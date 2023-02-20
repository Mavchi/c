#include <stdio.h>
#define MAX_LENGTH 30

int main(void) {
    char lemmikinNimi[MAX_LENGTH];
    char lemmikinRotu[MAX_LENGTH];
    int lemmikinIka;
    float lemmikinPaino;

    printf("Anna lemmikin nimi: ");
    scanf("%s", lemmikinNimi);
    getchar();

    printf("Anna lemmikin rotu: ");
    scanf("%s", lemmikinRotu);
    getchar();

    printf("Anna lemmikin ikä: ");
    scanf("%d", &lemmikinIka);
    getchar();

    printf("Anna lemmikin paino: ");
    scanf("%f", &lemmikinPaino);
    getchar();

    printf("Lemmikin nimi on %s ja rotu on %s.\n", lemmikinNimi, lemmikinRotu);
    printf("Sen ikä on %d vuotta ja paino %.1f kg.\n", lemmikinIka, lemmikinPaino);

    return 0;
}