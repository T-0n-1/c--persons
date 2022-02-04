//
// Created by Toni Mertanen on 24.2.2022.
//

#pragma once
#include "Person.h"
class Persons {
private:
    // 1) static array containing Person objects. NOTE: no Employee objects
    // Person persons[10];
    // 2) dynamic array but all cells Person objects --> no Employee objects
    // Person* persons;
    // 3) dynamic array & cells are pointers to Person --> they can point to Person or Employee objects
    Person* *persons;
    size_t size;
    // example: array with five cells - some of cells are empty(0 aka null pointer) and some pointing to P and E objects
    // [ ] [ ] [0] [ ] [0]
    //  |   |       |
    //  E   P       E
public:
    Persons(size_t size = 10);
    Person* add(Person* p);
    // & means either reference or address
    // with reference we make no copy of var (we aren't allocating more memory), instead we access directly
    // the value of variable --> if we just want to read the info we can put const-->read-only
    Person* remove(const string& name);
    void print();
    virtual ~Persons(); //TODO: In next lecture we are going to write code to cleanuo the memory
};

/*
 int x = 5; // variable declaration&definition
 int* px = &x; // px points to (px is a pointer) the memory address of var x (px references to address)
 *px = 6; // the value of x's memory address is now 6 so x = 6
*/

