#include "subject_creator.h"

Creator::~Creator() {
}

Creator* Creator::set(string name) {
    Subject *subject = this->create_subject();
    subject->set_name_work(name);
}

string Creator::get() const {
    Subject *subject = this->create_subject();
    string name = subject->get_name_work();
    return name;
}

Subject *Concrete_Lab_work::create_subject() const  {
    return new Lab_work;
}

Subject *Concrete_Rgz::create_subject() const  {
    return new Rgz;
}

Subject *Concrete_Coursework::create_subject() const {
    return new Coursework;
}

Subject *Concrete_Test::create_subject()  const {
    return new Test;
}

Subject *Concrete_Exam::create_subject() const {
    return new Exam;
}
