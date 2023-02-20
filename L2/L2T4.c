#include <stdio.h>

#define PI 3.141

int main(void){
    float r;
    printf("Anna ympyrän säde: ");
    scanf("%f", &r);

    int choise;
    printf("\nValikko:\n");
    printf("1) Laske ympyrän kehän pituus\n");
    printf("2) Laske ympyrän pinta-ala\n");
    printf("Valitse: ");
    scanf("%d", &choise);

    switch (choise) {
        case 1:
            printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.\n", r, 2*PI*r);
            break;
        case 2:
            printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.\n", r, PI*r*r);
            break;
        default:
            printf("Tuntematon valinta.\n");
            break;
    }

    return 0;
}