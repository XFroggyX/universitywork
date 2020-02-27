#include "Task.h"

void Lab_work::set_name_work(std::string name) {
    name_work = name;
}

std::string Lab_work::get_name_work() const {
    return name_work;
}

void Lab_work::set_mark(const Mark& new_mark) {
    mark = new_mark;
}

Mark Lab_work::get_mark() {
    return mark;
}


void Rgz::set_name_work(std::string name) {
    name_work = name;
}

std::string Rgz::get_name_work() const {
    return name_work;
}

void Rgz::set_mark(const Mark& new_mark) {
    mark = new_mark;
}

Mark Rgz::get_mark() {
    return mark;
}



void Coursework::set_name_work(std::string name) {
    name_work = name;
}

std::string Coursework::get_name_work() const {
    return name_work;
}

void Coursework::set_mark(const Mark& new_mark) {
    mark = new_mark;
}

Mark Coursework::get_mark() {
    return mark;
}


void Test::set_name_work(std::string name) {
    name_work = name;
}

std::string Test::get_name_work() const {
    return name_work;
}

void Test::set_mark(const Mark& new_mark) {
    mark = new_mark;
}

Mark Test::get_mark() {
    return mark;
}


void Exam::set_name_work(std::string name) {
    name_work = name;
}

std::string Exam::get_name_work() const {
    return name_work;
}

void Exam::set_mark(const Mark& new_mark) {
    mark = new_mark;
}

Mark Exam::get_mark() {
    return mark;
}