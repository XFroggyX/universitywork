#ifndef UNIVERSITY_MAIN_MARK_H
#define UNIVERSITY_MAIN_MARK_H

#include <string>
#include <iostream>
#include <limits>
#include <algorithm>
#include <functional>

class Mark {
private:
    std::string mark;
    std::string type;
public:
    Mark();
    explicit Mark(int);
    explicit Mark(bool);

    void change_type_int();
    void change_mark();
    int return_mark();
    std::string return_type();
    void set_mark(int);
    ~Mark();
};

#endif //UNIVERSITY_MAIN_MARK_H
