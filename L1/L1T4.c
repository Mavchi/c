#include <stdio.h>

int main(void){
    char c;
    printf("Anna merkki: ");
    c = getchar();
    printf("Annoit merkin '%c'.\n", c);

    char merkkijono[20];
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    scanf("%s", merkkijono);
    printf("Annoit merkkijonon '%s'.\n", merkkijono);

    return 0;
}