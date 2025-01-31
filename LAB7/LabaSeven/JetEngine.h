#ifndef JETENGINE_H
#define JETENGINE_H

#include "Engine.h"
#include <cstring>

class JetEngine : public Engine {
public:
    JetEngine() : Engine("Jet Engine") {
        std::cout << "JetEngine()" << std::endl;
    }

    ~JetEngine() override {
        std::cout << "~JetEngine()" << std::endl;
    }

    void show() const override {
        std::cout << "Type: " << type << std::endl;
    }
};

#endif // JETENGINE_H
