#include <iostream>

int main(void) {
	double a, b = 0.0;

	std::cout << std::fixed;
	std::cout.precision(10);

	std::cin >> a >> b;
	std::cout << a / b;

	return 0;
}