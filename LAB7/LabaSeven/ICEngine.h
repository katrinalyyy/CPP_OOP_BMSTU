#ifndef ICENGINE_H
#define ICENGINE_H

#include "Engine.h"
#include <cstring>

class ICEngine : public Engine {
public:
    ICEngine() : Engine("Internal Combustion Engine") {
        std::cout << "ICEngine()" << std::endl;
    }

    ~ICEngine() override {
        std::cout << "~ICEngine()" << std::endl;
    }

    void show() const override {
        std::cout << "Type: " << type << std::endl;
    }
};

#endif // ICENGINE_H
