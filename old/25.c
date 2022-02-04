#include <stdio.h>

int main(void) {
	int n, count = 0, countf = 0;
	int* num;

	scanf("%d", &n);

	num = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 2; j < num[i]; j++) {
			if (num[i] % j == 0) {
				countf = 0;
				break;
			}
			else
				countf++;
		}
		if (countf > 0) {
			countf = 0;
			count++;
		}
		if (num[i] == 2)
			count++;
	}

	printf("%d", count);

	return 0;
}