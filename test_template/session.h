#pragma once

#include <sstream>
#include "mark.h"
#include "Group.h"

using namespace std;

class Session {
private:
    string date_start;
    string date_end;
    vector<Plan> sub;
public:
    void set_date_start(int, int, int);
    void set_date_end(int, int, int);
    void set_mark();
    void get_mark();
    void print_mark();
};