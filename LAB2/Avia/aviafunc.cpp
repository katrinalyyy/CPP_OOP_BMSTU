#include "avia.h"

    int Avia1::menu() {
        std::cout << std::endl;
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Прочитать базу данных" << std::endl;  
        std::cout << "2. Записать в базу данных" << std::endl; 
        std::cout << "3. Найти информацию о билете" << std::endl;
        std::cout << "4. Вывести базу данных" << std::endl;
        std::cout << "5. Отсортировать билеты" << std::endl; 
        std::cout << "6. Добавить билет" << std::endl; 
        std::cout << "7. Удалить билет" << std::endl; 
        std::cout << "8. Редактировать билет" << std::endl; 
        std::cout << "9.Выход" << std::endl;
        std::cout << "Введите цифру: ";
        int choice;
        std::cin >> choice;
        return choice;
    }


    Avia1::Avia* Avia1::read_db(const char* file_name, Avia* tickets, int& count) {
        std::ifstream file(file_name);
        file >> count;
        Avia* new_tickets = new Avia[count];
        for (int i = 0; i < count; i++) {
            file >> new_tickets[i];
        }
        file.close();
        delete[] tickets;
        return new_tickets;
    }


    void Avia1::add_ticket(Avia* tickets, int& count) {
        char temp[10];
        float dist;
        int way;
        int transfers;
        std::cout << "Введите название страны для полета: ";
        std::cin >> temp;
        tickets[count].set_name(temp);

        std::cout << "Введите расстояние до этой страны: ";
        std::cin >> dist;
        tickets[count].set_dist(dist);

        std::cout << "Введите продолжительность полета (кол-во часов): ";
        std::cin >> way;
        tickets[count].set_way_long(way);

        std::cout << "Введите количество пересадок: ";
        std::cin >> transfers;
        tickets[count].set_kol_transfers_0(transfers);

        count += 1;
    }

    void Avia1::write_db(const char* file_name, Avia* tickets, int& count) {
        std::ofstream file(file_name, std::ios::out);
        if (file.is_open()) {
            file << count << std::endl;
            for (int i = 0; i < count; i++) {
                file << tickets[i];
                file << std::endl;
            }
        }
        else {
            std::cout << "Ошибка записи в файл";
        }
        file.close();
    }



    void Avia1::delete_ticket(Avia*& tickets, int& count) {
        char temp[10];
        std::cout << "Введите название билета по стране, для удаления: ";
        std::cin >> temp;
        char* name = new char[strlen(temp) + 1];
        strcpy_s(name, strlen(name) + 1, temp);

        for (int i = 0; i < count; i++) {
            if (strcmp(tickets[i].pName, name) == 0) {
                for (int j = i; j < count - 1; j++) {
                    tickets[j] = tickets[j + 1];
                }
                count--;
                std::cout << "Билет успешно удален" << std::endl;
            }
        }
        Avia* av = new Avia[count];
        for (int i = 0; i < count; i++) {
            av[i] = tickets[i];
        }
        delete[] tickets;
        tickets = av;
    }


    void Avia1::find_ticket(Avia* tickets, int& count) {
        char temp[10];
        std::cout << "Введите название билета по стране, для поиска информации: ";
        std::cin >> temp;
        int g = 0;
        char* name = new char[strlen(temp) + 1];
        strcpy_s(name, strlen(name) + 1, temp);
        for (int i = 0; i < count; i++) {
            if (strcmp(tickets[i].get_name(), name) == 0) {
                g++;
                std::cout << "Информация о билете:" << std::endl;
                std::cout << "Расстояние до страны: " << tickets[i].get_dist() << std::endl;
                std::cout << "Продолжительность полета: " << tickets[i].get_way_long() << std::endl;
                std::cout << "Количество пересадок: " << tickets[i].get_kol_transfers_0() << std::endl;
            }
        }
        if (g == 0) {
            std::cout << "Билет с именем " << name << " не найден." << std::endl;
        }
    }


    void Avia1::sort_db(Avia* tickets, int& count) {
        int minIndex;
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (tickets[j] < tickets[i]) {
                    Avia temp = tickets[j];
                    tickets[j] = tickets[i];
                    tickets[i] = temp;
                }

            }
        }
    }


    void Avia1::edit_ticket(Avia* tickets, int& count) {

        char temp[10];
        std::cout << "Введите имя билета по стране для редактирования: ";
        std::cin >> temp;
        char* searchName = new char(strlen(temp) + 1);
        strcpy_s(searchName, strlen(searchName) + 1, temp);
        int index = -1;
        for (int i = 0; i < count; ++i) {
            if (strcmp(tickets[i].get_name(), searchName) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            std::cout << "Билет с именем " << searchName << " не найден." << std::endl;
        }
        else {
            std::cout << "Бител найден. Введите новые данные:" << std::endl;
            Avia newTicket;
            std::cin >> newTicket;
            tickets[index] = newTicket;
            std::cout << "Билет успешно отредактирован." << std::endl;
        }
    }


    Avia1::Avia::Avia(const Avia& p1) {
        this->way_long = p1.way_long;
        this->dist = p1.dist;
        this->kol_transfers = p1.kol_transfers;
        this->pName = new char[strlen(p1.pName) + 1];
        for (int i = 0;i < strlen(p1.pName) + 1;i++) {
            this->pName[i] = p1.pName[i];
        }
    }


    bool Avia1::Avia::operator<(const Avia& p1) {
        return (strcmp(this->pName, p1.pName) < 0);
    }


    bool Avia1::Avia::operator>(const Avia& p1) {
        return (strcmp(this->pName, p1.pName) > 0);
    }


    Avia1::Avia& Avia1::Avia::operator=(const Avia& p1) {
        if (&p1 == this) {
            return *this;
        }
        this->way_long = p1.way_long;
        this->dist = p1.dist;
        this->kol_transfers = p1.kol_transfers;
        set_name(p1.pName);
        return *this;
    }


    std::ostream& Avia1::operator<<(std::ostream& out, const Avia1::Avia& ticket) {
        out << ticket.pName << " " << ticket.dist << " " << ticket.way_long << " " << ticket.kol_transfers;
        return out;
    }


    std::istream& Avia1::operator>>(std::istream& in, Avia1::Avia& ticket) {
        char word[Size];
        in >> word;
        ticket.pName = new char[strlen(word) + 1];
        for (int i = 0;i < strlen(word) + 1;i++) {
            ticket.pName[i] = word[i];
        }
        in >> ticket.dist >> ticket.way_long >> ticket.kol_transfers;
        return in;
    }
