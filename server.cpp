#define _WIN32_WINNT 0x0A00

#include <iostream>
#include <queue>
#include <string>

//#define CPPHTTPLIB_SINGLE_THREAD
#include "yhirose-cpp-httplib-68fa9bc/httplib.h"

using namespace std;
using namespace httplib;

// --- ข้อมูลคิวและโต๊ะ (เหมือนในคลาส Employee ของเรา) ---
queue<int> queueSingle;
queue<int> queueFamily;
int tableSingle[10] = {0};
int tableFamily[5] = {0};
int nextTicketSingle = 1;
int nextTicketFamily = 1;

// ฟังก์ชันสำหรับตั้งค่า CORS (อนุญาตให้หน้าเว็บ HTML คุยกับ C++ ข้ามไฟล์ได้)
void set_cors(Response &res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type");
}

int main() {
    Server svr;

    // 1. ดักจับ OPTIONS (Preflight Request ของเบราว์เซอร์)
    svr.Options(R"(.*)", [](const Request& req, Response& res) {
        set_cors(res);
    });

    // ==============================================================
    // API 1: ส่งข้อมูลสถานะร้านทั้งหมดกลับไปให้หน้าเว็บ (GET /api/get-queue)
    // ==============================================================
    svr.Get("/api/get-queue", [](const Request& req, Response& res) {
        set_cors(res);
        
        // สร้างข้อความรูปแบบ JSON แบบ Manual เพื่อส่งให้ Javascript
        string json = "{";
        json += "\"waitSingle\": " + to_string(queueSingle.size()) + ",";
        json += "\"nextSingle\": " + (queueSingle.empty() ? "\"-\"" : "\"" + to_string(queueSingle.front()) + "\"") + ",";
        json += "\"waitFamily\": " + to_string(queueFamily.size()) + ",";
        json += "\"nextFamily\": " + (queueFamily.empty() ? "\"-\"" : "\"" + to_string(queueFamily.front()) + "\"") + ",";
        
        // สร้าง Array ของโต๊ะ
        json += "\"tableSingle\": [";
        for(int i=0; i<10; i++) { json += to_string(tableSingle[i]) + (i<9 ? "," : ""); }
        json += "], \"tableFamily\": [";
        for(int i=0; i<5; i++) { json += to_string(tableFamily[i]) + (i<4 ? "," : ""); }
        json += "]}";

        res.set_content(json, "application/json");
    });

    // ==============================================================
    // API 2: ลูกค้ากดรับคิว (POST /api/add-queue)
    // ==============================================================
    svr.Post("/api/add-queue", [](const Request& req, Response& res) {
        set_cors(res);
        
        // ค้นหาว่าลูกค้าส่งคำว่า "Single" หรือ "Family" มา
        bool isSingle = (req.body.find("Single") != string::npos);
        int myQ = 0, waiting = 0;
        
        if (isSingle) {
            myQ = nextTicketSingle++;
            queueSingle.push(myQ);
            waiting = queueSingle.size() - 1;
        } else {
            myQ = nextTicketFamily++;
            queueFamily.push(myQ);
            waiting = queueFamily.size() - 1;
        }
        
        string json = "{\"myQ\": " + to_string(myQ) + ", \"waiting\": " + to_string(waiting) + "}";
        res.set_content(json, "application/json");
        cout << ">> [Customer] Added to " << (isSingle ? "Single" : "Family") << " Queue. (Q: " << myQ << ")" << endl;
    });

    // ==============================================================
    // API 3: พนักงานเรียกคิวเข้าโต๊ะ (POST /api/call-queue)
    // ==============================================================
    svr.Post("/api/call-queue", [](const Request& req, Response& res) {
        set_cors(res);
        bool isSingle = (req.body.find("Single") != string::npos);
        string msg = "";
        
        if (isSingle && !queueSingle.empty()) {
            bool isFull = true;
            for (int i = 0; i < 10; i++) {
                if (tableSingle[i] == 0) {
                    tableSingle[i] = queueSingle.front();
                    queueSingle.pop();
                    msg = "Assigned to Single Table " + to_string(i+1);
                    cout << ">> [Employee] " << msg << endl;
                    isFull = false; break;
                }
            }
            if (isFull) { msg = "Table is full!"; cout << ">> " << msg << endl; }
        } else if (!isSingle && !queueFamily.empty()) {
            bool isFull = true;
            for (int i = 0; i < 5; i++) {
                if (tableFamily[i] == 0) {
                    tableFamily[i] = queueFamily.front();
                    queueFamily.pop();
                    msg = "Assigned to Family Table " + to_string(i+1);
                    cout << ">> [Employee] " << msg << endl;
                    isFull = false; break;
                }
            }
            if (isFull) { msg = "Table is full!"; cout << ">> " << msg << endl; }
        } else {
            msg = "No customer in queue!";
        }
        
        res.set_content("{\"message\": \"" + msg + "\"}", "application/json");
    });

    // ==============================================================
    // API 4: พนักงานกดเช็คบิลออกจากโต๊ะ (POST /api/checkout)
    // ==============================================================
    svr.Post("/api/checkout", [](const Request& req, Response& res) {
        set_cors(res);
        bool isSingle = (req.body.find("Single") != string::npos);
        string msg = "";
        
        int index = -1;
        size_t pos = req.body.find("\"tableIndex\":");
        if (pos != string::npos) {
            size_t start = pos + 13; 
            size_t end = req.body.find_first_of(",}", start);
            index = stoi(req.body.substr(start, end - start));
        }
        
        if (index >= 0) {
            if (isSingle && index < 10) {
                if (tableSingle[index] == 0) {
                    msg = "Table is already empty!";
                } else {
                    msg = "Checkout Single Table " + to_string(index+1);
                    tableSingle[index] = 0;
                }
                cout << ">> [Employee] " << msg << endl;
            } else if (!isSingle && index < 5) {
                if (tableFamily[index] == 0) {
                    msg = "Table is already empty!";
                } else {
                    msg = "Checkout Family Table " + to_string(index+1);
                    tableFamily[index] = 0;
                }
                cout << ">> [Employee] " << msg << endl;
            }
        }
        
        res.set_content("{\"message\": \"" + msg + "\"}", "application/json");
    });

    cout << "=========================================" << endl;
    cout << "  Shabu Queue Backend is running..." << endl;
    cout << "  Listening on http://localhost:8080" << endl;
    cout << "=========================================" << endl;
    
    svr.listen("localhost", 8080); // เปิดเซิร์ฟเวอร์ที่พอร์ต 8080
    
    return 0;
}