#include "employee.h"

#include <iostream>
#include <limits>

AbstractEmployee::AbstractEmployee() : first_name_(""), last_name_(""), job_("") {}

AbstractEmployee::AbstractEmployee(const std::string& fn,
        const std::string& ln,
        const std::string& j) : first_name_(fn), last_name_(ln), job_(j) {}

AbstractEmployee::~AbstractEmployee() {}

std::ostream& operator<< (std::ostream& os, const AbstractEmployee& e) {
    os << e.first_name_ << " " << e.last_name_;
    return os;
}

void AbstractEmployee::showAll() const {
    std::cout << "========================================\n"
        << "first name: " << first_name_
        << "\nlast name: " << last_name_
        << "\njob: " << job_ << '\n';
}

void AbstractEmployee::setAll() {
    std::string temp;
    std::cout << "Enter fist name: ";
    std::cin >> temp;
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    this->first_name_ = temp;

    std::cout << "Enter last name: ";
    std::cin >> temp;
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    this->last_name_ = temp;

    std::cout << "Enter occupied job: ";
    std::getline(std::cin, temp);
    // conditional buffer ignore only here just because getline capture all to newline
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    this->job_ = temp;
}
//===============================================================================================
Employee::Employee() : AbstractEmployee() {}

Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j)
    : AbstractEmployee(fn, ln, j) {}

void Employee::showAll() const {
    AbstractEmployee::showAll();
}

void Employee::setAll() {
    AbstractEmployee::setAll();
}
//===============================================================================================
Manager::Manager() : AbstractEmployee(), in_charge_of_(0) {}

Manager::Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico)
    : AbstractEmployee(fn, ln, j), in_charge_of_(ico) {}

Manager::Manager(const AbstractEmployee& e, int ico)
    : AbstractEmployee(e), in_charge_of_(ico) {}

Manager::Manager(const Manager& m)
    : AbstractEmployee(m), in_charge_of_(m.in_charge_of_) {}

void Manager::showAll() const {
    AbstractEmployee::showAll();
    std::cout << "in charge of " << in_charge_of_ << " people\n";
}

void Manager::setAll() {
    AbstractEmployee::setAll();
    int ppl;
    std::cout << "Enter number of employees manager is in charge of: ";
    std::cin >> ppl;
    if (std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setInChargeOf(ppl);
}
//===============================================================================================
Fink::Fink() : AbstractEmployee(), reports_to_("") {}

Fink::Fink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo)
    : AbstractEmployee(fn, ln, j), reports_to_(rpo) {}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo)
    : AbstractEmployee(e), reports_to_(rpo) {}

Fink::Fink(const Fink& m)
    : AbstractEmployee(m), reports_to_(m.reports_to_) {}

void Fink::showAll() const {
    AbstractEmployee::showAll();
    std::cout << "reports to " << reports_to_ << "\n";
}

void Fink::setAll() {
    AbstractEmployee::setAll();
    std::string rpo;
    std::cout << "Enter person this manager reports to: ";
    std::getline(std::cin, rpo);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    setReportsTo(rpo);
}
//===============================================================================================
HighFink::HighFink() : AbstractEmployee(), Manager(), Fink() {}

HighFink::HighFink(const std::string& fn, const std::string& ln,
        const std::string& j, const std::string& rpo, int ico)
    : AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}

HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico)
    : AbstractEmployee(e), Manager(e, ico), Fink(e, rpo) {}

HighFink::HighFink(const Fink& f, int ico) : AbstractEmployee(), Manager(f, ico), Fink(f) {}

HighFink::HighFink(const Manager& m, const std::string& rpo)
    : AbstractEmployee(m), Manager(m), Fink(m, rpo) {}

HighFink::HighFink(const HighFink& h)
    : AbstractEmployee(h), Manager(h), Fink(h) {}

void HighFink::showAll() const {
    Manager::showAll();
    std::cout << "Reports to " << reportsTo() << '\n';
}

void HighFink::setAll() {
    Manager::setAll();
    std::string rpo;
    std::cout << "Enter person this manager reports to: ";
    std::getline(std::cin, rpo);
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    setReportsTo(rpo);
}

