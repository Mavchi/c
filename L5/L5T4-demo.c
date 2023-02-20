/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 16.2.2023
    Tiedosto: L5T3.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 30

typedef struct data
{
    char s[MAX_LENGTH];
    int sumIndexChars;
    int sumIndexNumbers;
} DATA;

// Tallentaa käyttäjältä saatua tiedoston nimeä parametrina saatuun merkkitaulukkoon
void getFileName(char *name);
// Tulostaa valikon ja palauttaa käyttäjän syötettä tarkastaen oikeellisuutta
int printMenu();
// Luetaan tiedostosta tarpeellinen tieto
DATA *readFile(char *fileName, DATA *data, int *lastIndex);
// reserve memory to add new member
DATA *reserveMemory(DATA *data, int *lastIndex);
// palauttaa merkkijonoen summaa (int)
int sumOfIndexes(char *s);
// tulostetaan tietovirtaan (stdout tai tiedosto)
void writeStream(FILE *fp, DATA *data, int length);

int main(void)
{
    char fileName[MAX_LENGTH] = "";
    DATA *data = NULL;
    int length = 0;

    int input = -1;
    while (input != 0)
    {
        input = printMenu();

        switch (input)
        {
        case 1: // lue tiedosto
            printf("\nAnna luettavan tiedoston nimi: ");
            getFileName(fileName);
            data = readFile(fileName, data, &length);
            printf("\n");
            break;
        case 2: // näyttää summat
            if (data == NULL)
            {
                printf("\nEi analysoitavaa, lue tiedosto ennen analyysia.\n\n");
                continue;
            }

            printf("\nSummat laskettu %d merkkijonolle.\n\n", length - 1);
            break;
        case 3: // kirjoita tiedostoon
            if (length == 0)
            {
                printf("\nEi kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n\n");
                continue;
            }

            printf("\nAnna kirjoitettavan tiedoston nimi: ");
            getFileName(fileName);

            FILE *fp = NULL;
            if ((fp = fopen(fileName, "w")) == NULL)
            {
                perror("Ei voitu avata tiedostoa, lopetetaan");
                exit(0);
            }
            writeStream(fp, data, length);
            printf("Tiedosto '%s' kirjoitettu.\n\n", fileName);
            fclose(fp);
            break;
        case 0:
            if (data != NULL)
            {
                free(data);
            }
            data = NULL;
            printf("\nMuisti vapautettu.\n");
            printf("Lopetaan.\n");
            break;
        default:
            printf("Ei tuettu toiminto\n");
            break;
        }
    }

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

// Tallentaa käyttäjältä saatua tiedoston nimeä parametrina saatuun merkkitaulukkoon
void getFileName(char *name)
{
    scanf("%s", name);
    getchar();
}

// Tulostaa valikon ja palauttaa käyttäjän syötettä tarkastaen oikeellisuutta
int printMenu()
{
    int input = -1;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Laske merkkijonojen summa\n");
    printf("3) Kirjoita tiedosto\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");

    scanf("%d", &input);
    getchar();
    return input;
}

// Luetaan tiedostosta tarpeellinen tieto
DATA *readFile(char *fileName, DATA *data, int *pLength)
{
    FILE *fp = NULL;
    char *p1 = NULL, *p2 = NULL;

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        perror("Ei voitu avata tiedostoa, lopetetaan");
        exit(0);
    }
    printf("Tiedosto '%s' luettu.\n", fileName);

    char line[MAX_LENGTH] = "";
    while (fgets(line, MAX_LENGTH, fp) != NULL)
    {
        if ((p1 = strtok(line, ";")) == NULL)
        {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", line);
            exit(0);
        }
        if ((p2 = strtok(NULL, "\n")) == NULL)
        {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", line);
            exit(0);
        }

        /*
        if (strcmp(p1, "Nimi") == 0) {
            continue;
        }
    */
        ++(*pLength);
        // printf("%d new length", *pLength);
        data = reserveMemory(data, pLength);
        sprintf(data[*pLength - 1].s, "%s;%s\n", p1, p2);
        // strcpy(data[*pLength-1].s, p1);
        data[*pLength - 1].sumIndexChars = sumOfIndexes(p1);
        data[*pLength - 1].sumIndexNumbers = sumOfIndexes(p2);
    }
    /*
        for(int i=0; i<*pLength; i++) {
            printf("%s\n", data[i].s);
        }
        */
    fclose(fp);
    return data;
}

// reserve memory to add new member
DATA *reserveMemory(DATA *data, int *pLength)
{
    DATA *newArray = (DATA *)realloc(data, sizeof(DATA) * (*pLength));
    return newArray;
}

// palauttaa merkkijonoen summaa (int)
int sumOfIndexes(char *s)
{
    int sum = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        sum += (int)s[i];
    }
    return sum;
}

// tulostetaan tietovirtaan (stdout tai tiedosto)
void writeStream(FILE *fp, DATA *data, int length)
{
    printf("Tiedostoon kirjoitetaan seuraavat arvot:\n");
    for (int i = 0; i < length; i++)
    {
        fprintf(fp, "%s", data[i].s);
        printf("%s", data[i].s);
        if (i == length-1) {
            printf("\n");
        }
    }

    return;
}