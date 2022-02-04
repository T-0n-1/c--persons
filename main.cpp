//
// Created by Toni Mertanen on 4.2.2022.
//

#include <stdio.h> // Instead of C++ iostream using C standard io
#include "Persons.h"
#include "Persons2.h"

int main() {
    /*                                      // Commented out to test properly the Persons class
    Person p("Olli", "Koskimaa", false);
    printf("p: %s \n", p.toString().c_str());

    Person p2; // default ctor, note: no ()
    printf("p2: %s \n", p2.toString().c_str());

    Employee e; // default ctor
    printf("e: %s \n", e.toString().c_str());

    // If we create dynamic child objects and assign the address (returned from "new") to a base pointer var
    //  -> polymorphism works with virtual functions
    Person* pointer = new Employee("Nikke", "Knakkerton", false, 1250);
    printf("pointer: %s \n", pointer->toString().c_str());
    // programmer is responsible for cleaning heap (dynamic memory) when dyn.mem. is not needed anymore
    delete pointer;
    pointer = 0; // if pointer value (=address) is zero, we know the mem.space is free to be reused
    */

    Persons prs;
    prs.print();
    Person* p;
    p = prs.add(new Person());
    if (p) {
        printf("removed: %s\n", p->toString().c_str());
        delete p;
    }
    p = prs.add(new Employee());
    if (p) {
        printf("removed: %s\n", p->toString().c_str());
        delete p;
    }
    prs.print();
    p = prs.add(new Employee);
    if (p) {
        printf("removed: %s\n", p->toString().c_str());
        delete p;
    }
    prs.print();

    Persons2 prs2;
    prs2.add(new Person("Kerttu", "Niskanen", true));
    prs2.add(new Employee("Robin", "Hood"));
    prs2.add(new Person("Maija", "Meikäläinen", true));
    prs2.print();
    p = prs2.remove("RobinHood");
    if (p) {
        printf("removed: %s\n", p->toString().c_str());
        delete p;
        p = 0;
    }
    prs2.print();

    return 0;
}
