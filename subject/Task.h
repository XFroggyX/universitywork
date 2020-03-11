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
    virtual std::string get_type_task() const  = 0;
    virtual Mark& get_mark() = 0;
};

class Lab_work:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    explicit Lab_work(const Mark&);
    void set_name_work(std::string) override;
    std::string get_name_work() const override;
    void set_mark() override;
    std::string get_type_task() const override;
    void change_mark() override;
    Mark& get_mark() override;

};

class Rgz:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    explicit Rgz(const Mark&);
    void set_name_work(std::string) override;
    std::string get_name_work() const override;
    void set_mark() override;
    std::string get_type_task() const override;
    void change_mark() override;
    Mark& get_mark() override ;
};

class Coursework:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    explicit Coursework(const Mark&);
    void set_name_work(std::string) override;
    std::string get_name_work() const override;
    void set_mark() override;
    void change_mark() override;
    std::string get_type_task() const override ;
    Mark& get_mark() override;
};

class Test:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    explicit Test(const Mark&);
    void set_name_work(std::string) override;
    std::string get_name_work() const override;
    void set_mark() override;
    void change_mark() override;
    std::string get_type_task() const override ;
    Mark& get_mark() override;
};

class Exam:public Task {
private:
    std::string name_work;
    std::string type_work;
    std::vector<Mark> mark;
public:
    explicit Exam(const Mark&);
    void set_name_work(std::string) override;
    std::string get_name_work() const override;
    void set_mark() override;
    void change_mark() override;
    std::string get_type_task() const override ;
    Mark& get_mark() override;
};

#endif //UNIVERSITY_MAIN_TASK_H
