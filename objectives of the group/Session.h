#ifndef UNIVERSITY_MAIN_SESSION_H
#define UNIVERSITY_MAIN_SESSION_H

#include "Plan.h"
#include <vector>
#include <string>

class Session {
private:
    unsigned items_session = 0;
    Plan session;
public:
    Session(Plan);
    unsigned items_sessio();
    void print_session();
    unsigned average_score();
};


#endif //UNIVERSITY_MAIN_SESSION_H
