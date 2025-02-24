#include "Classes.h"
#include "Functions.h"

void menuPayrollSystem() {
    PayrollSystem system;
    system.addWork("Loading", 500, WorkType::Fixed);
    system.addWork("Cleaning", 200, WorkType::Hourly);
    system.addWork("AssemblingParts", 50, WorkType::Piecework);

    system.addWorker("Ivanov");
    system.addWorker("Petrov");

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add worker\n";
        cout << "2. Add job\n";
        cout << "3. Register work's accomplishment\n";
        cout << "4. Check worker's salary\n";
        cout << "5. Check the total amount of payments\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";

        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Enter employee's surname: ";
            string name;
            cin >> name;
            system.addWorker(name);
            break;
        }
        case 2: {
            cout << "Enter job type: ";
            string name;
            cin >> name;
            cout << "Enter rate: ";
            double rate;
            cin >> rate;
            if (rate < 10000) {
                cout << "Enter payment type (0 - Hourly, 1 - Fixed, 2 - Piecework): ";
                int type;
                cin >> type;
                system.addWork(name, rate, static_cast<WorkType>(type));
            }
            else {
                cout << "The rate is too high. Looks like smth illegal =).\n";
            }
            break;
        }
        case 3: {
            cout << "Enter employee's surname: ";
            string workerName;
            cin >> workerName;
            Worker* worker = system.findWorker(workerName);
            if (!worker) {
                cout << "Worker hasn't been found.\n";
                break;
            }
            cout << "Enter job type: ";
            string workName;
            cin >> workName;
            Work* work = system.findWork(workName);
            if (!work) {
                cout << "Job hasn't been found.\n";
                break;
            }
            cout << "Enter the number of hours or the amount of accomplished works: ";
            double count;
            cin >> count;
            if (count < 2000) {
                worker->addWork(*work, count);
            }
            else {
                cout << "Slavery isn't an appropriate thing. Please, try again.\n";
            }
            break;
        }
        case 4: {
            cout << "Enter employee's surname: ";
            string name;
            cin >> name;
            Worker* worker = system.findWorker(name);
            if (!worker) {
                cout << "Worker hasn't been found.\n";
                break;
            }
            worker->display();
            break;
        }
        case 5:
            system.displayAllSalaries();
            break;
        case 6:
            return;
        default:
            cout << "Wrong input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}

void menuLuggageSystem() {
    RailwayStation* station = RailwayStation::getInstance();
    station->addLuggageCompartment("Ivanov", 14);
    station->addLuggageCompartment("Smirnova", 20);
    station->addLuggageCompartment("Petrov", 3);

    station->displayAllLuggageCompartment();
}
