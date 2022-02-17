#include <iostream>

int main(void)
{
    int k;
    std::cin >> k;

    for (int i = 0; i < k; i++)
        std::cout << "1";
    for (int i = 0; i < k - 1; i++)
        std::cout << "0";

    return 0;
}