#include "EMPLOYEE_H_INCLUDED.h"
#include <iostream>
using namespace std;

void Employee::checkTable()
{
    showTable();
    cout<<"1. Add Customer to Table"<<endl;
    cout<<"2. Remove Customer from Table"<<endl;
    cout<<"3. Back to Employee Menu"<<endl;
    cout<<"4. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;
    if(actionSelected==1)
    {
        enQueue();
    }
    else if(actionSelected==2)
    {
        deQueue();
    }
    else if(actionSelected==3)
    {
        employeeSystem();
    }
    else if(actionSelected==4)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        checkTable();
    }
}

void Employee::enQueue()
{
    cout<<"1. Add Queue to Single Table"<<endl;
    cout<<"2. Add Queue to Family Table"<<endl;
    cout<<"3. Back to Employee Menu"<<endl;
    cout<<"4. Back to Check Table Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>tableSelected;
    
    if(tableSelected == 1)
    {
        if(queueSingle.empty()) 
        {
            cout << "No customers waiting in the Single Table queue!" << endl;
        }
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(!queueSingle.empty())
            { 
                if(tableSingle[i]==0)
                {
                    tableSingle[i]=getQueueSingle();
                    popFromSingle();
                    cout<<"Customer single table queue "<<tableSingle[i]<<" added to Single Table number "<<i+1<<"!"<<endl;
                    setTotalSingle(1);
                    break;
                }
                else if(i==getmaxNumA()-1 && tableSingle[i]!=0)
                {
                    cout<<"The Single Table is full!"<<endl;
                    break;
                }
            }
        }
    }
    else if(tableSelected == 2)
    {
        if(queueFamily.empty()) 
        {
            cout << "No customers waiting in the Family Table queue!" << endl;
        }
        for(int j=0; j<getmaxNumB(); j++)
        {
            if(!queueFamily.empty())
            { 
                if(tableFamily[j]==0)
                {
                    tableFamily[j]=getQueueFamily();
                    popFromFamily();
                    cout<<"Customer family table queue "<<tableFamily[j]<<" added to Family Table number "<<j+1<<"!"<<endl;
                    setTotalFamily(1);
                    break;
                }
                else if(j==getmaxNumB()-1 && tableFamily[j]!=0)
                {
                    cout<<"The Family Table is full!"<<endl;
                    break;
                }
            }
        }
    }
    else if(tableSelected==3)
    {
        employeeSystem();
    }
    else if(tableSelected==4)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        enQueue();
    }
}

void Employee::deQueue()
{
    cout<<"1. Remove Queue from Single Table"<<endl;
    cout<<"2. Remove Queue from Family Table"<<endl;
    cout<<"3. Back to Employee Menu"<<endl;
    cout<<"4. Back to Check Table Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>tableSelected;

    if(tableSelected==1)
    {
        cout<<"Select the queue number to remove: ";
        cin>>indexSelected;

        if(tableSingle[indexSelected-1]==0)
        {
            cout<<"There's no customer to remove from Single Table Queue "<<indexSelected<<"!"<<endl;
            deQueue();
        }

        else if(indexSelected-1<getmaxNumA() && tableSingle[indexSelected-1]!=0)
        {
            tableSingle[indexSelected-1]=0;
            cout<<"Customer removed from Single Table Queue "<<indexSelected<<"!"<<endl;
        }
        
    }
    else if(tableSelected==2)
    {
        cout<<"Select the table number to remove: ";
        cin>>indexSelected;

        if(tableFamily[indexSelected-1]==0)
        {
            cout<<"There's no customer to remove from Family Table Number "<<indexSelected<<"!"<<endl;
            deQueue();
        }

        else if(indexSelected<=getmaxNumB() && tableFamily[indexSelected-1]!=0)
        {
            tableFamily[indexSelected-1]=0;
            cout<<"Customer removed from Family Table Number "<<indexSelected<<"!"<<endl;
        }
    }
    else if(tableSelected==3)
    {
        employeeSystem();
    }
    else if(tableSelected==4)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        deQueue();
    }
}

void Employee::showTable()
{
    cout<<"\nShowing Current Table Status: \n"<<endl;
    cout<<"Single Table Status: "<<endl;

    for(int i=0; i<getmaxNumA(); i++)
    {
        cout<<"Table "<<i+1<<": "<<tableSingle[i]<<endl;
    }
    cout<<"Family Table Status: "<<endl;
    for(int j=0; j<getmaxNumB(); j++)
    {
        cout<<"Table "<<j+1<<": "<<tableFamily[j]<<endl;
    }
}

void Employee::showQueue()
{
    cout<<"Showing Current Queue: "<<endl;
    cout<<"Single queue waiting: "<<sizeOfSingle()<<" customer(s)"<<endl;
    if(!queueSingle.empty()) 
    {
        cout<<"-> Next queue in Single table is: "<<getQueueSingle() << endl;
    }
    cout<<"Family queue waiting: "<<sizeOfFamily()<<" customer(s)"<<endl;
    if(!queueFamily.empty()) 
    {
        cout<<"-> Next queue in Family table is: "<<getQueueFamily()<<endl;
    }

    cout<<"1. Back to Employee Menu"<<endl;
    cout<<"2. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected==1)
    {
        employeeSystem();
    }
    else if(actionSelected==2)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2."<<endl;
        showQueue();
    }
}

void Employee::checkTotal()
{
    cout<<"Checking Total Customers: "<<endl;
    cout<<"Total Ccustomers in Single Table: "<<totalSingle<<endl;
    cout<<"Total customers in Family Table: "<<totalFamily<<endl;
    cout<<"Total all customers: "<<totalSingle + totalFamily<<endl;
    cout<<"----- Options -----"<<endl;
    cout<<"1. Back to Employee Menu"<<endl;
    cout<<"2. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;
    if(actionSelected==1)
    {
        employeeSystem();
    }
    else if(actionSelected==2)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2."<<endl;
        checkTotal();
    }
}

void Employee::employeeSystem()
{
    cout<<"1. Show Current Queue"<<endl;
    cout<<"2. Check Table Available"<<endl;
    cout<<"3. Check Total Customers"<<endl;
    cout<<"4. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected==1)
    {
        showQueue();
    }
    else if(actionSelected==2)
    {
        checkTable();
    }
    else if(actionSelected==3)
    {
        checkTotal();
    }
    else if(actionSelected==4)
    {
        cout<<"\n----- Back to Main Menu -----\n"<<endl;
    }
    else
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        employeeSystem();
    }
}
