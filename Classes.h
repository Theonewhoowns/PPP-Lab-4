#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//2nd program
enum WorkType {
    Hourly,
    Fixed,
    Piecework
};

class Work {
private:
    string name;
    double rate;
    WorkType type;

public:
    Work(const string& name, double rate, WorkType type);
    const string& getName() const;
    double getRate() const;
    WorkType getType() const;
    void display() const;
};

class Worker {
private:
    string name;
    double totalSalary;
    unordered_map<string, double> performedWork;

public:
    Worker(const string& name);
    void addWork(const Work& work, double hoursOrUnits);
    const string& getName() const;
    double getTotalSalary() const;
    void display() const;
};

class PayrollSystem {
private:
    vector<Work> works;
    vector<Worker> workers;

public:
    void addWork(const string& name, double rate, WorkType type);
    void addWorker(const string& name);
    Worker* findWorker(const string& name);
    Work* findWork(const string& name);
    void displayAllSalaries() const;
};

//1st program
class LuggageCompartment {
private:
    string owner;
    int cellNumber;

public:
    LuggageCompartment(const string& owner, int cellNumber);
    void display() const;
};

class RailwayStation {
private:
    vector<LuggageCompartment> luggageCompartmentList;
    static RailwayStation* instance_ptr;
    RailwayStation();

public:
    RailwayStation(const RailwayStation&) = delete;
    ~RailwayStation();
    static RailwayStation* getInstance();
    void addLuggageCompartment(const string& owner, int cellNumber);
    void displayAllLuggageCompartment() const;
};


