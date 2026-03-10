#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <queue>
using namespace std;

class Employee {
    private:
        int tableSingle[10]={0};
        int tableFamily[5]={0};
        queue<int> queueSingle;
        queue<int> queueFamily;

        int tableSelected;
        int indexSelected;
        int actionSelected;

        int totalSingle=0;
        int totalFamily=0;

        int waitingQueueS=1;
        int waitingQueueF=1;
    public:
        Employee() { cout<<"\n-----Selected Employee Path------\n"<<endl;}
        ~Employee() { }

        void checkTable();
        void showTable();
        void checkTotal();

        int getmaxNumA() { return sizeof(tableSingle)/sizeof(tableSingle[0]); }
        int getmaxNumB() { return sizeof(tableFamily)/sizeof(tableFamily[0]); }

        // --- เพิ่มฟังก์ชันเพื่อให้ Web Server ดึงข้อมูลโต๊ะได้ ---
        int getTableSingle(int index) { return tableSingle[index]; }
        void setTableSingle(int index, int value) { tableSingle[index] = value; }
        int getTableFamily(int index) { return tableFamily[index]; }
        void setTableFamily(int index, int value) { tableFamily[index] = value; }

        int generateNextQSingle() { return waitingQueueS++; }
        int generateNextQFamily() { return waitingQueueF++; }

        int getQueueSingle() { return queueSingle.front(); }
        void setQueueSingle(int value) { queueSingle.push(value); }
        size_t sizeOfSingle() { return queueSingle.size(); }
        void popFromSingle(){ queueSingle.pop(); }

        int getQueueFamily() { return queueFamily.front(); }
        void setQueueFamily(int value) { queueFamily.push(value); }
        size_t sizeOfFamily() { return queueFamily.size(); }
        void popFromFamily() { queueFamily.pop(); }

        void enQueue();
        void deQueue();
        void showQueue();
        void employeeSystem();

        int getActionSelected() { return actionSelected; }
        void setActionSelected(int a) { actionSelected = a; }

        int getTotalSingle() { return totalSingle; }
        void setTotalSingle(int b) { totalSingle += b; }
        int getTotalFamily() { return totalFamily; }
        void setTotalFamily(int c) { totalFamily += c; }
};

#endif