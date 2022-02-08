#include <iostream>

int main(void) {
	int score[5];
	int sum = 0;

	for (int i = 0; i < 5; i++)
		std::cin >> score[i];

	for (int i = 0; i < 5; i++) {
		if (score[i] < 40)
			score[i] = 40;
		sum = sum + score[i];
	}

	std::cout << sum / 5;

	return 0;
}