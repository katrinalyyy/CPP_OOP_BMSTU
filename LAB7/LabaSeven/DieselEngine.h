#ifndef DIESELENGINE_H
#define DIESELENGINE_H

#include "ICEngine.h"

class DieselEngine : public ICEngine {
public:
    DieselEngine() {
        std::strncpy(type, "Internal Combustion Engine (Diesel)", 50);
        std::cout << "DieselEngine()" << std::endl;
    }

    ~DieselEngine() override {
        std::cout << "~DieselEngine()" << std::endl;
    }

    void show() const override {
        std::cout << "Type: " << type << std::endl;
    }
};

#endif // DIESELENGINE_H
