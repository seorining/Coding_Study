#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {
	char str[1000001] = { 0, };
	char* ptr;
	int count = 0;

	scanf("%[^\n]s", str);

	ptr = strtok(str, " ");
	if (ptr != NULL)
		count++;

	while (true) {
		ptr = strtok(NULL, " ");
		if (ptr == NULL)
			break;
		count++;
	}

	printf("%d", count);

	return 0;
}