#include "TaskManager.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <sstream>

const string FILE_PATH = "data/tasks.txt";

TaskManager::TaskManager(){nextId = 1;}

TaskManager::~TaskManager(){}

void TaskManager::setNextId(int nextId){this->nextId = nextId;}

int TaskManager::getNextId() {return nextId;}

void TaskManager::addTask(int id, const string& title, const string& description, const Priority& priority, Status& status, const string& dueDate){
    Task newTask(id, title, description, priority, status, dueDate);
    tasks.push_back(newTask);
    nextId++;
}

void TaskManager::removeTask(int id){
    for(auto it = tasks.begin(); it != tasks.end(); it++){
        if(it->getId() == id){
            tasks.erase(it);
            cout << "Task removed successfully." << endl;
            return;
        }
    }
    cout << "Task not found." << endl;
}

void TaskManager::updateTitle(int id, string newTitle){
    Task* actualTask = findTaskById(id);
    if (actualTask != nullptr) actualTask->setTitle(newTitle);
}

void TaskManager::updateStatus(int id, string newStatus){
    Task* actualTask = findTaskById(id);
    if (actualTask != nullptr){
        for (char &c : newStatus) c = toupper(c);
        if (newStatus == "PENDING") actualTask->setStatus(Status::PENDING);
        else if(newStatus == "IN PROGRESS")actualTask->setStatus(Status::IN_PROGRESS);
        else if(newStatus == "DONE")actualTask->setStatus(Status::DONE);
    }
}

void TaskManager::updateDescription(int id, string newDescription){
    Task* actualTask = findTaskById(id);
    if (actualTask != nullptr) actualTask->setDescription(newDescription);
}

void TaskManager::updateDueDate(int id, string newDate){
    Task* actualTask = findTaskById(id);
    if (actualTask != nullptr) actualTask->setDueDate(newDate);
}

void TaskManager::updatePriority(int id, string newPriority){
    Task* actualTask = findTaskById(id);
    if (actualTask != nullptr){
        for (char &c : newPriority) c = toupper(c);
        if (newPriority == "LOW") actualTask->setPriority(Priority::LOW);
        else if(newPriority == "MEDIUM")actualTask->setPriority(Priority::MEDIUM);
        else if(newPriority == "HIGH")actualTask->setPriority(Priority::HIGH);
    }
}

void TaskManager::listAllTasks() const{
    if (tasks.empty()) {
        cout << "No tasks avaliable." << endl;
        return;
    }
    cout << endl;
    cout << left
         << setw(4)  << "ID"
         << setw(30) << "Title"
         << setw(55) << "Description"
         << setw(10) << "Priority"
         << setw(14) << "Status"
         << setw(10) << "DueDate"
         << endl;

    cout << left
         << setw(4)  << "--"
         << setw(30) << "----------------------------"
         << setw(55) << "-----------------------------------------------------"
         << setw(10) << "--------"
         << setw(14) << "------------"
         << setw(10) << "----------"
         << '\n';

    for(const Task& task : tasks){
        cout << left
        << setw(4)  << task.getId()
        << setw(30) << task.getTitle()
        << setw(55) << task.getDescription()
        << setw(10) << priorityToString(task.getPriority())
        << setw(14) << statusToString(task.getStatus())
        << setw(10) << task.getDueDate()
        << endl;
    }
    cout << "\n\n";
}

Task* TaskManager::findTaskById(int id){
    for(Task& task : tasks){
        if(task.getId() == id) return &task;
    }
    return nullptr;
}

string TaskManager::statusToString(Status status) const{
    switch(status){
        case Status::PENDING:
            return "Pending";
        case Status::IN_PROGRESS:
            return "In Progress";
        case Status::DONE:
            return "Done";
        default:
            return "Unknown";
    }
}

string TaskManager::priorityToString(Priority priority) const{
    switch(priority){
        case Priority::LOW:
            return "*";
        case Priority::MEDIUM:
            return "* *";
        case Priority::HIGH:
            return "* * *";
        default:
            return "Unknown";
    }
}

void TaskManager::save() const{
    ofstream file(FILE_PATH);
    if (!file.is_open()){
        cout << "Error opening file." << endl;
        return;
    }

    string priority, status;

    for (const Task& task : tasks){
        status = statusToString(task.getStatus());
        priority = priorityToString(task.getPriority());

        file << task.getId() << "|"
             << task.getTitle() << "|"
             << task.getDescription() << "|"
             << priority << "|"
             << status << "|"
             << task.getDueDate() << "\n"; 
    }

    file.close();
    cout << "Saved successfully." << endl;
}

void TaskManager::load(){
    ifstream file(FILE_PATH);
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    tasks.clear();
    int maxId = 0;
    string line;

    while (getline(file, line)){
        stringstream ss(line);
        string segment;
        vector<string> data;

        while (getline(ss, segment, '|')) {
            data.push_back(segment);
        }

        if (data.size() == 6){
            if (stoi(data[0]) > maxId) maxId = stoi(data[0]);

            Priority priority;
            if (data[3] == "*") priority = Priority::LOW;
            else if (data[3] == "* *") priority = Priority::MEDIUM;
            else if (data[3] == "* * *") priority = Priority::HIGH;

            Status status = Status::PENDING;
            if (data[4] == "Pending") status = Status::PENDING;
            else if (data[4] == "In Progress") status = Status::IN_PROGRESS;
            else if (data[4] == "Done") status = Status::DONE;

            tasks.push_back(Task(stoi(data[0]), data[1], data[2], priority, status, data[5]));
        }
    }
    setNextId(maxId + 1);
    file.close();
    cout << "Loaded successfully.\n" << endl;
}