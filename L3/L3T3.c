/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 4.2.2023
    Tiedosto: L3T3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LENGTH_FILE_NAME    30

// returns new sum
int addToTotal(int oldSum, char *fileName);
// reads file and prints all additions made by user (found in given file)
void printHistory(char *fileName);

int main(void){
    int sum = 0, choise;
    char fileName[MAX_LENGTH_FILE_NAME];

    printf("Anna kokonaisluku: ");
    scanf("%d", &sum);
    getchar();
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);
    getchar();

    do {
        printf("\nValitse haluamasi toiminto:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Tulosta tulokset\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &choise);

        switch(choise) {
            case 1:
                sum = addToTotal(sum, fileName);
                break;
            case 2:
                printHistory(fileName);
                break;
            case 0:
                printf("\nLopetetaan.\n");
                break;
            default:
                printf("\nTuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while(choise != 0);

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

// returns new sum
int addToTotal(int oldSum, char *fileName) {
    int sum = oldSum;
    int newNumber;
    FILE *fp = NULL;

    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &newNumber);
    getchar();
    sum += newNumber;
    printf("%d+%d=%d\n", oldSum, newNumber, sum);

    if ((fp = fopen(fileName, "a")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(fp, "%d+%d=%d\n", oldSum, newNumber, sum);

    fclose(fp);
    return sum;
}

// reads file and prints all additions made by user (found in given file)
void printHistory(char *fileName) {
    char line[MAX_LENGTH_FILE_NAME];
    FILE *fp = NULL;
    if ((fp = fopen(fileName, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("\nTiedostossa oleva laskuhistoria:\n");
    while(fgets(line, MAX_LENGTH_FILE_NAME, fp) != NULL) {
        printf("%s", line);
    }
    printf("Tiedosto '%s' luettu ja tulostettu.\n", fileName);

    fclose(fp);
    return;
}