#ifndef UNIVERSITY_MAIN_TASKS_CEREATOR_H
#define UNIVERSITY_MAIN_TASKS_CEREATOR_H

#include "Mark.h"
#include "Task.h"

class Tasks_cereator {
public:
    virtual Task* create_subject()  = 0 ;
    virtual ~Tasks_cereator();
};

class Concrete_Lab_work : public Tasks_cereator {
public:
    Task* create_subject();
};

class Concrete_Rgz : public Tasks_cereator {
public:
    Task* create_subject();
};

class Concrete_Coursework : public Tasks_cereator {
public:
    Task* create_subject();
};

class Concrete_Test : public Tasks_cereator {
public:
    Task* create_subject();
};

class Concrete_Exam : public Tasks_cereator {
public:
    Task* create_subject();
};



#endif //UNIVERSITY_MAIN_TASKS_CEREATOR_H
