#pragma once

#include <string>
#include "subject.h"

using namespace std;

class Creator {
private:
public:
    virtual ~Creator();
    virtual Subject* create_subject() const = 0 ;
    Creator * set(string);
    string get() const;
};

class Concrete_Lab_work : public Creator {
public:
    Subject* create_subject() const;
};

class Concrete_Rgz : public Creator {
public:
    Subject* create_subject() const;
};

class Concrete_Coursework : public Creator {
public:
    Subject* create_subject() const;
};

class Concrete_Test : public Creator {
        public:
    Subject* create_subject() const;
};

class Concrete_Exam : public Creator {
public:
    Subject* create_subject() const;
};
