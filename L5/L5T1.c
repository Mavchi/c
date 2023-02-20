/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 14.2.2023
    Tiedosto: L5T1.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH  30

char *reserveMemoryForString();
void getInput(char *pString);

int main(void) {
    char *pString = reserveMemoryForString();
    printf("Muisti varattu %d merkille.\n", MAX_LENGTH);

    getInput(pString);

    printf("Annoit merkkijonon '%s'.\n", pString);
    free(pString);
    printf("Muisti vapautettu.\n");
    pString = NULL;
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}

char *reserveMemoryForString() {
    char *ptr = NULL;
    if ((ptr = (char *)malloc(sizeof(char)*MAX_LENGTH)) == NULL) {
        perror("Ei voitu varata muistia taulukollemme");
        exit(0);
    }
    return ptr;
}

void getInput(char *pString) {
    printf("Anna merkkijono: ");
    fgets(pString, MAX_LENGTH, stdin);
    pString[strlen(pString)-1] = '\0';
}