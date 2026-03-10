#include "CUSTOMER_H_INCLUDED.h"
#include <iostream>
using namespace std;

void Customer::selectSet()
{
    cout<<"Sets of Shabu :"<<endl;
    cout<<"1. Normal Shabu Set"<<endl;
    cout<<"2. Premium Shabu Set"<<endl;
    cout<<"3. Seafood Shabu Set"<<endl;
    cout<<"Please Select Shabu Set: ";
    cin>>selectedSet;

    if(getSelectedSet()==1)
    {
        setSet("Normal Shabu Set");
    }
    else if(getSelectedSet()==2)
    {
        setSet("Premium Shabu Set");
    }
    else if(getSelectedSet()==3)
    {
        setSet("Seafood Shabu Set");
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2/3"<<endl;
    }
}

//----- Customer : Type of Table  -----//
void Customer::selectTypeTable(Employee &callEsystem)
{
    cout<<"Types of table:"<<endl;
    cout<<"1. Single Table"<<endl;
    cout<<"2. Family Table"<<endl;
    cout<<"Please Select Type of Table: ";
    cin>>selectedType;

    if(getSelectedType()==1)
    {
        customerQNumS=callEsystem.generateNextQSingle(); 
        callEsystem.setQueueSingle(customerQNumS);
        setType("Single Table");
    }
    else if(getSelectedType()==2)
    {
        customerQNumF=callEsystem.generateNextQFamily();
        callEsystem.setQueueFamily(customerQNumF);
        setType("Family Table");
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2"<<endl;
        selectTypeTable(callEsystem);
    }
}

void Customer::showCustomerQ()
{
    cout<<"\n----- Customer Information -----\n"<<endl;
    cout<<"Selected Shabu Set: "<<getSet()<<endl;
    cout<<"Selected Table Type: "<<getType()<<endl;
    
    if(getSelectedType()==1)
    {
        cout<<"Your queue in Single Table: "<<customerQNumS<<endl;
    }
    else if(getSelectedType()==2)
    {
        cout<<"Your queue in Family Table: "<<customerQNumF<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2"<<endl;
        showCustomerQ();
    }

    cout<<"1. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected==1)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1."<<endl;
        showCustomerQ();
    }
}

//----- Customer : Method for call all methods -----//
void Customer::customerSystem(Employee &callEsystem)
{
    selectSet();
    selectTypeTable(callEsystem);
    showCustomerQ();
}