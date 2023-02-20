/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 12.2.2023
    Tiedosto: L4T5.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(char *s, int index, int length);
void printStringReverse(char *s, int index);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Et antanut merkkijonoa parametrinä, lopetetaan\n");
        exit(0);
    }

    int input = -1;
    while(input != 0) {
        printf("Valitse haluamasi toiminto:\n");
        printf("1) Tulosta merkkijono\n");
        printf("2) Tulosta merkkijono takaperin\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &input);
        getchar();

        switch (input) {
            case 1: // tulosta merkkijono
                printf("\n");
                printString(argv[1], 0, strlen(argv[1]));
                printf("\n");
                break;
            case 2: // tulosta merkkijono käänteisessä järjestyksessä
                printf("\n");
                printStringReverse(argv[1], strlen(argv[1])-1);
                printf("\n");
                break;
            case 0:
                printf("Lopetetaan.\n");
                break;
            default:
                printf("Väärä syöte.\n");
                break;
        }
    }

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

void printString(char *s, int index, int length) {
    if (index == length) {
        return;
    }
    printf("%c\n", s[index]);
    printString(s, index+1, length);
    return;
}


void printStringReverse(char *s, int index) {
    if (index == -1) {
        return;
    }
    printf("%c\n", s[index]);
    printStringReverse(s, index-1);
    return;
}