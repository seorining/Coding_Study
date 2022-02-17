#include <iostream>

int main(void) {
	int n;
	std::cin >> n;

	int *score = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> score[i];

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (score[i] > max)
			max = score[i];
	}

	double* new_score = new double[n];
	double sum = 0;
	for (int i = 0; i < n; i++) {
		new_score[i] = (double)score[i] / max * 100;
		sum += new_score[i];
	}

	std::cout << sum / n;
	
	return 0;
}