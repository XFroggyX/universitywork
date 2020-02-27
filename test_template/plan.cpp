#include "plan.h"

void Plan::add_subj_plan() {
    int type = 0;
    string name = "works";

    switch(type) {
        case 0: {
            Concrete_Lab_work* Lab_work = new Concrete_Lab_work();
            plan_sub.push_back(Lab_work->create_subject());
            plan_sub[0]->set_name_work(name);
            cout << plan_sub[0]->get_name_work();
            plan_sub.push_back(Lab_work->create_subject());
            plan_sub[0]->set_name_work("name");
            cout << plan_sub[0]->get_name_work();
            break;
        }
        case 1: {
            Creator* Rgz = new Concrete_Rgz();
            Rgz->set(name);
            plan_sub.push_back(Rgz->create_subject());
            break;
        }
        case 2: {
            Creator* Coursework = new Concrete_Coursework();
            plan_sub.push_back(Coursework->create_subject());
            Coursework->set(name);
            break;
        }
        case 3: {
            Creator* Test = new Concrete_Test();
            plan_sub.push_back(Test->create_subject());
            Test->set(name);
            break;
        }
        case 4: {
            Creator* Exam = new Concrete_Exam();
            plan_sub.push_back(Exam->create_subject());
            Exam->set(name);
            break;
        }
        default: {
            cout << "Ошибка" << endl;
            break;
        }
    }
}

void Plan::print_paln() {
    cout << "Предметы в плане:" << endl;
    for(int i = 0; i < plan_sub.size(); i++) {
        cout << "#" << i << plan_sub[i] << endl;
    }
}

void Plan::del_subj_plan() {
    print_paln();
    cout << "Какой предмет желаете удалить из плана. ";
    cout << "Введите индекс элемента: " << endl;
    int index;
    cin >> index;
    plan_sub.erase(plan_sub.begin() + index);
}
