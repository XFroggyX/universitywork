#include "Tasks_cereator.h"

Tasks_cereator::~Tasks_cereator() = default;

Task *Concrete_Lab_work::create_subject() {
    return new Lab_work;
}

Task *Concrete_Rgz::create_subject() {
    return new Rgz;
}

Task *Concrete_Coursework::create_subject() {
    return new Coursework;
}

Task *Concrete_Test::create_subject() {
    return new Test;
}

Task *Concrete_Exam::create_subject() {
    return new Exam;
}
