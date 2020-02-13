#ifndef UNIVERSITY_MAIN_SESSION_H
#define UNIVERSITY_MAIN_SESSION_H

#include "Subject.h"
#include <vector>
#include <string>

template <typename T>
class Session {
private:
    int size_session;
    std::vector<Subject> subjects_list;
public:
    Session();
    int size_sessio();
};


#endif //UNIVERSITY_MAIN_SESSION_H
