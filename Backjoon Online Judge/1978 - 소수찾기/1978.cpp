#include <iostream>

int main(void) {
	int n = 0;
	int count = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;

		if (temp == 2) {
			count++;
			continue;
		}

		for (int j = 2; j < temp; j++) {
			if (temp % j == 0)
				break;

			if (j == temp-1)
				count++;
		}
	}

	std::cout << count;

	return 0;
}