#include "labaPyat/myset.h"
#include "labaPyat/myvector.h"

int main() {
	setlocale(LC_ALL, "Russian");
	char test[20];
	std::cin >> test;
	MyVector<char*> v(test);
	v.add_element(test);
	char test1[20];
	std::cin >> test1;
	v.add_element(test1);
	std::cout << "Вектор v: " << v << '\n';
	v.add_element(test);

	std::cout << "Вектор v: " << v << '\n';
	MyVector<char*> v1 = v;
	std::cout << "Вектор v1: " << v1 << '\n';
	std::cout << v1.get_size() << std::endl;
	std::cout << "Вектор v1: " << v1 << '\n';

	MySet<char*> s(test1), s1, s2;
	s.add_element(test);
	s.add_element(test1);
	char* str = test;
	s.add_element(str);
	std::cout << "Множество s: " << s << std::endl;
	s1.add_element(test);
	s1.add_element(test1);
	s1.add_element(test);
	std::cout << "Множество s1: " << s1 << std::endl;
	s2 = s1 - s;
	std::cout << "Множество s2 = s1 - s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s - s1;
	std::cout << "Множество s2 = s - s1: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s1 + s;
	std::cout << "Множество s2 = s1 + s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	s2 = s1 * s;
	std::cout << "Множество s2 = s1 * s: " << s2 << std::endl;
	std::cout << "Множество s1: " << s1 << std::endl;
	std::cout << "Множество s: " << s << std::endl;
	   MySet s3 = s2;
	   std::cout << "Множество s3 = s2: " << s3 << std::endl;
	   if (s3 == s2)
	     std::cout << "Множество s3 = s2\n";
	   else
	     std::cout << "Множество s3 != s2\n";
	   if (s3 == s1)
	     std::cout << "Множество s3 = s1\n";
	   else
	     std::cout << "Множество s3 != s1\n";
	   if (s1 == s3)
	     std::cout << "Множество s1 = s3\n";
	   else
	     std::cout << "Множество s1 != s3\n";

	std::string test3;
	std::cin >> test3;
	MySet<std::string> m(test3);
	std::cout << m;

	return 0;
}
