#include <iostream>
#include "TaskManager.h"

using namespace std;

int main(){
    TaskManager manager;
    manager.load();
    int option = 0, priority = 0, status = 0, id = 0, changeOption = 0;
    string buffer, title, description, dueDate;
    Priority typePriority;
    Status typeStatus;

    while (option != 5){
        cout << "MENU:" << endl;
        cout << "1 - List all tasks" << endl;
        cout << "2 - Add new task" << endl;
        cout << "3 - Update task" << endl;
        cout << "4 - Remove task" << endl;
        cout << "5 - Exit" << endl;

        cout << "\nOption: ";

        getline(cin, buffer);
        option = stoi(buffer);

        system("clear");

        switch (option){
            case 1:
                manager.listAllTasks();
                break;
            case 2:
                cout << "\nTitle: ";
                getline(cin, title);
                cout << "Description: ";
                getline(cin, description);
                cout << "Priority (1) LOW | (2) MEDIUM | (3) HIGH: ";
                getline(cin, buffer);
                priority = stoi(buffer);
                cout << "Status (1) PENDING | (2) IN PROGRESS | (3) DONE: ";
                getline(cin, buffer);
                status = stoi(buffer);
                cout << "Due date (DD/MM/AAAA): ";
                getline(cin, dueDate);

                if (priority == 1) typePriority = Priority::LOW;
                else if (priority == 2) typePriority = Priority::MEDIUM;
                else if (priority == 3) typePriority = Priority::HIGH;

                if (status == 1) typeStatus = Status::PENDING;
                else if (status == 2) typeStatus = Status::IN_PROGRESS;
                else if (status == 3) typeStatus = Status::DONE;

                manager.addTask(manager.getNextId(), title, description, typePriority, typeStatus, dueDate);
                cout << "Task created successfully! \n" << endl;
                break;
            case 3:
                manager.listAllTasks();
                cout << "ID from the task to be change: ";
                getline(cin, buffer);
                id = stoi(buffer);

                cout << "(1) Title | (2) Description | (3) Priority | (4) Status | (5) Due date : ";
                getline(cin, buffer);
                changeOption = stoi(buffer);

                cout << "New data: ";
                getline(cin, buffer);

                switch (changeOption){
                    case 1:
                        manager.updateTitle(id, buffer);
                        break;
                    case 2:
                        manager.updateDescription(id, buffer);
                        break;
                    case 3:
                        manager.updatePriority(id, buffer);
                        break;
                    case 4:
                        manager.updateStatus(id, buffer);
                        break;
                    case 5:
                        manager.updateDueDate(id, buffer);
                        break;
                    default:
                        cout << "Invalid option." << endl;
                }
                cout << "\nUpdated successfully! \n" << endl;
                break;
            case 4:
                manager.listAllTasks();
                cout << "ID from the task to be removed: ";
                getline(cin, buffer);
                id = stoi(buffer);
                manager.removeTask(id);
                break;
            case 5:
                manager.save();
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Invalid option.";
        }
    }
    
    return 0;
}