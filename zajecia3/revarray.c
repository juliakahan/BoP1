//
// Proszę o zdefiniowanie tablicy trzech liczb i wyświetlenie ich w odwrotnej kolejności:
//

#include <stdio.h>

int main()
{   int N = 3;
    int tab[] = {1,2,3};
    for(int i = 2; i >= 0; i--)
    {
        printf("%d\n", tab[i]);
    }
    return 0;
}
