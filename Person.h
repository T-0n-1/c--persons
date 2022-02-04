//
// Created by Toni Mertanen on 4.2.2022.
//

#pragma once
#include <string>
using namespace std;

class Person {
private:
    string fname;
    string lname;
    bool female;
public:
    Person(string fname = "Keijo", string lname = "Rosberg", bool female = false);   // Constructor with default velues

    string getFname() { return fname; }
    void setFname(string fname) { if (fname.size() > 0) this->fname = fname; }

    string getLname() { return lname; }
    void setLname(string lname) { if (lname.size() > 0) this->lname = lname; }

    bool isFemale() { return female; }
    void setFemale(bool female) { this->female = female; }

    //About 'virtual': if we want polymorphism (which works with base class
    // object pointers and references) we have to use virtual keyword. Rule of
    // thumb: destructor should also be declared virtual
    virtual string toString();
    virtual ~Person();

}; //NOTE The semicolon!!!

// INHERITANCE
// Inherited members can be spesified by
// public: all inherited members as is
// protected: all inherited public members -> protected
// private: all inherited public members -> private
class Employee : public Person {
private:
    float salary;

public:
    Employee(string fname = "Rami", string lname = "Rohkea", bool female = false, float salary = 3000.0f);

    float getSalary() { return salary; }

    void setSalary(float salary) { this -> salary = salary; }

    string toString();

    virtual ~Employee();
};