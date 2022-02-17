#include <stdio.h>
#include <iostream>

int compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n, k = 0;

    scanf("%d %d", &n, &k);

    int *array = new int[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    qsort(array, n, sizeof(int), compare);

    printf("%d", array[k - 1]);

    return 0;
}