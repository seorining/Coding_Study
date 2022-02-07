#include <iostream>

int plus(int n) {
	if (n == 0)
		return 0;

	return n + plus(n-1);
}

int main(void) {
	int n = 0;
	int sum = 0;

	std::cin >> n;

	std::cout << plus(n);

	return 0;
}