#include "Tasks_cereator.h"

Tasks_cereator::~Tasks_cereator() = default;

Task *Concrete_Lab_work::create_subject() {
    Mark n(1);
    return new Lab_work(n);
}

Task *Concrete_Rgz::create_subject() {
    Mark n(1);
    return new Rgz(n);
}

Task *Concrete_Coursework::create_subject() {
    Mark n(1);
    return new Coursework(n);
}

Task *Concrete_Test::create_subject() {
    Mark n(1);
    return new Test(n);
}

Task *Concrete_Exam::create_subject() {
    Mark n(1);
    return new Exam(n);
}
