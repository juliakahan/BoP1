//Wyświetl wartość logiczną, jeśli wśród liczb tablicy znajduje się zadana liczba (przeszukiwanie tablicy):

#include <stdio.h>

int main()
{
    int tab[]={1,3,4,2,10,67,26,6,5};
    int bool=0;
    int szukana;
    scanf("%d", &szukana);
    for(int i=0; i<sizeof(tab)/sizeof(tab[0]); ++i)
    {
        if(tab[i]==szukana)
        {
            bool=1;
            printf("%d", bool);
            return 0;
        }
    }
return 0;

}

