#include <iostream>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int num[3];

	std::cin >> num[0] >> num[1] >> num[2];

	for (int i = 0; i < 2; i++) {
		int index = i;
		for (int j = i + 1; j < 3; j++) {
			if (num[j] < num[index])
				index = j;
		}
		swap(&num[index], &num[i]);
	}

	std::cout << num[1];
	
	return 0;
}