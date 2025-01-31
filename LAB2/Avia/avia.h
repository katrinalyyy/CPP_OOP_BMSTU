#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef AVIA
#define AVIA
#include <iostream>
#include <fstream>
#include <cstring>

namespace Avia1 {


    const int Size = 10;


    class Avia {
    private:
        char* pName;
        float dist;
        int way_long;
        int kol_transfers;

    public:
        Avia() {
            pName = new char[1];
            pName[0] = '\0';
            dist = 0;
            way_long = 0;
            kol_transfers = 0;
        }

        Avia(char* pName_0, float dist_0, int way_long_0, int kol_transfers_0) {
            pName = new char[strlen(pName_0) + 1];
            strcpy_s(pName, strlen(pName_0) + 1, pName_0);
            dist = dist_0;
            way_long = way_long_0;
            kol_transfers = kol_transfers_0;
        }


        void set_name(char* name) {
            if (this->pName != nullptr) {
                delete[] this->pName;
            }
            this->pName = new char[strlen(name) + 1];
            strcpy(this->pName, name);
        }
        void set_dist(float dist0) { dist = dist0; }
        void set_way_long(int way_long0) { way_long = way_long0; }
        void set_kol_transfers_0(int kol_transfers0) { kol_transfers = kol_transfers0; }

        char* get_name() { return pName; }
        float get_dist() { return dist; }
        int get_way_long() { return way_long; }
        int get_kol_transfers_0() { return kol_transfers; }

        void print_db1() {
            std::cout << pName;
            std::cout << ", " << dist << ", " << way_long << ", " << kol_transfers << ". " << std::endl;
        }

        friend Avia* read_db(const char* file_name, Avia* tickets, int& count);
        friend void write_db(const char* file_name, Avia* tickets, int& count);
        friend void sort_db(Avia* tickets, int& count);
        friend void add_ticket(Avia* tickets, int& count);

        friend void delete_ticket(Avia*& tickets, int& count);
        friend void find_ticket(Avia* tickets, int& count);
        friend void edit_ticket(Avia* tickets, int& count);

        friend std::ostream& operator<<(std::ostream& out, const Avia& ticket);
        friend std::istream& operator>>(std::istream& in, Avia& ticket);
        bool operator<(const Avia& p1);
        bool operator>(const Avia& p1);
        Avia& operator=(const Avia& p1);
        Avia(const Avia& p1);

        ~Avia() { delete[] pName; }
    };


    void edit_ticket(Avia* tickets, int& count);
    void sort_db(Avia* tickets, int& count);
    void find_ticket(Avia* tickets, int& count);
    void delete_ticket(Avia*& tickets, int& count);
    void write_db(const char* file_name, Avia* tickets, int& count);
    void add_ticket(Avia* tickets, int& count);
    void add_ticket(Avia* tickets, int& count);
    Avia* read_db(const char* file_name, Avia* tickets, int& count);
    int menu();
}
#endif
