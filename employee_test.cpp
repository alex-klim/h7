#include "employee.h"
#include <iostream>

int main() {
    Employee employee("Rick", "Deckard", "Blade runner");
    std::cout << employee << '\n';
    employee.showAll();
    std::cout << '\n';

    Manager manager("Harry", "Bryant", "Captain", 5);
    std::cout << manager << '\n';
    manager.showAll();
    std::cout << '\n';

    Fink fink("Leon", "Kowalski", "Cargo loader", "Roy Batty");
    std::cout << fink << '\n';
    fink.showAll();
    std::cout << '\n';

    HighFink highFink(manager, "Eduardo Gaff");
    highFink.showAll();
    std::cout << '\n';
    std::cout << "Press a key for next phase:" << '\n';
    std::cin.get();

    HighFink highFink2;
    highFink2.setAll();

    std::cout << "Using an AbstractEmployee * pointer:" << '\n';
    AbstractEmployee* tri[4] = { &employee, &fink, &highFink, &highFink2};
    for (auto i = 0; i < 4; i++) {
        tri[i]->showAll();
    }
    return 0;
}
