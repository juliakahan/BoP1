#include <stdio.h>


int main() {
    int a = 31;
    short int b = 12;
    int wynik = 0;

    wynik = a & b;
    printf("bitowy & : ");
    printf("%d\n", wynik);

    wynik = a && b;
    printf("Logiczny && : ");
    printf("%d", wynik);

    return 0;
}

