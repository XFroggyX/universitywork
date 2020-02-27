#ifndef UNIVERSITY_MAIN_TASK_H
#define UNIVERSITY_MAIN_TASK_H

#include "Mark.h"

class Task {
public:
    virtual void set_name_work(std::string) = 0;
    virtual std::string get_name_work() const = 0;
    virtual void set_mark(const Mark&) = 0;
    virtual Mark get_mark() = 0;


};

class Lab_work:public Task {
private:
    std::string name_work;
    Mark mark;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark(const Mark&);
    Mark get_mark();

};

class Rgz:public Task {
private:
    std::string name_work;
    Mark mark;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark(const Mark&);
    Mark get_mark();
};

class Coursework:public Task {
private:
    std::string name_work;
    Mark mark;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark(const Mark&);
    Mark get_mark();
};

class Test:public Task {
private:
    std::string name_work;
    Mark mark;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark(const Mark&);
    Mark get_mark();
};

class Exam:public Task {
private:
    std::string name_work;
    Mark mark;
public:
    void set_name_work(std::string);
    std::string get_name_work() const;
    void set_mark(const Mark&);
    Mark get_mark();
};

#endif //UNIVERSITY_MAIN_TASK_H
