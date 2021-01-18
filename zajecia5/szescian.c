#include <stdio.h>
int szecian(int liczba)
{
    return liczba*liczba*liczba;
}

int main()
{
    int licz;
    scanf("%d", &licz);
    printf("%d\n", szecian(licz));
    return 0;
}