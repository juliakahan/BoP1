//
// Proszę zrobić programik obliczający pierwiastki równania kwadratowego:
//
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, delta=0;
    printf("podaj wspolczynniki");
    scanf("%d" "%d" "%d", &a, &b, &c);
    delta = b*b - 4*a*c;
    if(delta < 0)
    {
        printf("równianie nie ma pierwiastków rzeczywistych");
        return 0;
    }

    if (delta == 0)
    {
        printf("rownanie posiada jeden pierwiastek: ");
        double x0=b/2*a;
        printf("%d\n", x0);
        return 0;
    }

    else
    {
        double x1=(b+sqrt(delta))/2*a;
        double x2=(b-sqrt(delta))/2*a;
        printf("rownianie ma dwa pierwiastki kwasratowe: ");
        printf("%d\n",x1);
        printf("%d", x2);
    }

    return 0;

}

