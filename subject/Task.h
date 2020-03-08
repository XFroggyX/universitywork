#ifndef UNIVERSITY_MAIN_TASK_H
#define UNIVERSITY_MAIN_TASK_H

#include "Mark.h"
#include <vector>

class Task {
public:
    virtual void set_name_work(std::string) = 0;
    virtual std::string get_name_work() const = 0;
    virtual void set_mark() = 0;
    virtual void change_mark() = 0;
    virtual std::string get_type_task() = 0;
    virtual Mark& get_mark() = 0;
};

class Lab_work:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    Lab_work(const Mark&);
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark();
    std::string get_type_task();
    void change_mark();
    Mark& get_mark();

};

class Rgz:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    Rgz(const Mark&);
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark();
    std::string get_type_task();
    void change_mark();
    Mark& get_mark();
};

class Coursework:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    Coursework(const Mark&);
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark();
    void change_mark();
    std::string get_type_task();
    Mark& get_mark();
};

class Test:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    Test(const Mark&);
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark();
    void change_mark();
    std::string get_type_task();
    Mark& get_mark();
};

class Exam:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    Exam(const Mark&);
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark();
    void change_mark();
    std::string get_type_task();
    Mark& get_mark();
};

#endif //UNIVERSITY_MAIN_TASK_H
