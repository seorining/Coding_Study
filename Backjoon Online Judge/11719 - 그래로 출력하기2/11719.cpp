#include <iostream>
#include <string>

int main(void) {
	std::string str;

	while (!std::cin.eof()) {
		getline(std::cin, str);
		std::cout << str << std::endl;
	}

	return 0;
}