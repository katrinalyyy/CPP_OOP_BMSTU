#include "planet.h"


    int Planet1::menu() {
        std::cout << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Прочитать базу данных" << std::endl;  
        std::cout << "2. Записать в базу данных" << std::endl; 
        std::cout << "3. Найти планету и информацию о ней" << std::endl;
        std::cout << "4. Вывести базу данных" << std::endl;
        std::cout << "5. Отсортировать планеты" << std::endl; 
        std::cout << "6. Добавить планету" << std::endl; 
        std::cout << "7. Удалить планету" << std::endl; 
        std::cout << "8. Редактировать планету" << std::endl; 
        std::cout << "9.Выход" << std::endl;
        std::cout << "Введите цифру: ";
        int choice;
        std::cin >> choice;
        return choice;
    }


    Planet1::Planet* Planet1::read_db(const char* file_name, Planet* planets, int& count) {
        std::ifstream file(file_name);
        file >> count;
        Planet* new_planets = new Planet[count];
        for (int i = 0; i < count; i++) {
            file >> new_planets[i];
        }
        file.close();
        delete[] planets;
        return new_planets;
    }


    void Planet1::add_planet(Planet* planets, int& count) {
        char temp[10];
        float diametr;
        int life;
        int satellites;
        std::cout << "Введите имя планеты: ";
        std::cin >> temp;
        planets[count].set_name(temp);

        std::cout << "Введите диаметр планеты: ";
        std::cin >> diametr;
        planets[count].set_diametr(diametr);

        std::cout << "Введите жизнь планеты (0 - нет, 1 - да): ";
        std::cin >> life;
        planets[count].set_life_long(life);

        std::cout << "Введите количество спутников: ";
        std::cin >> satellites;
        planets[count].set_kol_satellites_0(satellites);

        count += 1;
    }


    void Planet1::write_db(const char* file_name, Planet* planets, int& count) {
        std::ofstream file(file_name, std::ios::out);
        if (file.is_open()) {
            file << count << std::endl;
            for (int i = 0; i < count; i++) {
                file << planets[i];
                file << std::endl;
            }
        }
        else {
            std::cout << "Ошибка записи в файл";
        }
        file.close();
    }


    void Planet1::delete_planet(Planet*& planets, int& count) {
        char temp[10];
        std::cout << "Введите название планеты, для удаления: ";
        std::cin >> temp;
        char* name = new char[strlen(temp) + 1];
        strcpy_s(name, strlen(name) + 1, temp);

        for (int i = 0; i < count; i++) {
            if (strcmp(planets[i].pName, name) == 0) {
                for (int j = i; j < count - 1; j++) {
                    planets[j] = planets[j + 1];
                }
                count--;
                std::cout << "Планета успешно удалена" << std::endl;
            }
        }
        Planet* pl = new Planet[count];
        for (int i = 0; i < count; i++) {
            pl[i] = planets[i];
        }
        delete[] planets;
        planets = pl;
    }


    void Planet1::find_planet(Planet* planets, int& count) {
        char temp[10];
        std::cout << "Введите название планеты, для поиска информации: ";
        std::cin >> temp;
        int g = 0;
        char* name = new char[strlen(temp) + 1];
        strcpy_s(name, strlen(name) + 1, temp);             
        for (int i = 0; i < count; i++) {
            if (strcmp(planets[i].get_name(), name) == 0) {
                g++;
                std::cout << "Информация о планете:" << std::endl;
                std::cout << "Диаметр: " << planets[i].get_diametr() << std::endl;
                std::cout << "Продолжительность жизни: " << planets[i].get_life_long() << std::endl;
                std::cout << "Количество спутников: " << planets[i].get_kol_satellites_0() << std::endl;
            }
        }
        if (g == 0) {
            std::cout << "Планета с именем " << name << " не найдена." << std::endl;
        }
    }


    void Planet1::sort_db(Planet* planets, int& count) {
        int minIndex;
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (planets[j] < planets[i]) {
                    Planet temp = planets[j];
                    planets[j] = planets[i];
                    planets[i] = temp;
                }

            }
        }
    }


    void Planet1::edit_planet(Planet* planets, int& count) {

        char temp[10];
        std::cout << "Введите имя планеты для редактирования: ";
        std::cin >> temp;
        char* searchName = new char(strlen(temp) + 1);
        strcpy_s(searchName, strlen(searchName) + 1, temp);

        int index = -1;
        for (int i = 0; i < count; ++i) {
            if (strcmp(planets[i].get_name(), searchName) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "Планета с именем " << searchName << " не найдена." << std::endl;
        }
        else {
            std::cout << "Планета найдена. Введите новые данные:" << std::endl;
            Planet newPlanet;
            std::cin >> newPlanet;

            planets[index] = newPlanet;

            std::cout << "Планета успешно отредактирована." << std::endl;
        }
    }


    Planet1::Planet::Planet(const Planet& p1) {
        this->life_long = p1.life_long;
        this->dimetr = p1.dimetr;
        this->kol_satellites = p1.kol_satellites;
        this->pName = new char[strlen(p1.pName) + 1];
        for (int i = 0;i < strlen(p1.pName) + 1;i++) {
            this->pName[i] = p1.pName[i];
        }
    }


    bool Planet1::Planet::operator<(const Planet& p1) {
        return (strcmp(this->pName, p1.pName) < 0);
    }



    bool Planet1::Planet::operator>(const Planet& p1) {
        return (strcmp(this->pName, p1.pName) > 0);
    }


    Planet1::Planet& Planet1::Planet::operator=(const Planet& p1) {
        if (&p1 == this) {
            return *this;
        }
        this->life_long = p1.life_long;
        this->dimetr = p1.dimetr;
        this->kol_satellites = p1.kol_satellites;
        set_name(p1.pName);
        return *this;
    }


    std::ostream& Planet1::operator<<(std::ostream& out, const Planet& planet) {
        out << planet.pName << " " << planet.dimetr << " " << planet.life_long << " " << planet.kol_satellites;
        return out;
    }


    std::istream& Planet1::operator>>(std::istream& in, Planet& planet) {
        char word[Size];
        in >> word;
        planet.pName = new char[strlen(word) + 1];
        for (int i = 0;i < strlen(word) + 1;i++) {
            planet.pName[i] = word[i];
        }
        in >> planet.dimetr >> planet.life_long >> planet.kol_satellites;
        return in;
    }
