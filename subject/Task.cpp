#include "Task.h"

void Lab_work::set_name_work(std::string name) {
    name_work = name;
    type_work = "Лабораторная";
}

std::string Lab_work::get_name_work() const {
    return name_work;
}

Mark& Lab_work::get_mark()  {
    return mark[0];
}

void Lab_work::set_mark() {
    mark[0].change_mark();
}

void Lab_work::change_mark() {
    mark[0].change_mark();
}

Lab_work::Lab_work(const Mark& new_mark) {
    mark.push_back(new_mark);
}

std::string Lab_work::get_type_task() const {
    return type_work;
}


void Rgz::set_name_work(std::string name) {
    name_work = name;
    type_work = "РГЗ";
}

std::string Rgz::get_name_work() const {
    return name_work;
}

Mark& Rgz::get_mark() {
    return mark[0];
}

void Rgz::set_mark() {
    mark[0].change_mark();
}

void Rgz::change_mark() {
    mark[0].change_mark();
}

Rgz::Rgz(const Mark& new_mark) {
    mark.push_back(new_mark);
}

std::string Rgz::get_type_task() const {
    return type_work;
}

void Coursework::set_name_work(std::string name) {
    name_work = name;
    type_work = "Курсовая работа";
}

std::string Coursework::get_name_work() const {
    return name_work;
}

Mark& Coursework::get_mark() {
    return mark[0];
}

void Coursework::set_mark() {
    mark[0].change_mark();
}

void Coursework::change_mark() {
    mark[0].change_mark();
}

Coursework::Coursework(const Mark& new_mark) {
    mark.push_back(new_mark);
}

std::string Coursework::get_type_task() const {
    return type_work;
}


void Test::set_name_work(std::string name) {
    name_work = name;
    type_work = "Тест";
}

std::string Test::get_name_work() const {
    return name_work;
}

Mark& Test::get_mark() {
    return mark[0];
}

void Test::set_mark() {
    mark[0].change_mark();
}

void Test::change_mark() {
    mark[0].change_mark();
}

Test::Test(const Mark& new_mark) {
    mark.push_back(new_mark);
}

std::string Test::get_type_task() const {
    return type_work;
}


void Exam::set_name_work(std::string name) {
    name_work = name;
    type_work = "Экзамен";
}

std::string Exam::get_name_work() const {
    return name_work;
}

Mark& Exam::get_mark() {
    return mark[0];
}

void Exam::set_mark() {
    mark[0].change_mark();
}

void Exam::change_mark() {
    mark[0].change_mark();
}

Exam::Exam(const Mark& new_mark) {
    mark.push_back(new_mark);
}

std::string Exam::get_type_task() const {
    return type_work;
}
