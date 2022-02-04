#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int count, k, tmp;
	int a[500];

	scanf("%d %d", &count, &k);

	for (int i = 0; i < count; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < count; i++) {
		tmp = i;
		for (int j = i + 1; j < count; j++) {
			if (a[tmp] > a[j])
				tmp = j;
		}
		swap(&a[i], &a[tmp]);
	}

	printf("%d", a[k-1]);

	return 0;
}