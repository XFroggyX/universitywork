#pragma once

#include "subject_creator.h"
#include <vector>
#include <iostream>

class Plan {
private:
vector<Subject*> plan_sub;

public:
void add_subj_plan();
void del_subj_plan();
void print_paln();
};