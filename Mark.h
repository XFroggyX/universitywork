#ifndef UNIVERSITY_MAIN_MARK_H
#define UNIVERSITY_MAIN_MARK_H

#include <string>

template <typename T>
class Mark {
private:
    T mark;
public:
    Mark(T);
    ~Mark();

    void set_mark(T);
    T get_mark();
    void print_mark();
};


#endif //UNIVERSITY_MAIN_MARK_H
