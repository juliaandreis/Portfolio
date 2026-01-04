#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

enum class Priority{
    LOW,
    MEDIUM,
    HIGH
};

enum class Status{
    PENDING,
    IN_PROGRESS,
    DONE
};

class Task {
    private:
        Priority priority;
        Status status;
        int id;
        string title;
        string description;
        string dueDate;

    public:
        Task();
        ~Task();
        Task(int id, string title, string description, Priority priority, Status status, string dueDate);
        void setTitle(string title);
        void setStatus(Status status);
        void setPriority(Priority priority);
        void setDescription(string descrioption);
        void setDueDate(string dueDate);
        Priority getPriority() const;
        Status getStatus() const;
        int getId() const;
        string getTitle() const;
        string getDescription() const;
        string getDueDate() const;
};

#endif