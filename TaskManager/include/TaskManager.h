#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>

class TaskManager {
    private:
        vector<Task> tasks;
        int nextId;

    public:
        TaskManager();
        ~TaskManager();
        void setNextId(int nextId);
        int getNextId();
        void addTask(int id, const string& title, const string& description, const Priority& priority, Status& status, const string& dueDate);
        void removeTask(int id);
        void updateTitle(int id, string newTitle);
        void updateStatus(int id, string newStatus);
        void updateDescription(int id, string newDescription);
        void updateDueDate(int id, string newDate);
        void updatePriority(int id, string newPriority);
        void listAllTasks() const;
        Task* findTaskById(int id);
        string statusToString(Status status) const;
        string priorityToString(Priority priority) const;
        void save() const;
        void load();
};

#endif