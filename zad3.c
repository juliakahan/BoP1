#include <stdio.h>
//zmienjszyc wszytana liczbe zmiennoprzecinkowa o jej czesc niecalkowita,
// nastepnie wyswietlic jej postinkrementacje i preinkrementacje

int main() {
    float num;
    scanf("%f\n", &num);
    int c = num;
    printf("%d\n", c++);
    printf("%d\n", ++c);

    return 0;
}
