#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort(char p[], int len) {
	int tem;

	for (int i = 0; i < len - 1; i++) {
		tem = i;
		for (int j = i + 1; j < len; j++) {
			if (p[tem] < p[j])
				tem = j;
		}
		swap(&p[i], &p[tem]);
	}





}

int main(void) {
	char num[1000];
	scanf("%s", num);

	int len = strlen(num);
	insert_sort(num, len);

	for (int i = 0; i < len; i++)
		printf("%c", num[i]);


	return 0;
}