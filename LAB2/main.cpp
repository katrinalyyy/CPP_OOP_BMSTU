#include <iostream>
#include "Avia/avia.h"
#include "Planet/planet.h"


int main(){
    setlocale(LC_ALL, "Russian");
    std::cout << "С какой библиотекой Вы хотите работать (0/1) 0 - Планеты, 1 - Авиабилет: ";
    int n;
    std::cin >> n;
    char* file_name;
    
    if (n == 0) {
            file_name = "planet.txt";
            int count = 0;
            Planet1::Planet* planets = new Planet1::Planet[0];

            while (true) {
                switch (Planet1::menu()) {
                case 1:
                    planets = Planet1::read_db(file_name, planets, count);
                    break;
                case 2:
                    Planet1::write_db(file_name, planets, count);
                    break;
                case 3:
                    Planet1::find_planet(planets, count);
                    break;
                case 4:
                    for (int i = 0; i < count; i++) {
                        planets[i].print_db2();                
                    }
                    break;
                case 5:
                    Planet1::sort_db(planets, count);
                    break;
                case 6: {
                    Planet1::Planet* new_planets = new Planet1::Planet[count + 1];
                    for (int i = 0;i < count;i++) {
                        new_planets[i] = planets[i];
                    }
                    delete[] planets;
                    planets = new_planets;
                    Planet1::add_planet(planets, count);
                    break;}
                case 7:
                    Planet1::delete_planet(planets, count);
                    break;
                case 8:
                    Planet1::edit_planet(planets, count);
                    break;
                case 9:
                    return 0;
                default:
                    std::cout << " Неправильный ввод" << std::endl;
                    break;

                }
            }
    }
    else {
            file_name = "avia.txt";
            int count = 0;
            Avia1::Avia* tickets = new Avia1::Avia[0];
            while (true) {
                switch (Avia1::menu()) {
                case 1:
                    tickets = read_db(file_name, tickets, count);
                    break;
                case 2:
                    Avia1::write_db(file_name, tickets, count);
                    break;
                case 3:
                    Avia1::find_ticket(tickets, count);
                    break;
                case 4:{
                    for (int i = 0; i < count; i++) {
                        tickets[i].print_db1();               
                    }
                }
                    break;
                case 5:
                    Avia1::sort_db(tickets, count);
                    break;
                case 6: {
                    Avia1::Avia* new_tickets = new Avia1::Avia[count + 1];
                    for (int i = 0;i < count;i++) {
                        new_tickets[i] = tickets[i];
                    }
                    delete[] tickets;
                    tickets = new_tickets;
                    Avia1::add_ticket(tickets, count);
                    break;}
                case 7:
                    Avia1::delete_ticket(tickets, count);
                    break;
                case 8:
                    Avia1::edit_ticket(tickets, count);
                    break;
                case 9:
                    return 0;
                default:
                    std::cout << " Неправильный ввод" << std::endl;
                    break;
                }
            }
    }

}
