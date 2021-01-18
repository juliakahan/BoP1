//Funkcja, która zmienia tekst na duże/małe litery
//- Funkcja, która zmienia małe na duże i duże na małe litery:

#include <stdio.h>
#include <stdlib.h>

void zmiana(char tekst[], const int N)
{

    for(int i=0; i<N; ++i)
    {
        if (tekst[i] >= 'A' && tekst[i] <= 'Z') printf("%c", tekst[i]+32);

        else if(tekst[i] >= 'a' && tekst[i] <= 'z') printf("%c", tekst[i]-32);


        else printf("%c", tekst[i]);

    }
}
int main() {
    char tekst[100]="Czy byt konceptualny IstniEje?";
    zmiana(tekst, 100);

    return 0;

}