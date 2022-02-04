#include <stdio.h>

int main(void) {
	int score[5];
	int sum = 0;

	for(int i = 0 ; i < 5 ; i++)
		scanf("%d", &score[i]);

	for (int i = 0; i < 5; i++) {
		if (score[i] < 40)
			sum = sum + 40;
		else
			sum = sum + score[i];
	}

	printf("%d", sum / 5);


	return 0;
}