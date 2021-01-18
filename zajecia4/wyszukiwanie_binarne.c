//Wykorzystać fakt, że tablica jest uporządkowana i odpowiedzieć na pytanie czy dana liczba znajduje się w tablicy
#include <stdio.h>

int main() {
    int num;
    scanf("%d",&num);
    int tab[]={1,2,3,4,5,6,7,8,8,9};
    int l=0, r= sizeof(tab)/sizeof(tab[0]);
    int mid;
    while (l<=r){

        mid=(l+r)/2;

        if(tab[mid]==num)
        {
            printf("udalo sie");
            return 0;
        }
        if(tab[mid]>num){
            r=mid-1;

        }
        else
        {
            l=mid+1;

        }

    }

    printf("Nie udalo sie");

    return 0;
}
