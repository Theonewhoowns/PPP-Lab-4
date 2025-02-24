#include "Classes.h"

//1st program
Work::Work(const string& name, double rate, WorkType type) : name(name), rate(rate), type(type) {}

const string& Work::getName() const { return name; }
double Work::getRate() const { return rate; }
WorkType Work::getType() const { return type; }

void Work::display() const {
    cout << "Job: " << name << ", Rate: " << rate
        << ", Type: " << (type == Hourly ? "Hourly" : type == Fixed ? "Fixed" : "Piecework") << endl;
}


Worker::Worker(const string& name) : name(name), totalSalary(0) {}

void Worker::addWork(const Work& work, double hoursOrUnits) {
    double payment = work.getType() == Fixed ? work.getRate() : work.getRate() * hoursOrUnits;
    totalSalary += payment;
    performedWork[work.getName()] += hoursOrUnits;
}

const string& Worker::getName() const { return name; }
double Worker::getTotalSalary() const { return totalSalary; }

void Worker::display() const {
    cout << "Worker: " << name << ", Total Salary: " << totalSalary << endl;
}


void PayrollSystem::addWork(const string& name, double rate, WorkType type) {
    works.emplace_back(name, rate, type);
}

void PayrollSystem::addWorker(const string& name) {
    workers.emplace_back(name);
}

Worker* PayrollSystem::findWorker(const string& name) {
    for (auto& worker : workers) {
        if (worker.getName() == name) return &worker;
    }
    return nullptr;
}

Work* PayrollSystem::findWork(const string& name) {
    for (auto& work : works) {
        if (work.getName() == name) return &work;
    }
    return nullptr;
}

void PayrollSystem::displayAllSalaries() const {
    cout << "Total Payroll:\n";
    for (const auto& worker : workers) {
        worker.display();
    }
}

//2nd program
LuggageCompartment::LuggageCompartment(const string& owner, int cellNumber) : owner(owner), cellNumber(cellNumber) {}

void LuggageCompartment::display() const {
    cout << "Owner: " << owner << ", Luggage Cell: " << cellNumber << endl;
}


RailwayStation* RailwayStation::instance_ptr = nullptr;

RailwayStation::RailwayStation() {}

RailwayStation::~RailwayStation() {
    instance_ptr = nullptr;
}

RailwayStation* RailwayStation::getInstance() {
    if (!instance_ptr) instance_ptr = new RailwayStation();
    return instance_ptr;
}

void RailwayStation::addLuggageCompartment(const string& owner, int cellNumber) {
    luggageCompartmentList.emplace_back(owner, cellNumber);
}

void RailwayStation::displayAllLuggageCompartment() const {
    for (const auto& compartment : luggageCompartmentList) {
        compartment.display();
    }
}
