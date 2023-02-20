#include <stdio.h>
int main(void)
{
    /* Määritellään kaksi kokonaislukumuuttujaa */
    int iLuku1 = 1, iLuku2 = 2;
    /* Määritellään osoitinmuuttuja, joka osoittaa kokonaislukuun */
    int *pLuku;
    /* Asetetaan osoitinmuuttuja osoittamaan muuttujan iLuku1 osoitteeseen */
    pLuku = &iLuku1;
    printf("Muuttujan iLuku1 arvo %d ja se on muistipaikassa %p.\n", iLuku1, &iLuku1);
    printf("Osoitin pLuku osoittaa muistipaikkaan %p, jossa on arvo %d.\n", pLuku, *pLuku);
    /* Aseta osoitinmuuttuja osoittamaan muuttujan iLuku2 osoitteeseen */
    pLuku = &iLuku2;
    printf("Muuttujan iLuku2 arvo %d ja se on muistipaikassa %p.\n", iLuku2, &iLuku2);
    printf("Osoitin pLuku osoittaa muistipaikkaan %p, jossa on arvo %d.\n", pLuku, *pLuku);
    return (0);
}

