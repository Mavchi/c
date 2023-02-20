/*
    Tekijä: Aleksander Khlebnikov, 0380341
    Päivämäärä: 4.2.2023
    Tiedosto: L3T2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH_FILE_NAME 30

int fileSum(char *fName);
void fileSave(char *fName, int newNumber);

int main(void) {
    int sum;
    char fName[MAX_LENGTH_FILE_NAME];
    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    printf("Anna luettavan tiedoston nimi: ");
    fgets(fName, MAX_LENGTH_FILE_NAME, stdin);
    fName[strlen(fName)-1] = '\0';

    // lets count sum
    sum = fileSum(fName);
    printf("Tiedosto '%s' luettu, lukujen summa oli %d.\n", fName, sum);

    // lets save sum in a file fiven my user
    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    fgets(fName, MAX_LENGTH_FILE_NAME, stdin);
    fName[strlen(fName)-1] = '\0';
    fileSave(fName, sum);
    printf("Tiedosto '%s' kirjoitettu.\n", fName);

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

int fileSum(char *fName) {
    FILE *fp = NULL;
    int sum = 0, temp = 0;
    if((fp = fopen(fName, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while(1) {
        fscanf(fp, "%d", &temp);
        if (feof(fp)) {
            break;
        }
        sum += temp;
        //printf("read %d from file, sum is %d\n", temp, sum);
    }
    fclose(fp);
    return sum;
}

void fileSave(char *fName, int newNumber) {
    FILE *fp = NULL;
    if ((fp = fopen(fName, "a")) == NULL) {
        perror("Couldn't handle adding past sum");
        exit(0);
    }
    fprintf(fp, "Lukujen summa oli %d.\n", newNumber);
    fclose(fp);

    return;
}