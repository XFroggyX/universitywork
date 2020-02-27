#include <iostream>
#include <algorithm>
#include <vector>

#include "subject/Tasks_cereator.h"

using namespace std;

int main() {
    Concrete_Lab_work *lab = new Concrete_Lab_work;
    Concrete_Rgz *wq = new Concrete_Rgz;

    vector<Task*> list;
    list.push_back(lab->create_subject());
    list.push_back(wq->create_subject());

    Mark *a = new Int_mark(3);
    Int b; //Тут ошибка
    list[0]->set_mark(*a);
    b = list[0]->get_mark();
    list[0]->set_name_work("dfsfdsf");
    cout << list[0]->get_name_work();
    m.print_mark();
}