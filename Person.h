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
    string getFname();
    void setFname(string fname);

    string getLname();
    void setLname(string lname);

    bool isFemale();
    void setFemale(bool female);
};
