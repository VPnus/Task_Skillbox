#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Employee;

class Manager{

public:
    string name;

    Manager(string name): name(name){}
    void getTasks(int instructions);

    vector<Employee*> workers;
};

class Employee {

public:
    string name;
    Manager* manager;
    Employee(string name, Manager* manager): name(name), manager(manager){}
    void getTask(){
        cout<<name<<" got task"<<endl;
    }
};


void Manager::getTasks(int instructions){

    srand(instructions + name.length());


    int tasksCount = rand() % (workers.size() + 1);


    vector<string> tasksTypes = {"A", "B", "C"};


    for(int i = 0; i<tasksCount; i++){
        int taskType = rand() % tasksTypes.size();
        string task = tasksTypes[taskType];


        if(i<workers.size()){
            cout<<name<<" assigned task "<<task<<" to "<<workers[i]->name<<endl;
            workers[i]->getTask();
        }


        else
            cout<<name<<" has no available workers for task "<<task<<endl;
    }
}


int main(){
    int commands;
    cout<<"Enter the number of commands: ";
    cin>>commands;

    vector<Manager*> managers;
    vector<Employee*> employees;


    for(int i=0; i<commands; i++){
        string name;
        int employeesCount;

        cout<<"Enter the name of command "<<i+1<<": ";
        cin>>name;
        cout<<"Enter the number of employees for command "<<i+1<<": ";
        cin>>employeesCount;


        Manager* manager = new Manager(name);
        managers.push_back(manager);


        for(int j=0; j<employeesCount; j++){
            string employeeName = name + to_string(j);
            Employee* employee = new Employee(employeeName, manager);
            employees.push_back(employee);
            manager->workers.push_back(employee);
        }
    }

    int instructions;
    cout<<"Enter the instructions: ";
    while(cin>>instructions){

        for(auto manager: managers)
            manager->getTasks(instructions);
    }

    for(auto manager: managers)
        delete manager;

    for(auto employee: employees)
        delete employee;

    return 0;
}