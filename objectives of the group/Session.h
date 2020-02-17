#ifndef UNIVERSITY_MAIN_SESSION_H
#define UNIVERSITY_MAIN_SESSION_H

#include "../subject/Subject.h"
#include <vector>
#include <string>

class Session {
private:
    unsigned items_session = 0;
    std::vector<Subject> subjects;
public:
    Session();
    unsigned items_sessio();
    void print_session();
    unsigned average_score();
};


#endif //UNIVERSITY_MAIN_SESSION_H
