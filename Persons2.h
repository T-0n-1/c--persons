//
// Created by Toni Mertanen on 25.2.2022.
//
#pragma once
// vector is one of the STL (standard template library) container classes. It holds values in indexed manner
#include <vector>
#include "Person.h"

class Persons2 {
private:
    vector<Person*> persons;

public:
    Persons2();

    Person* add(Person* p);
    Person* remove(const string& name);
    void print();
    ~Persons2();
};
