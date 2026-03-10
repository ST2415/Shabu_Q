#define _WIN32_WINNT 0x0A00

#include <iostream>
#include <queue>
#include <string>

#include "yhirose-cpp-httplib-68fa9bc/httplib.h"
#include "EMPLOYEE_H_INCLUDED.h"
#include "CUSTOMER_H_INCLUDED.h"

using namespace std;
using namespace httplib;

Employee shopEmployee;
Customer shopCustomer;

// ฟังก์ชันสำหรับตั้งค่า CORS
void set_cors(Response &res) {
    res.set_header("Access-Control-Allow-Origin", "*");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type");
}

int main() {
    Server svr;

    svr.Options(R"(.*)", [](const Request& req, Response& res) {
        set_cors(res);
    });

    // ==============================================================
    // API 1: ดึงสถานะคิวและโต๊ะจาก Object Employee
    // ==============================================================
    svr.Get("/api/get-queue", [](const Request& req, Response& res) {
        set_cors(res);
        
        string json = "{";
        json += "\"waitSingle\": " + to_string(shopEmployee.sizeOfSingle()) + ",";
        json += "\"nextSingle\": " + (shopEmployee.sizeOfSingle() == 0 ? "\"-\"" : "\"" + to_string(shopEmployee.getQueueSingle()) + "\"") + ",";
        json += "\"waitFamily\": " + to_string(shopEmployee.sizeOfFamily()) + ",";
        json += "\"nextFamily\": " + (shopEmployee.sizeOfFamily() == 0 ? "\"-\"" : "\"" + to_string(shopEmployee.getQueueFamily()) + "\"") + ",";
        
        // ดึงข้อมูลโต๊ะผ่าน Getter ที่เราเพิ่งสร้าง
        json += "\"tableSingle\": [";
        for(int i=0; i<10; i++) { json += to_string(shopEmployee.getTableSingle(i)) + (i<9 ? "," : ""); }
        json += "], \"tableFamily\": [";
        for(int i=0; i<5; i++) { json += to_string(shopEmployee.getTableFamily(i)) + (i<4 ? "," : ""); }
        json += "]}";

        res.set_content(json, "application/json");
    });

    // ==============================================================
    // API 2: รับคิวเข้า Object Employee
    // ==============================================================
    svr.Post("/api/add-queue", [](const Request& req, Response& res) {
        set_cors(res);
        bool isSingle = (req.body.find("Single") != string::npos);
        int myQ = 0, waiting = 0;
        
        if (isSingle) {
            myQ = shopEmployee.generateNextQSingle();
            shopEmployee.setQueueSingle(myQ);
            waiting = shopEmployee.sizeOfSingle() - 1;
        } else {
            myQ = shopEmployee.generateNextQFamily();
            shopEmployee.setQueueFamily(myQ);
            waiting = shopEmployee.sizeOfFamily() - 1;
        }
        
        string json = "{\"myQ\": " + to_string(myQ) + ", \"waiting\": " + to_string(waiting) + "}";
        res.set_content(json, "application/json");
        cout << ">> [Customer] Added to " << (isSingle ? "Single" : "Family") << " Queue. (Q: " << myQ << ")" << endl;
    });

    // ==============================================================
    // API 3: พนักงานดึงคิวลงโต๊ะผ่าน Object Employee
    // ==============================================================
    svr.Post("/api/call-queue", [](const Request& req, Response& res) {
        set_cors(res);
        bool isSingle = (req.body.find("Single") != string::npos);
        string msg = "";
        
        if (isSingle && shopEmployee.sizeOfSingle() > 0) {
            bool isFull = true;
            for (int i = 0; i < 10; i++) {
                if (shopEmployee.getTableSingle(i) == 0) {
                    shopEmployee.setTableSingle(i, shopEmployee.getQueueSingle());
                    shopEmployee.popFromSingle();
                    msg = "Assigned to Single Table " + to_string(i+1);
                    cout << ">> [Employee] " << msg << endl;
                    isFull = false; break;
                }
            }
            if (isFull) { msg = "Table is full!"; cout << ">> " << msg << endl; }
        } else if (!isSingle && shopEmployee.sizeOfFamily() > 0) {
            bool isFull = true;
            for (int i = 0; i < 5; i++) {
                if (shopEmployee.getTableFamily(i) == 0) {
                    shopEmployee.setTableFamily(i, shopEmployee.getQueueFamily());
                    shopEmployee.popFromFamily();
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
    // API 4: เคลียร์โต๊ะผ่าน Object Employee
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
                if (shopEmployee.getTableSingle(index) == 0) {
                    msg = "Table is already empty!";
                } else {
                    msg = "Checkout Single Table " + to_string(index+1);
                    shopEmployee.setTableSingle(index, 0);
                }
                cout << ">> [Employee] " << msg << endl;
            } else if (!isSingle && index < 5) {
                if (shopEmployee.getTableFamily(index) == 0) {
                    msg = "Table is already empty!";
                } else {
                    msg = "Checkout Family Table " + to_string(index+1);
                    shopEmployee.setTableFamily(index, 0);
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
    
    svr.listen("localhost", 8080);
    return 0;
}