#include "SELECTION_H_INCLUDED.h"
#include <iostream>
using namespace std;

void SelectionPath::selectRole(Employee &ePath, Customer &cPath)
{

    //Get input for choosing role or exit the loop//
    while (inputNumSelected != 3)
    {
        cout<<"1. Employee"<<endl;
        cout<<"2. Customer"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the Number to Select Path: ";
        cin>>inputNumSelected;

        if(inputNumSelected == 1)
        {
            ePath.employeeSystem();
        }
        else if(inputNumSelected == 2)
        {
            cPath.customerSystem(ePath);
        }
        else if(inputNumSelected == 3)
        {
            break;
        }
        else
        {
            cout<<"Invalid input. Please enter only 1/2/3."<<endl;
        }
    }
}