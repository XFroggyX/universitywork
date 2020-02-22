#ifndef UNIVERSITY_MAIN_MARK_H
#define UNIVERSITY_MAIN_MARK_H

#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <functional>

class Mark {
private:
    int mark;
public:
    virtual void change_mark(int);
    virtual void print_mark();
    virtual int return_mark();
    virtual ~Mark();
};

class Int_mark : public Mark {
private:
    int mark;
public:
    Int_mark();
    Int_mark(int);
    ~Int_mark();

    void change_mark(int = 0);
    void print_mark() const;
    int return_mark() const;
};

class Bool_mark : public Mark {
private:
    int mark;
public:
    Bool_mark();
    Bool_mark(bool);
    ~Bool_mark();

    void change_mark(bool);
    void print_mark() const;
    int return_mark() const;
};

#endif //UNIVERSITY_MAIN_MARK_H
