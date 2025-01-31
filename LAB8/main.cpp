#include "LabaEight/LabaEight.h"

int main() {
    //setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int x;
    while (1) {
        std::cout << "введите номер задания: ";
        std::cin >> x;
        std::cin.ignore(); // Очищаем входной буфер от символа новой строки
        switch (x) {
        case 1: {
            // Task 1
            //Пользователь вводит два слова(две переменные).
            //Сколько раз в первом слове встречается последняя буква второго слова.
            std::string word1, word2;
            std::cout << "Введите два слова: ";
            std::cin >> word1 >> word2;
            char last_letter = word2[word2.size() - 1];
            int count = 0;
            for (int i = 0; i < word1.length(); i++) {
                if (word1[i] == last_letter) {
                    count++;
                }
            }
            std::cout << "в первом слове встречается последняя буква второго слова " << count << " раз(а)." << std::endl;
            break;
        }
        

        case 2: {
            //Task 2
            //Пользователь вводит некоторый текст.
            //Образовать из него новый, в который включить информацию, заключенную между пробелом и запятой.
            std::string text;
            std::cout << "Введите текст: ";
            std::getline(std::cin, text);
            std::string result;
            bool inside = false;
            for (int i = 0; i < text.length(); i++) {
                if (text[i] == ' ' && !inside) {
                    inside = true;
                }
                else if (text[i] == ',' && inside) {
                    inside = false;
                }
                else if (inside) {
                    result += text[i];
                }
            }
            std::cout << "текст между пробелом и запятой: " << result << std::endl;
            break;
        }
        case 3: {
            //Task 3
            // Дан текстовый файл. Запишите в другой файл содержимое исходного файла, нумеруя каждую строку
            std::ifstream inputfile("input.txt");
            if (!inputfile.is_open()) {
                std::cout << "ошибка открытия input.txt" << std::endl;
                return 1;
            }
            std::ofstream outputfile("output.txt");
            if (!outputfile.is_open()) {
                std::cout << "ошибка открытия output.txt" << std::endl;
                return 1;
            }
            std::string line;
            int col = 1;
            while (std::getline(inputfile, line)) {
                outputfile << col << " : " << line << std::endl;
                std::cout << col << " : " << line << std::endl;
                col++;
            }
            inputfile.close();
            outputfile.close();
            std::cout << "нумерация строк в output.txt." << std::endl;
            break;
        }  
         

        case 4: {
            //Task 4
            std::vector<float> arr;
            for (int i = 0; i < 25; ++i) {
                arr.push_back(i);
            }
            std::cout << "до возведения в квадрат:" << std::endl;
            printVector(arr);
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] *= arr[i];
            }
            std::cout << "после возведения в квадрат:" << std::endl;
            printVector(arr);
            if (arr.size() > 5) {
                arr.erase(arr.begin() + 5);
            }
            std::cout << std::endl << "после удаления элемента с индексом 5:" << std::endl;
            printVector(arr);
            break;
        }
        case 5: {
            //Task 5
            std::vector<Card> library;
            library.push_back(Card("Война и мир", "Толстой", 3));
            library.push_back(Card("преступление и наказание", "достоевский", 5));
            library.push_back(Card("1984", "оруэлл", 2));
            library.push_back(Card("мастер и маргарита", "булгаков", 4));
            library.push_back(Card("инженерная графика", "горячкина", 1));
            std::cout << "библиотека:" << std::endl;
            for (int i = 0; i < library.size(); ++i) {
                library[i].print();
            }
            std::string input_au;
            std::cout << "введите имя автора: ";
            std::getline(std::cin, input_au);
            bool found = false;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].get_author() == input_au) {
                    library[i].print();
                    found = true;
                }
            }
            if (!found) {
                std::cout << "у меня нет такой книги" << std::endl;
            }

            break;
        }
        case 6: {
            //Task 6 
            // Описать функцию, которая печатает Yes или No в зависимости от того, 
            // содержится ли заданное целое число x в заданном контейнере-списке list<int>.
            std::list<int> my_list = { 1, 2, 3, 4, 5 };
            int x;
            std::cout << "введите целое число: ";
            std::cin >> x;
            printList(my_list, x);

            break;
        }
        case 7: {
            //Task 7
            //вычислить сумму всех комплексных чисел
            std::list<Complex> complex_arr = {Complex(-1.2, 6.3), Complex(4.0, 0.7), Complex(7.2, -0.8), 
                Complex(5.3, 3.0), Complex(-4.9, 6.6), Complex(-9.3, 0.2)
            };
            std::cout << "мой cписок компл чисел:" << std::endl;
            std::list<Complex>::iterator iter;
            for (iter = complex_arr.begin(); iter != complex_arr.end(); ++iter) {
                iter -> print();
            }
            Complex sum(0, 0);
            std::list<Complex>::iterator iter2;
            for (iter2 = complex_arr.begin(); iter2 != complex_arr.end(); ++iter2) {
                sum = sum + *iter2;
            }
            std::cout << "Сумма всех комплексных чисел: ";
            sum.print();
            break;
        }
        case 8: {
            //Task 8
            //Создайте отображение map<int, int> и занесите в него пары 1 - 10, 2 - 20, 3 - 30, ..., 
            //20 - 200. 
            //Выведите содержимое отображения на экран.Удалить пары с нечетными ключами и 
            //снова распечатайте отображение.

            std::map<int, int> my_map;
            for (int i = 1; i <= 20; ++i) {
                my_map[i] = i * 10;
            }
            std::cout << "до удаления пар с нечетными ключами:" << std::endl;
            std::map<int, int>::iterator it;
            for (it = my_map.begin(); it != my_map.end(); it++) {
                std::cout << it->first << " - " << it->second << std::endl;
            }
            
            for (it = my_map.begin(); it != my_map.end(); it++) {
                if (it->first % 2 != 0) {
                    it = my_map.erase(it);
                }
            }

            // Вывод содержимого отображения после удаления пар с нечетными ключами
            std::cout << "содержимое отображения после удаления пар с нечетными ключами:" << std::endl;
            for (it = my_map.begin(); it != my_map.end(); it++) {
                std::cout << it->first << " - " << it->second << std::endl;
            }

            break;
        }
        case 9: {
            //Task 9
            std::map<std::string, int> salary_map = {
                {"Ivanov", 45500},
                {"Petrov", 37000},
                {"Sidorov", 245000},
                {"Petrenko", 65000},
                {"Tovalds", 91200},
                {"Popov", 54600},
                {"Andrienko", 35000}
            };
            //принадлежность сотрудников к отделам
            std::map<std::string, std::string> department_map = {
                {"Ivanov", "Research"},
                {"Petrov", "Research"},
                {"Sidorov", "Management"},
                {"Petrenko", "Management"},
                {"Tovalds", "Development"},
                {"Popov", "Research"},
                {"Andrienko", "Sales"}
            };

            int total_salary = 0;
            //по отделам
            std::map<std::string, int> department_salary;
            std::map<std::string, int>::iterator it;
            for (it = salary_map.begin(); it != salary_map.end(); ++it) {
                total_salary += it->second; // прибавляем зарплату к общему фонду
                const std::string& name = it->first;
                const std::string& department = department_map[name];
                department_salary[department] += it->second;
            }

            std::cout << "Research " << department_salary["Research"] << std::endl;
            std::cout << "Management " << department_salary["Management"] << std::endl;
            std::cout << "Development " << department_salary["Development"] << std::endl;
            std::cout << "Sales " << department_salary["Sales"] << std::endl;
            std::cout << "Overall " << total_salary << std::endl;
            break;
        }
        default: {
            std::cout << "неверный номер задания" << std::endl;
            break;
        }

        }
    }
    return 0;
}