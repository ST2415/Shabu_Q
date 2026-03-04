#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

//----- Employee System -----//

class Employee {
    private:
        static const int maxNumA = 10;
        static const int maxNumB = 5;
        queue<int> tableSingle[maxNumA];
        queue<int> tableFamily[maxNumB];
        queue<int> queueSingle[maxNumA];
        queue<int> queueFamily[maxNumB];

        //int queueSingle[maxNumA]
        int front = -1, rear = -1;

        int tableSelected;
        int indexSelected;
        int actionSelected;

        int total;
        int totalSingle;
        int totalFamily;
    public:

        void checkTable();
        void showTable();

        void resetQueue();

        void checkTotal();

        int getmaxNumA() const { return maxNumA; }
        //int setmaxNumA(int a) { return maxNumA; }
        int getmaxNumB() const { return maxNumB; }
        //int setmaxNumB(int b) { return maxNumB; }

        int getQueueSingle(int index)
        { return queueSingle[index].front(); }
        void setQueueSingle(int index, int value)
        { queueSingle[index].push(value); }
        int getQueueFamily(int index)
        { return queueFamily[index].front(); }
        void setQueueFamily(int index, int value)
        { queueFamily[index].push(value); }

        int getQueueSingleBack(int index)
        { return queueSingle[index].empty() ? -1 : queueSingle[index].back(); }
        int getQueueFamilyBack(int index)
        { return queueFamily[index].empty() ? -1 : queueFamily[index].back(); }

        
        void pushToSingle(std::size_t idx, int value) { queueSingle[idx].push(value); }
        int frontOfSingle(std::size_t idx) const { return queueSingle[idx].empty()? -1 : queueSingle[idx].front(); }
        std::size_t sizeOfSingle(std::size_t idx) const { return queueSingle[idx].size(); }
        void popFromSingle(std::size_t idx) { queueSingle[idx].pop(); }

        void pushToFamily(std::size_t idx, int value) { queueFamily[idx].push(value); }
        int frontOfFamily(std::size_t idx) const { return queueFamily[idx].empty()? -1 : queueFamily[idx].front(); }
        std::size_t sizeOfFamily(std::size_t idx) const { return queueFamily[idx].size(); }
        void popFromFamily(std::size_t idx) { queueFamily[idx].pop(); }

        void pushToSingleTable(int idx, int value) { tableSingle[idx].push(value); }
        int frontOfSingleTable(int idx) const { return tableSingle[idx].empty()? -1 : tableSingle[idx].front(); }
        std::size_t sizeOfSingleTable(int idx) const { return tableSingle[idx].size(); }
        void popFromSingleTable(int idx) { tableSingle[idx].pop(); }

        void pushToFamilyTable(int idx, int value) { tableFamily[idx].push(value); }
        int frontOfFamilyTable(int idx) const { return tableFamily[idx].empty()? -1 : tableFamily[idx].front(); }
        std::size_t sizeOfFamilyTable(int idx) const { return tableFamily[idx].size(); }
        void popFromFamilyTable(int idx) { tableFamily[idx].pop(); }

        //bool queueEmpty() { return front == -1; }
        //bool queueFull() { return (rear+1)%5==front; }

        void enQueue(int q);
        void deQueue();

        void showQueue();
        void employeeSystem();

        int getActionSelected()
        { return actionSelected; }
        void setActionSelected(int a)
        { actionSelected = a; }
        
        int getTotal()
        { return total; }
        void setTotal(int a)
        { total += a; }
        int getTotalSingle()
        { return totalSingle; }
        void setTotalSingle(int b)
        { totalSingle += b; }
        int getTotalFamily()
        { return totalFamily; }
        void setTotalFamily(int c)
        { totalFamily += c; }
};

void Employee::resetQueue()
{
    cout<<"1. Reset Single queues."<<endl;
    cout<<"2. Reset Family queues."<<endl;
    cout<<"3. Reset All queues."<<endl;
    cout<<"4. Back to Employee Menu."<<endl;
    cout<<"5. Back to Main Menu."<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected == 1)
    {
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(!queueSingle[i].empty() && queueSingle[i].front() != 2)
            {
                cout<<"You cannot reset single queue! All single queues must have a value of 2 to be reset."<<endl;
                break;
            }
            if(!queueSingle[i].empty() && queueSingle[i].front() == 2)          // front element is 2
            {
                queueSingle[i].pop();      // assign a fresh empty queue
                //queueSingle[i].push(0);                 // …then push the initial value
            }
        }
    }
    else if(actionSelected == 2)
    {
        for(int j=0; j<getmaxNumB(); j++)
        {
            if(!queueFamily[j].empty() && queueFamily[j].front() != 2)
            {
                cout<<"You cannot reset family queue! All family queues must have a value of 2 to be reset."<<endl;
                break;
            }
            if(!queueFamily[j].empty() && queueFamily[j].front() == 2)
            {   
                queueFamily[j].pop();
                //queueFamily[j] = std::queue<int>();      // assign a fresh empty queue
                //queueFamily[j].push(0);                 // …then push the initial value
            }
        }
    }
    else if(actionSelected == 3)
    {
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(!queueSingle[i].empty() && queueSingle[i].front() != 2)
            {
                cout<<"You cannot reset all queue! All queues must have a value of 2 to be reset."<<endl;
                break;
            }
            if(!queueSingle[i].empty() && queueSingle[i].front() == 2)          // front element is 2
            {
                queueSingle[i].pop();      // assign a fresh empty queue
                //queueSingle[i].push(0);                 // …then push the initial value
            }
        }
        for(int j=0; j<getmaxNumB(); j++)
        {
            if(!queueFamily[j].empty() && queueFamily[j].front() != 2)
            {
                cout<<"You cannot reset all queue! All queues must have a value of 2 to be reset."<<endl;
                break;
            }
            if(!queueFamily[j].empty() && queueFamily[j].front() == 2)
            {   
                queueFamily[j].pop();
                //queueFamily[j] = std::queue<int>();      // assign a fresh empty queue
                //queueFamily[j].push(0);                 // …then push the initial value
            }
        }
    }
    else if(actionSelected == 4)
    {
        employeeSystem();
    }
    else if(actionSelected == 5)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4 && actionSelected != 5)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4/5."<<endl;
        resetQueue();
    }


    /*for(int i=0; i<getmaxNumA(); i++)
    {
        if(!queueSingle[i].empty() && queueSingle[i].front() != 2)
        {
            cout<<"You cannot reset all queue! All queues must have a value of 2 to be reset."<<endl;
            break;
        }
        else if(!queueSingle[i].empty() && queueSingle[i].front() == 2)          // front element is 2
        {
            queueSingle[i].pop();      // assign a fresh empty queue
            //queueSingle[i].push(0);                 // …then push the initial value
        }
    }
    
    for(int i=0; i<getmaxNumA(); i++)
    {
        if(!queueSingle[i].empty() && queueSingle[i].front() == 2)          // front element is 2
        {
            queueSingle[i].pop();      // assign a fresh empty queue
            //queueSingle[i].push(0);                 // …then push the initial value
        }
    }
    for(int j=0; j<getmaxNumB(); j++)
    {
        if(!queueFamily[j].empty() && queueFamily[j].front() == 2)
        {   
            queueFamily[j].pop();
            //queueFamily[j] = std::queue<int>();      // assign a fresh empty queue
            //queueFamily[j].push(0);                 // …then push the initial value
        }
    }*/
}

void Employee::checkTable()
{
    cout<<"Checking Table Available: "<<endl;
    showTable();
    cout<<"1. Add Customer to Table"<<endl;
    cout<<"2. Remove Customer from Table"<<endl;
    cout<<"3. Back to Employee Menu"<<endl;
    cout<<"4. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;
    if(actionSelected == 1)
    {
        enQueue(1);
    }
    else if(actionSelected == 2)
    {
        deQueue();
    }
    else if(actionSelected == 3)
    {
        employeeSystem();
    }
    else if(actionSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        checkTable();
    }
}

void Employee::enQueue(int q)
{
    cout<<"1. Add Queue to Single Table"<<endl;
    cout<<"2. Add Queue to Family Table"<<endl;
    cout<<"3. Back to Employee Menu"<<endl;
    cout<<"4. Back to Check Table Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>tableSelected;
    
    if(tableSelected == 1)
    {
        
        
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(queueSingle[i].front() == 1)
            { 
                if(tableSingle[i].front() == 0)
                {
                    popFromSingle(i);
                    pushToSingle(i, 2);
                    pushToSingleTable(i, 1);
                    cout<<"Customer added to Single Table Queue "<<i+1<<"!"<<endl;
                    setTotal(1);
                    setTotalSingle(1);
                    break;
                }
                else if(i == getmaxNumA()-1 && tableSingle[i].front() == 1)
                {
                    cout<<"The Single Table is full!"<<endl;
                    break;
                }
            }
            else if(i == getmaxNumA()-1 && tableSingle[i].front() == 1)
            {
                cout<<"The Single Table is full!"<<endl;
                break;
            }
        }
    }
    else if(tableSelected == 2)
    {
        for(int j=0; j<getmaxNumB(); j++)
        {
            if(queueFamily[j].front() == 1)
            {
                if(tableFamily[j].front() == 0)
                {
                    popFromFamily(j);
                    pushToFamily(j, 2);
                    pushToFamilyTable(j, 1);
                    cout<<"Customer added to Family Table Queue "<<j+1<<"!"<<endl;
                    setTotal(1);
                    setTotalFamily(1);
                    break;
                }
                else if(j == getmaxNumB()-1 && tableFamily[j].front() == 1)
                {
                    cout<<"The Family Table is full!"<<endl;
                    break;
                }
            }
        }
    }
    else if(tableSelected == 3)
    {
        employeeSystem();
    }
    else if(tableSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if (tableSelected != 1 && tableSelected!= 2 && tableSelected != 3 && tableSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        enQueue(q);
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

    if(tableSelected == 1)
    {
        cout<<"Select the queue number to remove: ";
        cin>>indexSelected;

        if(tableSingle[indexSelected-1].front() == 0)
        {
            cout<<"There's no customer to remove from Single Table Queue "<<indexSelected<<"!"<<endl;
            deQueue();
        }

        else if(!queueSingle[indexSelected-1].empty() && indexSelected-1 < getmaxNumA() && tableSingle[indexSelected-1].front() != 0)
        {
            tableSingle[indexSelected-1].pop();
            cout<<"Customer removed from Single Table Queue "<<indexSelected<<"!"<<endl;
        }
        
    }
    else if(tableSelected == 2)
    {
        cout<<"Select the queue number to remove: ";
        cin>>indexSelected;

        if(tableFamily[indexSelected-1].front() == 0)
        {
            cout<<"There's no customer to remove from Family Table Queue "<<indexSelected<<"!"<<endl;
            deQueue();
        }

        if(!queueFamily[indexSelected-1].empty() && indexSelected <= getmaxNumB())
        {
            tableFamily[indexSelected-1].pop();
            cout<<"Customer removed from Family Table Queue "<<indexSelected<<"!"<<endl;
        }
    }
    else if(tableSelected == 3)
    {
        employeeSystem();
    }
    else if(tableSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if (tableSelected != 1 && tableSelected != 2 && tableSelected != 3 && tableSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        deQueue();
    }
}

void Employee::showTable()
{
    cout<<"Showing Current Table Status: "<<endl;
    cout<<"Single Table Status: "<<endl;

    for(int i=0; i<getmaxNumA(); i++)
    {
        cout<<"Table "<<i+1<<": "<<tableSingle[i].front()<<endl;
    }
    
    cout<<"Family Table Status: "<<endl;
    for(int j=0; j<getmaxNumB(); j++)
    {
        cout<<"Table "<<j+1<<": "<<tableFamily[j].front()<<endl;
    }
}

void Employee::showQueue()
{
    cout<<"Showing Current Queue: "<<endl;
    cout<<"Single Queue: "<<endl;
    for(int i=0; i<getmaxNumA(); i++)
    {
        cout<<"Q"<<i+1<<" : "<<queueSingle[i].front()<<endl;
    }
    cout<<"Family Queue: "<<endl;
    for(int i=0; i<getmaxNumB(); i++)
    {
        cout<<"Q"<<i+1<<" : "<<queueFamily[i].front()<<endl;
    }

    cout<<"1. Reset all Queues"<<endl;
    cout<<"2. Back to Employee Menu"<<endl;
    cout<<"3. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected == 1)
    {
        resetQueue();
        cout<<"-----All queues have been reset-----"<<endl;
        showQueue();
    }
    else if(actionSelected == 2)
    {
        employeeSystem();
    }
    else if(actionSelected == 3)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3)
    {
        cout<<"Invalid input. Please enter only 1/2/3."<<endl;
        showQueue();
    }
}

void Employee::checkTotal()
{
    cout<<"Checking Total Customers: "<<endl;
    cout<<"Total Customers in Single Table Queue: "<<totalSingle<<endl;
    cout<<"Total Customers in Family Table Queue: "<<totalFamily<<endl;
    cout<<"----- Options -----"<<endl;
    cout<<"1. Back to Employee Menu"<<endl;
    cout<<"2. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;
    if(actionSelected == 1)
    {
        employeeSystem();
    }
    else if(actionSelected == 2)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1 && actionSelected != 2)
    {
        cout<<"Invalid input. Please enter only 1/2."<<endl;
        checkTotal();
    }
}

void Employee::employeeSystem()
{
    cout<<"-----Employee System Activated!-----"<<endl;
    cout<<"1. Show Current Queue"<<endl;
    cout<<"2. Check Table Available"<<endl;
    cout<<"3. Check Total Customers"<<endl;
    cout<<"4. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected == 1)
    {
        showQueue();
    }
    else if(actionSelected == 2)
    {
        checkTable();
    }
    else if(actionSelected == 3)
    {
        checkTotal();
    }
    else if(actionSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
        employeeSystem();
    }
}




//----- Customer System -----//

class Customer {
    private:
        int selectedSet;
        int selectedType;
        string set;
        string typeT;
        int actionSelected;

        Employee maxA;
        Employee maxB;
        std::vector<std::queue<int>> qNumS;  // default 10 single‑table queues
        std::vector<std::queue<int>> qNumF;   // default  5 family‑table queuess
    public:
        void selectSet();
        void selectTypeTable(Employee &, Employee &, Employee &, Employee &);
        void showCustomerQ(Employee &, Employee &, Employee &, Employee &);
        void customerSystem(Employee &, Employee &, Employee &, Employee &);

        // Get and Set functions//
        // Get and Set functions : For check condition in select functions//
        int getSelectedSet()
        { return selectedSet; }
        void setSelectedSet(int a)
        { selectedSet = a; }
        int getSelectedType()
        { return selectedType; }
        void setSelectedType(int b)
        { selectedType = b; }

        // Get and Set functions : For show the selected string output//
        string getSet()
        { return set; }
        void setSet(string c)
        { set = c; }
        string getType()
        { return typeT; }
        void setType(string d)
        { typeT = d; }

        Customer() 
        {   
            selectedSet = 0;
            selectedType = 0;
            actionSelected = 0;

            qNumS.resize(maxA.getmaxNumA());
            qNumF.resize(maxB.getmaxNumB());
        }
};

//----- Customer : Type of Set  -----//
void Customer::selectSet()
{
    cout<<"Sets of Shabu :"<<endl;
    cout<<"1. Normal Shabu Set"<<endl;
    cout<<"2. Premium Shabu Set"<<endl;
    cout<<"3. Seafood Shabu Set"<<endl;
    cout<<"Please Select Shabu Set: ";
    cin>>selectedSet;

    if(getSelectedSet() == 1)
    {
        setSet("Normal Shabu Set");
    }
    else if(getSelectedSet() == 2)
    {
        setSet("Premium Shabu Set");
    }
    if(getSelectedSet() == 3)
    {
        setSet("Seafood Shabu Set");
    }
    if(getSelectedSet() != 1 && getSelectedSet() != 2 && getSelectedSet() != 3)
    {
        cout<<"Invalid input. Please enter only 1/2/3"<<endl;
    }
}

//----- Customer : Type of Table  -----//
void Customer::selectTypeTable(Employee &queueNumS, Employee &queueNumF, Employee &qNumS, Employee &qNumF)
{
    cout<<"Types of table:"<<endl;
    cout<<"1. Single Table"<<endl;
    cout<<"2. Family Table"<<endl;
    cout<<"Please Select Type of Table: ";
    cin>>selectedType;

    if(getSelectedType() == 1)
    {
        for(int i=0; i<queueNumS.getmaxNumA(); i++)
        {
            if(queueNumS.getQueueSingle(i) == 0)
            {
                queueNumS.pushToSingle(i, 1);
                setType("Single Table");
                //cout<<queueNumS.getQueueSingle(i);
                break;
            }
        }
    }
    else if(getSelectedType() == 2)
    {
        setType("Family Table");
        queueNumF.pushToFamily(0, 1);
    }
    else if(getSelectedType() != 1 && getSelectedType() != 2)
    {
        cout<<"Invalid input. Please enter only 1/2"<<endl;
        selectTypeTable(queueNumS, queueNumF, qNumS, qNumF);
    }
}

void Customer::showCustomerQ(Employee &queueNumS, Employee &queueNumF, Employee &qNumS, Employee &qNumF)
{
    cout<<"\n----- Customer Information -----\n"<<endl;
    cout<<"Selected Shabu Set: "<<getSet()<<endl;
    cout<<"Selected Table Type: "<<getType()<<endl;
    
    if(getSelectedType() == 1)
    {
        for(int i=0; i<queueNumS.getmaxNumA(); i++)
        {
            if(queueNumS.getQueueSingle(i) == 0)
            {
                cout<<"Your queue in Single Table: "<<i<<endl;
                break;
            }
        }
    }
    else if(getSelectedType() == 2)
    {
        for(int j=0; j<queueNumF.getmaxNumB(); j++)
        {
            cout<<"Your queue in Family Table: "<<queueNumF.getQueueFamily(j)<<endl;
        }
    }
    else if(getSelectedType() != 1 && getSelectedType() != 2)
    {
        cout<<"Invalid input. Please enter only 1/2"<<endl;
        showCustomerQ(queueNumS, queueNumF, qNumS, qNumF);
    }

    cout<<"1. Back to Main Menu"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected == 1)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    else if(actionSelected != 1)
    {
        cout<<"Invalid input. Please enter only 1."<<endl;
        showCustomerQ(queueNumS, queueNumF, qNumS, qNumF);
    }
}

//----- Customer : Method for call all methods -----//
void Customer::customerSystem(Employee &queueNumS, Employee &queueNumF, Employee &qNumS, Employee &qNumF)
{
    selectSet();
    selectTypeTable(queueNumS, queueNumF, qNumS, qNumF);
    showCustomerQ(queueNumS, queueNumF, qNumS, qNumF);
}





//----- Main System -----//

//----- selection class -----//
class selectionSystem {
    private:
        int inputNumSelected;
        int actionSelected;
        Employee maxA;
        Employee maxB;
        std::vector<std::queue<int>> queueNumS;  // default 10 single‑table queues
        std::vector<std::queue<int>> queueNumF;   // default  5 family‑table queuess
    public:
        selectionSystem()
        {
            inputNumSelected = 0;
            actionSelected = 0;
            
            queueNumS.resize(maxA.getmaxNumA());
            queueNumF.resize(maxB.getmaxNumB());
        }
        void selectRole(Employee &ePath, Customer &cPath, Employee &qNumS, Employee &qNumF);
        //void initializeQ(Employee, Employee);
        //selectionSystem(size_t s = 10, size_t f = 5)  : queueNumS(s), queueNumF(f) {}
};

/*void selectionSystem::initializeQ(Employee maxA, Employee maxB) {
    for(int i=0; i<maxA.getmaxNumA(); i++) 
    {
        maxA.setQueueSingle(i,0);
    }
    for(int j=0; j<maxB.getmaxNumB(); j++) 
    {
        maxB.setQueueFamily(j,0);
    }
}*/

void selectionSystem::selectRole(Employee &ePath, Customer &cPath, Employee &qNumS, Employee &qNumF)
{

    //Get input for choosing role or exit the loop//
    while (inputNumSelected != 3)
    {
        cout<<"-----Select Your Role Path------"<<endl;
        cout<<"1. Employee"<<endl;
        cout<<"2. Customer"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter the Number to Select Path: ";
        cin>>inputNumSelected;

        if(inputNumSelected == 1)
        {
            cout<<"\n-----Selected Employee Path------\n"<<endl;
            ePath.employeeSystem();
        }
        if(inputNumSelected == 2)
        {
            cout<<"\n-----Selected Customer Path------\n"<<endl;
            cPath.customerSystem(ePath, ePath, qNumS, qNumF);
        }
        if(inputNumSelected == 3)
        {
            cout<<"-----Exiting System Complete!-----"<<endl;
            break;
        }
        if(inputNumSelected != 1 && inputNumSelected != 2 && inputNumSelected != 3)
        {
            cout<<"Invalid input. Please enter only 1/2/3."<<endl;
        }
    }
}

int main()
{
    selectionSystem start;
    Employee employeePath;
    Employee qNumA;
    Employee qNumB;
    Customer customerPath;
    //selectionSystem emp;
    //emp.initializeQ(initA, initB);
    cout<<"Welcome to the Restaurant Queue System!"<<endl;
    start.selectRole(employeePath, customerPath, qNumA, qNumB);
}