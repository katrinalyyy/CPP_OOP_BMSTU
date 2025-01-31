#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

class Engine {
protected:
    char type[50];
public:
    Engine(const char* type) {
        std::strncpy(this->type, type, 50);
        std::cout << "Engine()" << std::endl;
    }

    virtual ~Engine() {
        std::cout << "~Engine()" << std::endl;
    }

    virtual void show() const = 0;
};


#endif // ENGINE_H
