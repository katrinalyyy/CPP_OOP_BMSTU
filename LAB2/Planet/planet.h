#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef PLANET
#define PLANET
#include <iostream>
#include <fstream>
#include <cstring>

namespace Planet1 {
    const int Size = 9;

    class Planet {
    private:
        char* pName;
        float dimetr;
        int life_long;
        int kol_satellites;

    public:
        Planet() {
            pName = new char[1];
            pName[0] = '\0';
            dimetr = 0;
            life_long = 0;
            kol_satellites = 0;
        }

        Planet(char* pName_0, float dimetr_0, int life_long_0, int kol_satellites_0) {
            pName = new char[strlen(pName_0) + 1];
            strcpy_s(pName, strlen(pName_0) + 1, pName_0);
            dimetr = dimetr_0;
            life_long = life_long_0;
            kol_satellites = kol_satellites_0;
        }


        void set_name(char* name) {
            if (this->pName != nullptr) {
                delete[] this->pName;
            }
            this->pName = new char[strlen(name) + 1];
            strcpy(this->pName, name);
        }
        void set_diametr(float dimetr0) { dimetr = dimetr0; }
        void set_life_long(int life_long0) { life_long = life_long0; }
        void set_kol_satellites_0(int kol_satellites0) { kol_satellites = kol_satellites0; }

        char* get_name() { return pName; }
        float get_diametr() { return dimetr; }
        int get_life_long() { return life_long; }
        int get_kol_satellites_0() { return kol_satellites; }

        void print_db2() {
            //for (int i = 0; i < strlen(pName) + 1; ++i) { cout << pName[i]; }
            std::cout << pName;
            std::cout << ", " << dimetr << ", " << life_long << ", " << kol_satellites << ". " << std::endl;
        }

        friend Planet* read_db(const char* file_name, Planet* planets, int& count);
        friend void write_db(const char* file_name, Planet* planets, int& count);
        friend void sort_db(Planet* planets, int& count);
        friend void add_planet(Planet* planets, int& count);

        friend void delete_planet(Planet*& planets, int& count);
        friend void find_planet(Planet* planets, int& count);
        friend void edit_planet(Planet* planets, int& count);

        friend std::ostream& operator<<(std::ostream& out, const Planet& planet);
        friend std::istream& operator>>(std::istream& in, Planet& planet);
        bool operator<(const Planet& p1);
        bool operator>(const Planet& p1);
        Planet& operator=(const Planet& p1);
        Planet(const Planet& p1);

        ~Planet() { delete[] pName; }
    };


    void edit_planet(Planet* planets, int& count);
    void sort_db(Planet* planets, int& count);
    void find_planet(Planet* planets, int& count);
    void delete_planet(Planet*& planets, int& count);
    void write_db(const char* file_name, Planet* planets, int& count);
    void add_planet(Planet* planets, int& count);
    void add_planet(Planet* planets, int& count);
    Planet* read_db(const char* file_name, Planet* planets, int& count);
    int menu();
}

#endif
