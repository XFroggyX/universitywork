#include <iostream>
#include <algorithm>
#include <vector>

#include "subject/Tasks_cereator.h"

using namespace std;

int main() {
    Concrete_Lab_work *lab = new Concrete_Lab_work;

    Task *a = lab->create_subject();

    Mark *m = new Int_mark(4);
    a->set_mark(m);
    Mark *q = a->get_mark();
    auto s = dynamic_cast<Int_mark*>(q);
    s->print_mark();
    s->print_mark();
    
}