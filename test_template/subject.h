#pragma once
#include <string>

using namespace std;

class Subject {
public:
    virtual void set_name_work(string) = 0;
    virtual string get_name_work() const = 0;
};

class Lab_work:public Subject {
private:
    string name_work;
public:
    void set_name_work(string);
    string get_name_work() const;
};

class Rgz:public Subject {
private:
    string name_work;
public:
    void set_name_work(string);
    string get_name_work() const;
};

class Coursework:public Subject {
private:
    string name_work;
public:
    void set_name_work(string);
    string get_name_work() const;
};

class Test:public Subject {
private:
    string name_work;
public:
    void set_name_work(string);
    string get_name_work() const;
};

class Exam:public Subject {
private:
    string name_work;
public:
    void set_name_work(string);
    string get_name_work() const;
};