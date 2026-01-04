#include "Task.h"

Task::Task(){}

Task::~Task(){}

Task::Task(int id, string title, string description, Priority priority, Status status, string dueDate){
    this->id = id;
    this->title = title;
    this->description = description;
    this->priority = priority;
    this->status = status;
    this->dueDate = dueDate;
}

void Task::setTitle(string title){this->title = title;}

void Task::setStatus(Status status){this->status = status;}

void Task::setPriority(Priority priority){this->priority = priority;}

void Task::setDescription(string description){this->description = description;}

void Task::setDueDate(string dueDate){this->dueDate = dueDate;}

Priority Task::getPriority() const {return priority;}

Status Task::getStatus() const {return status;}

int Task::getId() const {return id;}

string Task::getTitle() const {return title;}

string Task::getDescription() const {return description;}

string Task::getDueDate() const {return dueDate;}