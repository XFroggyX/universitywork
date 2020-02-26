#ifndef UNIVERSITY_MAIN_TASK_H
#define UNIVERSITY_MAIN_TASK_H

#include "Mark.h"

class Task {
public:
    virtual void set_name_work(std::string) = 0;
    virtual std::string get_name_work() const = 0;
};

class Lab_work:public Task {
private:
    std::string name_work;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
};

class Rgz:public Task {
private:
    std::string name_work;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
};

class Coursework:public Task {
private:
    std::string name_work;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
};

class Test:public Task {
private:
    std::string name_work;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
};

class Exam:public Task {
private:
    std::string name_work;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
};

#endif //UNIVERSITY_MAIN_TASK_H
