#include <iostream>

int main(void) {
	int num[8] = { 0 , };
	int count = 0;

	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
		std::cin >> num[i];

	for (int i = 0; i < sizeof(num) / sizeof(int); i++) {
		if (num[i] == i+1)
			count++;
		if (num[i] == 8 - i)
			count--;
	}

	if (count == 8)
		std::cout << "ascending";
	else if (count == -8)
		std::cout << "descending";
	else
		std::cout << "mixed";

	return 0;
}