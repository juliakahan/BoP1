// Wczytać wyraz z klawiatury do tablicy znaków i sprawdzić, czy zaczyna się od pierwszej litery naszego imienia:

#include <stdio.h>
#include <string.h>

#include <string.h>
#include <stdio.h>

int main()
{

    char word;
    scanf("%c", &word);
    if(word == 'J' || word == 'j')
    {
        printf("zaczyna sie");

    }
    else
    {
        printf("Nie zaczyna sie");
    }



    return 0;
}
