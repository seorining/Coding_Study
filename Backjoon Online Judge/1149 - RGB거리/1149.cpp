#include <iostream>

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int main(void) {
	int n;

	std::cin >> n;

	int** house = new int* [n];

	for (int i = 0; i < n; i++) {
		house[i] = new int[3];
		for (int j = 0; j < 3; j++)
			std::cin >> house[i][j];
	}

	int** colored_house = new int* [n+1];
	for (int i = 0; i < n+1; i++)
		colored_house[i] = new int[3];
	colored_house[0][0] = 0;
	colored_house[0][1] = 0;
	colored_house[0][2] = 0;

	for (int i = 1; i < n+1; i++) {
		//R로 칠할 경우
		colored_house[i][0] = min(colored_house[i - 1][1], colored_house[i - 1][2]) + house[i-1][0];
		//G로 칠할 경우
		colored_house[i][1] = min(colored_house[i - 1][0], colored_house[i - 1][2]) + house[i-1][1];
		//B로 칠할 경우
		colored_house[i][2] = min(colored_house[i - 1][0], colored_house[i - 1][1]) + house[i-1][2];
	}

	std::cout << min(colored_house[n][0], (min(colored_house[n][1], colored_house[n][2])));
	
	for (int i = 0; i < n; i++)
		delete[] house[i];
	for (int i = 0; i < n+1; i++)
		delete[] colored_house[i];
	delete[] house;
	delete[] colored_house;

	return 0;
}