/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 7.2.2023
    Tiedosto: L4T3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 30

typedef struct calculation
{
    char operator;
    int sumPre;
    int sumPost;
    int number;
} CALCULATION;

// varaa muisti taulukolle
CALCULATION *reserveMemoryCalculations();
// valikko
int printMenu();
// get file name
void getFileName(char *fileName);
// returns new sum
void addToTotal(int index, CALCULATION *history);
// writes complusory caluclations to binary file specified by user (FILENAME)
void writeHistoryToTextFile(CALCULATION *history, int lastIndex, char *FILENAME);
// read old session and save into table defined in main-function, pointer is passed as first argumennt
CALCULATION *readHistoryToTextFile(int *lastIndex, char *FILENAME);
// tulostaa
void printHistory(CALCULATION *history, int index);

int main(int argc, char *argv[])
{
    CALCULATION *history = NULL;
    if ((history = reserveMemoryCalculations()) == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    char *operands = NULL;
    operands = (char *)malloc(sizeof(char)*MAX_LENGTH);
    if (operands == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    int input = -1;
    int indexLastC = 0;
    char fileName[MAX_LENGTH];
    strcpy(fileName, "");

    // varmistetaan, että käyttäjä antoi alkulukua
    if (argc != 2)
    {
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    }
    history[0].sumPre = atoi(argv[1]);
    printf("Annoit luvun %d.", history[0].sumPre);

    do
    {
        input = printMenu();

        switch (input)
        {
        case 1: // anna tiedoston nimi
            getFileName(fileName);
            break;
        case 2: // lisää lukuun
            addToTotal(indexLastC++, history);
            // considering if keeping at minimal effort is best, checking if out of size for history array
            if (indexLastC == MAX_LENGTH - 1)
            {
                printf("History array is full. Quitting\n");
                exit(0);
            }
            break;
        case 3:
            if (indexLastC == 0)
            {
                printf("\nEi kirjoitettavia tietoja.\n");
                continue;
            }
            if (strlen(fileName) == 0)
            {
                printf("\nEi tiedoston nimeä, anna kirjoitettavan tiedoston nimi ensin.\n");
                continue;
            }

            writeHistoryToTextFile(history, indexLastC, fileName);
            break;
        case 4:
            if (strlen(fileName) == 0)
            {
                printf("\nEi tiedoston nimeä, anna luettavan tiedoston nimi ensin.\n");
                continue;
            }
            free(history);
            history = readHistoryToTextFile(&indexLastC, fileName);
            break;
        case 0:
            break;
        default:
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            break;
        }
    } while (input != 0);

    free(history);
    free(operands);
    operands = NULL;
    history = NULL;
    printf("\nMuisti vapautettu.\n");
    printf("Lopetetaan.\n");

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}

// varaa muisti taulukolle
CALCULATION *reserveMemoryCalculations()
{
    CALCULATION *calculations = NULL;
    calculations = (CALCULATION *)malloc(sizeof(CALCULATION) * MAX_LENGTH);
    return calculations;
}

// valikko
int printMenu()
{
    int input = -1;
    printf("\nValitse haluamasi toiminto:\n");
    printf("1) Anna tiedoston nimi\n");
    printf("2) Lisää lukuun\n");
    printf("3) Kirjoita historia tiedostoon\n");
    printf("4) Lue historia tiedostosta\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &input);
    return input;
}

// get file name
void getFileName(char *fileName)
{
    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);
    getchar();
}

// returns new sum
void addToTotal(int index, CALCULATION *history)
{
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &history[index].number);
    getchar();

    history[index].sumPre = index == 0 ? history[index].sumPre : history[index - 1].sumPost;
    history[index].sumPost = history[index].sumPre + history[index].number;
    printf("%d+%d=%d\n", history[index].sumPre, history[index].number, history[index].sumPost);
}

// writes complusory caluclations to binary file specified by user (FILENAME)
void writeHistoryToTextFile(CALCULATION *history, int lastIndex, char *FILENAME)
{
    FILE *fp = NULL;
    printf("\n");
    printHistory(history, lastIndex);

    if ((fp = fopen(FILENAME, "a")) == NULL)
    {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    for (int i = 0; i < lastIndex; i++)
    {
        fprintf(fp, "%d+%d=%d\n", history[i].sumPre, history[i].number, history[i].sumPost);
    }
    printf("\nTiedosto '%s' kirjoitettu.\n", FILENAME);

    fclose(fp);
}

// read old session and save into table defined in main-function, pointer is passed as first argumennt
CALCULATION *readHistoryToTextFile(int *lastIndex, char *FILENAME)
{
    FILE *fp = NULL;
    CALCULATION *history = NULL;
    history = reserveMemoryCalculations();
    *lastIndex = 0;

    if ((fp = fopen(FILENAME, "r")) == NULL)
    {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("\nTiedostossa oleva laskuhistoria:\n");
    char line[MAX_LENGTH];
    strcpy(line, "");
    while (fgets(line, MAX_LENGTH, fp) != NULL)
    {
        sscanf(line, "%d+%d=%d", &history[*lastIndex].sumPre, &history[*lastIndex].number, &history[*lastIndex].sumPost);
        printf("%d+%d=%d\n", history[*lastIndex].sumPre, history[*lastIndex].number, history[*lastIndex].sumPost);
        ++(*lastIndex);
    }

    printf("Tiedosto '%s' luettu ja tulostettu.\n", FILENAME);
    fclose(fp);

    return history;
}

// tulostaa
void printHistory(CALCULATION *history, int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("%d+%d=%d\n", history[i].sumPre, history[i].number, history[i].sumPost);
    }
}