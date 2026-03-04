#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

//----- Employee System -----//

class Employee {
    private:
        queue<int> tableSingle[10];
        queue<int> tableFamily[5];
        queue<int> queueSingle[5];
        queue<int> queueFamily[5];
        int front = -1, rear = -1;
        int tableSelected;
        int indexSelected;
        int actionSelected;
        int totalSingle;
        int totalFamily;
    public:
        void checkTable();
        void showTable();

        void checkTotal();

        int getQueueSingle(int index)
        { return queueSingle[index].front(); }
        int setQueueSingle(int index, int value)
        { queueSingle[index].push(value); }
        int getQueueFamily(int index)
        { return queueFamily[index].front(); }
        int setQueueFamily(int index, int value)
        { queueFamily[index].push(value); }

        
        void pushToSingle(std::size_t idx, int value) { queueSingle[idx].push(value); }
        int frontOfSingle(std::size_t idx) const { return queueSingle[idx].empty()? -1 : queueSingle[idx].front(); }
        std::size_t sizeOfSingle(std::size_t idx) const { return queueSingle[idx].size(); }
        void popFromSingle(std::size_t idx) { queueSingle[idx].pop(); }
        void pushToFamily(std::size_t idx, int value) { queueFamily[idx].push(value); }
        int frontOfFamily(std::size_t idx) const { return queueFamily[idx].empty()? -1 : queueFamily[idx].front(); }
        std::size_t sizeOfFamily(std::size_t idx) const { return queueFamily[idx].size(); }
        void popFromFamily(std::size_t idx) { queueFamily[idx].pop(); }

        /*void customerQueue();
        int getFront() { return front; }
        void setFront(int f) { front = f; }
        int getRear() { return rear; }
        void setRear(int r) { rear = r; }*/

        bool queueEmpty() { return front == -1; }
        bool queueFull() { return (rear+1)%5==front; }

        void showQueue();
        //void addQueue(int q);
        //void removeQueue();
        void employeeSystem();

        // Get and Set functions//
        // Get and Set functions : For check condition in select functions//
        /*int getTableSingle(int index)
        { return tableSingle[index]; }
        void setTableSingle(int index, int value)
        { tableSingle[index] = value; }
        int getTableFamily(int index)
        { return tableFamily[index]; }
        void setTableFamily(int index, int value)
        { tableFamily[index] = value; }*/

        int getActionSelected()
        { return actionSelected; }
        void setActionSelected(int a)
        { actionSelected = a; }
        
        int getTotalSingle()
        { return totalSingle; }
        void setTotalSingle(int b)
        { totalSingle += b; }
        int getTotalFamily()
        { return totalFamily; }
        void setTotalFamily(int c)
        { totalFamily += c; }
};

/*void Employee::customerQueue()
{
    if(rear == 4)
    {
        cout<<"Queue is Full!"<<endl;
    }
    else
    {
        rear++;
        queue[rear] = 1;
        cout<<"Customer added to the queue!"<<endl;
    }
}*/

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
        tableSingle->push(1);
    }
    if(actionSelected == 2)
    {
        tableSingle->pop();
    }
    if(actionSelected == 3)
    {
        employeeSystem();
    }
    if(actionSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
    }
}

/*void Employee::addQueue(int q)
{
    cout<<"1.  Add Single Table"<<endl;
    cout<<"2.  Add Family Table"<<endl;
    cout<<"Please select the table type to add customer: "<<endl;
    cin>>tableSelected;

    if(tableSelected == 1)
    {   
        cout<<"Adding Customer to Single Table: "<<endl;
        for(int i=0; i<10; i++)
        {
            if(tableSingle[i] == 0)
            {
                setTableSingle(i, 1);
                cout<<"Customer added to the queue "<<i+1<<"!"<<endl;
                showTable();
                break;
            }
        }
        if(queueFull())
        {
            cout<<"Single Table is Full! Cannot add more customers."<<endl;
            return;
        }
        if (front == -1)
        {
            front = 0;
            rear=(rear+1) % 10;
            tableSingle[rear] = q;
            cout<<"Customer added to the Single Table : "<<rear+1<<"!"<<endl;
        }
    }
    else if(tableSelected == 2)
    {
        cout<<"Adding Customer to Family Table: "<<endl;
        cin>>indexSelected;
        if(indexSelected >= 1 && indexSelected <= 5)
        {
            setTableFamily(indexSelected-1, 1);
        }
       cout<<"Adding Customer to Family Table: "<<endl;
       if(queueFull())
        {
            cout<<"Family Table is Full! Cannot add more customers."<<endl;
            return;
        }
        else if(front == -1)
        {
            front=0;
            rear=(rear+1)%5;
            tableFamily[rear] = q;
            cout<<"Customer added to the Family Table : "<<rear+1<<"!"<<endl;
        }
    }
    else if(tableSelected != 1 && tableSelected != 2)
    {
        cout<<"Invalid input. Please enter only 1/2."<<endl;
    }
}

void Employee::removeQueue()
{
    cout<<"1.  Remove Single Table"<<endl;
    cout<<"2.  Remove Family Table"<<endl;
    cout<<"Please select the table type to remove customer: "<<endl;
    cin>>tableSelected;

    if(tableSelected == 1)
    {   
        cout<<"Removing Customer from Single Table: "<<endl;
        cin>>indexSelected;
        if(indexSelected >= 1 && indexSelected <= 10)
        {
            setTableSingle(indexSelected-1, 0);
        }
    }
    else if(tableSelected == 2)
    {
        cout<<"Removing Customer from Family Table: "<<endl;
        cin>>indexSelected;
        if(indexSelected >= 1 && indexSelected <= 5)
        {
            setTableFamily(indexSelected-1, 0);
        }
    }
    else if(tableSelected != 1 && tableSelected != 2)
    {
        cout<<"Invalid input. Please enter only 1/2."<<endl;
    }
}*/

void Employee::showTable()
{
    cout<<"Showing Current Table Status: "<<endl;
    cout<<"Single Table Status: "<<endl;

    for(int i=0; i<10; i++)
    {
        //setTotalSingle(tableSingle[i]);
        cout<<"Table "<<i+1<<": "<<tableSingle[i].front()<<endl;
    }

    /*if(rear >= front)
    {
        for(int i=front; i<=rear; i++)
        {
            //setTotalSingle(tableSingle[i]);
            cout<<"Table "<<i+1<<": "<<tableSingle[i]<<endl;
            cout<<"Table "<<i;
        }
    }
    else
    {
        for(int j=front; j<5; j++)
        {
            //setTotalSingle(tableSingle[j]);
            cout<<"Table "<<j+1<<": "<<tableSingle[j]<<endl;
        }
        for(int k=0; k<=rear; k++)
        {
            //setTotalSingle(tableSingle[k]);
            cout<<"Table "<<k+1<<": "<<tableSingle[k]<<endl;
        }
    }*/
    
    cout<<"Family Table Status: "<<endl;
    for(int j=0; j<5; j++)
    {
        //setTotalFamily(tableFamily[j]);
        cout<<"Table "<<j+1<<": "<<tableFamily[j].front()<<endl;
    }
}

void Employee::showQueue()
{
    cout<<"Showing Current Queue: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"Q"<<i+1<<" : "<<queueSingle[i].front()<<endl;
    }
    for(int i=0; i<5; i++)
    {
        cout<<"Q"<<i+1<<" : "<<queueFamily[i].front()<<endl;
    }
}

void Employee::checkTotal()
{
    cout<<"Checking Total Customers: "<<endl;
    cout<<"Total Customers in Single Table Queue: "<<totalSingle<<endl;
    cout<<"Total Customers in Family Table Queue: "<<totalFamily<<endl;
}

void Employee::employeeSystem()
{
    cout<<"Employee System Activated!"<<endl;
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
    if(actionSelected == 2)
    {
        checkTable();
    }
    if(actionSelected == 3)
    {
        checkTotal();
    }
    if(actionSelected == 4)
    {
        cout<<"-----Back to Main Menu-----"<<endl;
    }
    if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
    }
}







//----- Customer System -----//

class Customer {
    private:
        int selectedSet;
        int selectedType;
        string set;
        string typeT;
    public:
        void selectSet();
        void selectTypeTable(Employee, Employee);
        void showCustomerQ(Employee, Employee);
        void customerSystem(Employee, Employee);

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
void Customer::selectTypeTable(Employee queueNumS, Employee queueNumF)
{
    cout<<"Types of table:"<<endl;
    cout<<"1. Single Table"<<endl;
    cout<<"2. Family Table"<<endl;
    cout<<"Please Select Type of Table: ";
    cin>>selectedType;

    if(getSelectedType() == 1)
    {
        for(int i=0; i<queueNumS.sizeOfSingle(10); i++)
        {
            if(queueNumS.getQueueSingle(i) == 0)
            {
                queueNumS.pushToSingle(i, 1);
                setType("Single Table");
                queueNumS.setTotalSingle(1);
                break;
            }
        }
    }
    if(getSelectedType() == 2)
    {
        setType("Family Table");
        queueNumF.pushToFamily(0, 1);
    }
    if(getSelectedType() != 1 && getSelectedType() != 2)
    {
        cout<<"Invalid input. Please enter only 1/2"<<endl;
    }
}

void Customer::showCustomerQ(Employee queueNumS, Employee queueNumF)
{
    cout<<"\n----- Customer Information -----\n"<<endl;
    cout<<"Selected Shabu Set: " <<getSet()<<endl;
    cout<<"Selected Table Type: " <<getType()<<endl;
    if(getType() == "Single Table")
    {
        cout<<"Your queue number is: "<<queueNumS.getQueueSingle(0)<<endl;
    }
    else if(getType() == "Family Table")
    {
        cout<<"Your queue number is: "<<queueNumF.getQueueFamily(0)<<endl;
    }
}

//----- Customer : Method for call all methods -----//
void Customer::customerSystem(Employee queueNumS, Employee queueNumF)
{
    selectSet();
    selectTypeTable(queueNumS, queueNumF);
    showCustomerQ(queueNumS, queueNumF);
}





//----- Main System -----//

//----- selection class -----//
class selectionSystem {
    private:
        int inputNumSelected;
        int actionSelected;
        std::vector<std::queue<int>> queueNumS{10};  // default 10 single‑table queues
        std::vector<std::queue<int>> queueNumF{5};   // default  5 family‑table queuess
    public:
        void selectRole(Employee &ePath, Customer &cPath);
        selectionSystem(size_t s = 10, size_t f = 5)  : queueNumS(s), queueNumF(f) {}
};

void selectionSystem::selectRole(Employee &ePath, Customer &cPath)
{
    cout<<"-----Select Your Role Path------\n"<<endl;
        
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
            cout<<"\n-----Selected Employee Path------\n"<<endl;
        }
        if(inputNumSelected == 2)
        {
            cout<<"\n-----Selected Customer Path------\n"<<endl;
            cPath.customerSystem(ePath, ePath);
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

/*void selectionSystem::backToMenu(int x)
{

}*/

int main()
{
    selectionSystem start;
    Employee employeePath;
    Customer customerPath;
    cout<<"Welcome to the Restaurant Queue System!"<<endl;
    start.selectRole(employeePath, customerPath);
}