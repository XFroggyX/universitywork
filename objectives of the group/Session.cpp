#include "Session.h"

#include <utility>

Session::Session(Plan plan) {
    session = std::move(plan);
}

Plan &Session::get_plan_session() {
    return session;
}

void Session::print_arrears() {
    for(int i = 0; i < session.get_size_plan(); i++) {
        if(!session.get_subject(i).subj_delivered()) {
            std::cout << "По предмету " << session.get_subject(i).get_name_subject() << " у вас есть следующие долги:"
                << std::endl;
            session.get_subject(i).print_task_delivered();
        } else {
            std::cout << "Задолжность по предметам отсутствует." << std::endl;
        }
    }
}

void Session::print_inf() {
    for(int i = 0; i < session.get_size_plan(); i++) {
        std::cout << "Передмет " << session.get_subject(i).get_name_subject() << ". Оенка за предмет: ";
        std:: cout << session.get_subject(i).get_mark() << std::endl << "Cписок всех работ по предмету: " << std::endl;
        session.get_subject(i).print_task_list();

    }
}
