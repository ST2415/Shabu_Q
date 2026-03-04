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

        bool queueEmpty() { return front == -1; }
        bool queueFull() { return (rear+1)%5==front; }

        void enQueue(int q);
        void deQueue();

        void showQueue();
        void employeeSystem();

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
    if(actionSelected == 2)
    {
        deQueue();
    }
    if(actionSelected == 3)
    {
        employeeSystem();
    }
    if(actionSelected == 4)
    {
        cout<<"Back to Main Menu!"<<endl;
    }
    if(actionSelected != 1 && actionSelected != 2 && actionSelected != 3 && actionSelected != 4)
    {
        cout<<"Invalid input. Please enter only 1/2/3/4."<<endl;
    }
}

void Employee::enQueue(int q)
{
    cout<<"1. Add Queue to Single Table"<<endl;
    cout<<"2. Add Queue to Family Table"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;
    
    if(actionSelected == 1)
    {
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(queueSingle[i].size() < 5)
            {
                queueSingle[i].push(q);
                cout<<"Customer added to Single Table Queue "<<i+1<<"!"<<endl;
                break;
            }
        }
    }
}

void Employee::deQueue()
{
    cout<<"1. Remove Queue from Single Table"<<endl;
    cout<<"2. Remove Queue from Family Table"<<endl;
    cout<<"Select the number to perform the action: ";
    cin>>actionSelected;

    if(actionSelected == 1)
    {
        for(int i=0; i<getmaxNumA(); i++)
        {
            if(!queueSingle[i].empty())
            {
                queueSingle[i].pop();
                cout<<"Customer removed from Single Table Queue "<<i+1<<"!"<<endl;
                break;
            }
        }
    }
}

void Employee::showTable()
{
    cout<<"Showing Current Table Status: "<<endl;
    cout<<"Single Table Status: "<<endl;

    for(int i=0; i<getmaxNumA(); i++)
    {
        //setTotalSingle(tableSingle[i]);
        cout<<"Table "<<i+1<<": "<<tableSingle[i].front()<<endl;
    }
    
    cout<<"Family Table Status: "<<endl;
    for(int j=0; j<getmaxNumB(); j++)
    {
        //setTotalFamily(tableFamily[j]);
        cout<<"Table "<<j+1<<": "<<tableFamily[j].front()<<endl;
    }
}

void Employee::showQueue()
{
    cout<<"Showing Current Queue: "<<endl;
    cout<<"Single Table Queue: "<<endl;
    for(int i=0; i<getmaxNumA(); i++)
    {
        cout<<"Q"<<i+1<<" : "<<queueSingle[i].front()<<endl;
    }
    cout<<"Family Table Queue: "<<endl;
    for(int i=0; i<getmaxNumB(); i++)
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
        cout<<"Back to Main Menu!"<<endl;
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
        for(int i=0; i<queueNumS.getmaxNumA(); i++)
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
    cout<<"Selected Table Number: " <<getSelectedType()<<endl;
    
    if(getSelectedType() == 1)
    {
        for(int i=0; i<queueNumS.getmaxNumA(); i++)
        {
            cout<<queueNumS.getmaxNumA();
            cout<<"Queue "<<i+1<<" in Single Table: "<<queueNumS.getQueueSingleBack(i)<<endl;
        }
    }
    else if(getSelectedType() == 2)
    {
        for(int j=0; j<queueNumF.getmaxNumB(); j++)
        {
            cout<<"Queue "<<j+1<<" in Family Table: "<<queueNumF.getQueueFamilyBack(j)<<endl;
        }
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
        std::vector<std::queue<int>> queueNumS[10];  // default 10 single‑table queues
        std::vector<std::queue<int>> queueNumF[5];   // default  5 family‑table queuess
    public:
        void selectRole(Employee &ePath, Customer &cPath);
        //selectionSystem(size_t s = 10, size_t f = 5)  : queueNumS(s), queueNumF(f) {}
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

int main()
{
    selectionSystem start;
    Employee employeePath;
    Customer customerPath;
    cout<<"Welcome to the Restaurant Queue System!"<<endl;
    start.selectRole(employeePath, customerPath);
}