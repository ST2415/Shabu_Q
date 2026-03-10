#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#include "EMPLOYEE_H_INCLUDED.h"
#include <iostream>
#include <string>
using namespace std;

class Customer {
    private:
        int selectedSet=0;
        int selectedType=0;
        string set;
        string typeT;
        int actionSelected=0;
        
        int customerQNumS;
        int customerQNumF;
    public:
        Customer() { cout<<"\n-----Selected Customer Path------\n"<<endl; }
        ~Customer() { }

        void selectSet();
        void selectTypeTable(Employee &callEsystem);
        void showCustomerQ();
        void customerSystem(Employee &callEsystem);

        // Get and Set functions//
        // Get and Set functions : For check condition in select functions//
        int getSelectedSet() { return selectedSet; }
        void setSelectedSet(int a) { selectedSet = a; }
        int getSelectedType() { return selectedType; }
        void setSelectedType(int b) { selectedType = b; }

        // Get and Set functions : For show the selected string output//
        string getSet() { return set; }
        void setSet(string c) { set = c; }
        string getType() { return typeT; }
        void setType(string d) { typeT = d; }
};

#endif