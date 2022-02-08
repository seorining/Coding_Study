#include <iostream>

int compare(const void* e1, const void* e2) {
	if (*(int*)e1 == (*(int*)e2))
		return 0;
	else if (*(int*)e1 > (*(int*)e2))
		return -1;
	else
		return 1;
}

int main(void) {
	int n;
	int count = 0;

	std::cin >> n;

	int num = n;

	while (true) {
		n = n / 10;
		count++;
		if (n == 0)
			break;
	}

	int* num_array = new int[count];

	for (int i = 0; i < count; i++) {
		num_array[i] = num % 10;
		num = num / 10;
	}
	
	qsort(num_array, count, sizeof(int), compare);

	for (int i = 0; i < count; i++)
		std::cout << num_array[i];

	return 0;
}