#include "Task.h"

void Lab_work::set_name_work(std::string name) {
    name_work = name;
    type_work = "Лабораторная";
}

std::string Lab_work::get_name_work() const {
    return name_work;
}

Mark* Lab_work::get_mark() {
    return mark;
}

void Lab_work::set_mark(Mark* new_mark) {
    mark = new_mark;
}


void Rgz::set_name_work(std::string name) {
    name_work = name;
    type_work = "РГЗ";
}

std::string Rgz::get_name_work() const {
    return name_work;
}

Mark* Rgz::get_mark() {
    return mark;
}

void Rgz::set_mark(Mark* new_mark) {
    mark = new_mark;
}


void Coursework::set_name_work(std::string name) {
    name_work = name;
    type_work = "Курсовая работа";
}

std::string Coursework::get_name_work() const {
    return name_work;
}

Mark* Coursework::get_mark() {
    return mark;
}

void Coursework::set_mark(Mark* new_mark) {
    mark = new_mark;
}


void Test::set_name_work(std::string name) {
    name_work = name;
    type_work = "Тест";
}

std::string Test::get_name_work() const {
    return name_work;
}

Mark* Test::get_mark() {
    return mark;
}

void Test::set_mark(Mark* new_mark) {
    mark = new_mark;
}


void Exam::set_name_work(std::string name) {
    name_work = name;
    type_work = "Экзамен";
}

std::string Exam::get_name_work() const {
    return name_work;
}

Mark* Exam::get_mark() {
    return mark;
}

void Exam::set_mark(Mark* new_mark) {
    mark = new_mark;
}
