#include "LabaSeven/CustomVector.h"
#include "LabaSeven/Engine.h"
#include "LabaSeven/ICEngine.h"
#include "LabaSeven/DieselEngine.h"
#include "LabaSeven/JetEngine.h"

void demoMode() {
    CustomVector<Engine*> engines;
    engines.push_back(new ICEngine());
    engines.push_back(new DieselEngine());
    engines.push_back(new JetEngine());

    std::cout << "Demo Mode - All Engines:" << std::endl;
    engines.print();

    std::cout << "Removing Diesel Engine (Index 1)" << std::endl;
    engines.remove(1);
    engines.print();

    std::cout << "Clearing All Engines" << std::endl;
    engines.clear();
    engines.print();
}

void interactiveMode() {
    CustomVector<Engine*> engines;
    int choice;
    do {
        std::cout << "\nMenu:\n1. Add ICEngine\n2. Add DieselEngine\n3. Add JetEngine\n4. Print Engines\n5. Remove Engine\n6. Clear Engines\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            engines.push_back(new ICEngine());
            break;
        case 2:
            engines.push_back(new DieselEngine());
            break;
        case 3:
            engines.push_back(new JetEngine());
            break;
        case 4:
            engines.print();
            break;
        case 5: {
            size_t index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;
            try {
                engines.remove(index);
            }
            catch (const std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 6:
            engines.clear();
            break;
        }
    } while (choice != 0);
}

int main() {
    int mode;
    std::cout << "Choose Mode:\n1. Demo Mode\n2. Interactive Mode\nChoice: ";
    std::cin >> mode;

    if (mode == 1) {
        demoMode();
    }
    else if (mode == 2) {
        interactiveMode();
    }
    else {
        std::cout << "Invalid choice. Exiting." << std::endl;
    }

    return 0;
}
