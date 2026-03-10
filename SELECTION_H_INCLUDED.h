#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include "EMPLOYEE_H_INCLUDED.h"
#include "CUSTOMER_H_INCLUDED.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class SelectionPath 
{
    private:
        int inputNumSelected=0;
        int actionSelected=0;
    public:
        SelectionPath() { cout<<"-----Select Your Role Path------"<<endl; }
        ~SelectionPath() { cout<<"-----Exiting System Complete!-----"<<endl; }
        void selectRole(Employee &ePath, Customer &cPath);
};

#endif