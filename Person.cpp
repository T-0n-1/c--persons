//
// Created by Toni Mertanen on 4.2.2022.
//

#include "Person.h"

Person::Person(string fname, string lname, bool female)
    : fname(fname), lname(lname), female(female)
{
    if (getFname().size() == 0) setFname("???");
    if (getLname().size() == 0) setLname("???");
}

// getter and setter for variable fname
/*string Person::getFname() {               Commented out because declared and defined in header
    return this->fname;
}

void Person::setFname(string fname) {
    if(fname.length() != 0)
        this->fname = fname;
}

// getter and setter for variable lname
string Person::getLname() {
    return this->lname;
}

void Person::setLname(string lname) {
    if(lname.length() != 0)
        this->lname = lname;
}

// getter and setter for variable female
bool Person::isFemale() {
    return this->female;
}

void Person::setFemale(bool female) {
    this->female = female;
}*/

string Person::toString() {
    const size_t bufsize = 1024;
    char buf[bufsize];
    snprintf(buf, bufsize, "%s %s %s", this->getFname().c_str(), this->getLname().c_str(), this->isFemale() ? "female" : "male");
    return buf;
}

Person::~Person() {
    printf("Person destructor: %s\n", this->toString().c_str());
}

// In child constructor we should call parent classes constructor. It has to be called
// in init list and it should be the first call. NOTE: Base class ctor has to be spesified
// by class name (Reason: C++ accepts multiple inheritance).
Employee::Employee(string fname, string lname, bool female, float salary)
    : Person(fname, lname, female), salary(salary)
{

}

string Employee::toString() {
    // 1) when we want to call base class function which has been overloaded in child class
    //      -> we have to spesify class name prefix
    // 2) numeric values cannot be concatenated to string with '+' operator
    //      -> global std::to_string() has to be used
    return Person::toString() + " salary: " + to_string(getSalary());
}

Employee::~Employee() {
    printf("Employee destructor: %s\n", this->toString().c_str());
}