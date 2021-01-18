//Napisz program, ktory wyswietli wszystkie liczby podzielne przez 6 mniejsze niz 100.
#include <stdio.h>

int main() {
    for (int i = 1; i < 100; ++i) {
        if ((i % 3 == 0) && (i % 2 == 0)) {
            printf("%d\n", i);
        }
    }

    return 0;
}