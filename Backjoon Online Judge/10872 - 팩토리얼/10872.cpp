#include <iostream>

int fac(int n) {
	if (n == 1 || n == 0)
		return 1;

	return n * fac(n - 1);
}


int main(void) {
	int n;
	std::cin >> n;

	std::cout << fac(n);

	return 0;
}