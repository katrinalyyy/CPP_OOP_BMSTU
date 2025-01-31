#include "LabaEight/LabaEight.h"

int main() {
    //setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int x;
    while (1) {
        std::cout << "������� ����� �������: ";
        std::cin >> x;
        std::cin.ignore(); // ������� ������� ����� �� ������� ����� ������
        switch (x) {
        case 1: {
            // Task 1
            //������������ ������ ��� �����(��� ����������).
            //������� ��� � ������ ����� ����������� ��������� ����� ������� �����.
            std::string word1, word2;
            std::cout << "������� ��� �����: ";
            std::cin >> word1 >> word2;
            char last_letter = word2[word2.size() - 1];
            int count = 0;
            for (int i = 0; i < word1.length(); i++) {
                if (word1[i] == last_letter) {
                    count++;
                }
            }
            std::cout << "� ������ ����� ����������� ��������� ����� ������� ����� " << count << " ���(�)." << std::endl;
            break;
        }
        

        case 2: {
            //Task 2
            //������������ ������ ��������� �����.
            //���������� �� ���� �����, � ������� �������� ����������, ����������� ����� �������� � �������.
            std::string text;
            std::cout << "������� �����: ";
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
            std::cout << "����� ����� �������� � �������: " << result << std::endl;
            break;
        }
        case 3: {
            //Task 3
            // ��� ��������� ����. �������� � ������ ���� ���������� ��������� �����, ������� ������ ������
            std::ifstream inputfile("input.txt");
            if (!inputfile.is_open()) {
                std::cout << "������ �������� input.txt" << std::endl;
                return 1;
            }
            std::ofstream outputfile("output.txt");
            if (!outputfile.is_open()) {
                std::cout << "������ �������� output.txt" << std::endl;
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
            std::cout << "��������� ����� � output.txt." << std::endl;
            break;
        }  
         

        case 4: {
            //Task 4
            std::vector<float> arr;
            for (int i = 0; i < 25; ++i) {
                arr.push_back(i);
            }
            std::cout << "�� ���������� � �������:" << std::endl;
            printVector(arr);
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] *= arr[i];
            }
            std::cout << "����� ���������� � �������:" << std::endl;
            printVector(arr);
            if (arr.size() > 5) {
                arr.erase(arr.begin() + 5);
            }
            std::cout << std::endl << "����� �������� �������� � �������� 5:" << std::endl;
            printVector(arr);
            break;
        }
        case 5: {
            //Task 5
            std::vector<Card> library;
            library.push_back(Card("����� � ���", "�������", 3));
            library.push_back(Card("������������ � ���������", "�����������", 5));
            library.push_back(Card("1984", "������", 2));
            library.push_back(Card("������ � ���������", "��������", 4));
            library.push_back(Card("���������� �������", "���������", 1));
            std::cout << "����������:" << std::endl;
            for (int i = 0; i < library.size(); ++i) {
                library[i].print();
            }
            std::string input_au;
            std::cout << "������� ��� ������: ";
            std::getline(std::cin, input_au);
            bool found = false;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].get_author() == input_au) {
                    library[i].print();
                    found = true;
                }
            }
            if (!found) {
                std::cout << "� ���� ��� ����� �����" << std::endl;
            }

            break;
        }
        case 6: {
            //Task 6 
            // ������� �������, ������� �������� Yes ��� No � ����������� �� ����, 
            // ���������� �� �������� ����� ����� x � �������� ����������-������ list<int>.
            std::list<int> my_list = { 1, 2, 3, 4, 5 };
            int x;
            std::cout << "������� ����� �����: ";
            std::cin >> x;
            printList(my_list, x);

            break;
        }
        case 7: {
            //Task 7
            //��������� ����� ���� ����������� �����
            std::list<Complex> complex_arr = {Complex(-1.2, 6.3), Complex(4.0, 0.7), Complex(7.2, -0.8), 
                Complex(5.3, 3.0), Complex(-4.9, 6.6), Complex(-9.3, 0.2)
            };
            std::cout << "��� c����� ����� �����:" << std::endl;
            std::list<Complex>::iterator iter;
            for (iter = complex_arr.begin(); iter != complex_arr.end(); ++iter) {
                iter -> print();
            }
            Complex sum(0, 0);
            std::list<Complex>::iterator iter2;
            for (iter2 = complex_arr.begin(); iter2 != complex_arr.end(); ++iter2) {
                sum = sum + *iter2;
            }
            std::cout << "����� ���� ����������� �����: ";
            sum.print();
            break;
        }
        case 8: {
            //Task 8
            //�������� ����������� map<int, int> � �������� � ���� ���� 1 - 10, 2 - 20, 3 - 30, ..., 
            //20 - 200. 
            //�������� ���������� ����������� �� �����.������� ���� � ��������� ������� � 
            //����� ������������ �����������.

            std::map<int, int> my_map;
            for (int i = 1; i <= 20; ++i) {
                my_map[i] = i * 10;
            }
            std::cout << "�� �������� ��� � ��������� �������:" << std::endl;
            std::map<int, int>::iterator it;
            for (it = my_map.begin(); it != my_map.end(); it++) {
                std::cout << it->first << " - " << it->second << std::endl;
            }
            
            for (it = my_map.begin(); it != my_map.end(); it++) {
                if (it->first % 2 != 0) {
                    it = my_map.erase(it);
                }
            }

            // ����� ����������� ����������� ����� �������� ��� � ��������� �������
            std::cout << "���������� ����������� ����� �������� ��� � ��������� �������:" << std::endl;
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
            //�������������� ����������� � �������
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
            //�� �������
            std::map<std::string, int> department_salary;
            std::map<std::string, int>::iterator it;
            for (it = salary_map.begin(); it != salary_map.end(); ++it) {
                total_salary += it->second; // ���������� �������� � ������ �����
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
            std::cout << "�������� ����� �������" << std::endl;
            break;
        }

        }
    }
    return 0;
}