#include "EMPLOYEE_H_INCLUDED.h"
#include "CUSTOMER_H_INCLUDED.h"
#include "SELECTION_H_INCLUDED.h"

#include "EmployeeSystem.cpp"
#include "CustomerSystem.cpp"
#include "SelectionSystem.cpp"

#include <iostream>
//#include "yhirose-cpp-httplib-68fa9bc/httplib.h"
using namespace std;

int main()
{
    SelectionPath start;
    Employee employeePath;
    Customer customerPath;
    cout<<"Welcome to the Restaurant Queue System!"<<endl;
    start.selectRole(employeePath, customerPath);
}