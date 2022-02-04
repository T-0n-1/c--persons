//
// Created by Toni Mertanen on 4.2.2022.
//

#include <stdio.h>
#include "Person.h"

int main(int argc, char** argv) {
    Person p;
    printf("Person p: %s %s %s\n", p.getFname().c_str(), p.getLname().c_str(), p.isFemale() ? "female" : "male");
    return 0;
}
