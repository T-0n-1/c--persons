//
// Created by Toni Mertanen on 25.2.2022.
//

#include "Persons2.h"

Persons2::Persons2() {
    printf("persons vector initial size %d and capacity %d\n", persons.size(), persons.capacity());
}

Person *Persons2::add(Person *p) {
    Person* tmp = remove(p->getFname()+p->getLname());
    persons.push_back(p);
    /*
    persons.insert(persons.end(), p);   // same as push_back()
    persons.insert(persons.begin(), p); // to [0], old [0] becomes [1]
    persons.insert(persons.begin()+2, p);   // to [2]
    persons[0] = p;     // replaces the first           */
    return tmp;
}

// This version seeks for the id and erases the first occurence and returns it
// NOTE! if you implement a version who erases all duplicates you can't put i++ to normal place
//      In that case you need `else i++;` after if()
Person *Persons2::remove(const string &name) {
    Person* tmp = 0;
    for (auto i = persons.begin(); i != persons.end();i++) {
        string refname = (*i)->getFname() + (*i)->getLname();
        if(refname.compare(name)==0) {
            tmp = *i;
            i = persons.erase(i);
            return tmp;
        }
    }
    return tmp;
}

void Persons2::print() {
    printf("---------- person ----------\n");
    // iterator is a "smart" pointer   .begin() = pointer to 1st cell, .end() pointer to virtual cell after last one
    // NOTE: .begin() returns read-write -iterator
    // for (vector<Person*>::iterator i = persons.begin();i != persons.end();i++) {
    // C++ allows nowadays also use "auto" as the type where compiler can find out the actual type
    /*for (auto i = persons.begin();i != persons.end();i++) {
        printf("persons: %s\n", (*i)->toString().c_str());   // NOTE: i is pointer to cell
    }*/
    // if you need just read the values, you can use short version aka "foreach"
    for (auto i : persons) {
        printf("persons: %s\n", i->toString().c_str());  // NOTE: i is the cell value
    }
    printf("----------------------------\n");

}

Persons2::~Persons2() {
    for (auto i = persons.begin(); i != persons.end();i++) {
        delete (*i);
    }
}
