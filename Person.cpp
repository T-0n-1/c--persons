//
// Created by Toni Mertanen on 4.2.2022.
//

#include "Person.h"
// getter and setter for variable fname
string Person::getFname() {
    return this->fname;
}

void Person::setFname(string fname) {
    this->fname = fname;
}

// getter and setter for variable lname
string Person::getLname() {
    return this->lname;
}

void Person::setLname(string lname) {
    this->lname = lname;
}

// getter and setter for variable female
bool Person::isFemale() {
    return this->female;
}

void Person::setFemale(bool female) {
    this->female = female;
}


