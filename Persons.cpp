//
// Created by Toni Mertanen on 24.2.2022.
//

#include "Persons.h"

Persons::Persons(size_t size) {
    // size can be 0 but array can't!
    if ( size <= 0 ) size = 10;
    this->size = size;      // save the size to member variable since c/c++ array is not a class object
                            // --> does not know it's size
    // if array will be created dynamically but all cells are Person objects --> still no Employee objects
    // persons = new Person[size]; // size amount of Person objects created by default constructor
    // but... we are using the cells-also-pointer version
    persons = new Person*[this->size]; // memory allocation, user have to make sure it clears when not needed anymore
    // also memory allocation does not 'empty' (set null values) --> we need to do that
    for(size_t i = 0; i < this->size; i++) persons[i] = 0; // 0 means that cell is free

}

Person *Persons::add(Person *p) {
    string refname = p->getFname() + p->getLname();
    Person* tmp = remove(refname);
    // try to find first empty cell
    for(size_t i = 0; i < this->size; i++){
        if(persons[i] == 0) {
            persons[i] = p;
            return tmp;
        }
    }
    return tmp;
}

Person *Persons::remove(const string &name) {
    // we go through the array to find an object having the same name
    Person* tmp = 0;
    for(size_t i = 0; i < this->size; i++){
        if (persons[i] != 0) {   // skip the null pointers
            string refname = persons[i]->getFname() + persons[i]->getLname();
            if (name.compare(refname) == 0) {
                tmp = persons[i];
                persons[i] = 0;
                return tmp; // or break;
            }
        }
    }
    return tmp;
}

void Persons::print() {
    printf("---------- Persons ----------\n");
    for(size_t i = 0; i < this->size; i++){
        printf("Persons[%d] = ", i);
        if (persons[i]) {
            printf("%s\n", persons[i]->toString().c_str());
        } else printf("0\n");
    }
    printf("-----------------------------\n");
}

// If we have some dynamic memory allocated in a class --> we are responsible to clean up the memory
Persons::~Persons() {
    for(size_t i = 0; i < this->size; i++) {
        if (persons[i]) {
            delete persons[i];
            persons[i] = 0;
        }
    }
    // to delete an array, we need to use "delete[]"
    delete[] persons;
}
