//przycinająca tekst do określonej długości (w razie gdy tekst jest za krótki nic nie robiąca):



#include <stdio.h>
void ucinanie (char tekst[], int N, int n)
{
    if (N>n)
    {
        tekst[n]='\n';
        for(int i=0; i<n; ++i)
        {
            printf("%c", tekst[i]);
        }
    }

}

int main() {

    char tekst[100]="Ciezko powiedziec";
    ucinanie (tekst, 100, 3);



    return 0;

}