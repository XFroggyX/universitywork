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
    explicit Session(Plan);

    void print_arrears();
    Plan &get_plan_session();

    void print_inf();
};


#endif //UNIVERSITY_MAIN_SESSION_H
