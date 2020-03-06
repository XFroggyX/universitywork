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
    Mark(int);
    Mark(bool);
    void change_mark();
    int return_mark();
    std::string return_type();
    ~Mark();
};

#endif //UNIVERSITY_MAIN_MARK_H
