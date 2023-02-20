/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 7.2.2023
    Tiedosto: L4T3.c
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH    30

typedef struct calculation {
    char operator;
    int sumPre;
    int sumPost;
    int number;
} CALCULATION;

// returns new sum
void addToTotal(int index, CALCULATION *history);
// writes complusory caluclations to binary file specified by user (FILENAME)
void writeHistoryToTextFile(CALCULATION *history, int lastIndex, char *FILENAME);
// read old session and save into table defined in main-function, pointer is passed as first argumennt
void readHistoryToTextFile(CALCULATION *history, int *lastIndex, char *FILENAME);

int main(void){
    CALCULATION history[MAX_LENGTH];
    int choise;
    int indexLastC = 0;
    char fileName[MAX_LENGTH];

    printf("Anna kokonaisluku: ");
    scanf("%d", &history[0].sumPre);
    getchar();
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);
    getchar();

    do {
        printf("\nValitse haluamasi toiminto:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Kirjoita historia tiedostoon\n");
        printf("3) Lue historia tiedostosta\n");
        printf("0) Lopeta\n");
        printf("Anna valintasi: ");
        scanf("%d", &choise);

        switch(choise) {
            case 1:
                addToTotal(indexLastC++, history);
                // considering if keeping at minimal effort is best, checking if out of size for history array
                if(indexLastC == MAX_LENGTH-1) {
                    printf("History array is full. Quitting\n");
                    exit(0);
                }
                break;
            case 2:
                writeHistoryToTextFile(history, indexLastC ,fileName);
                break;
            case 3:
                readHistoryToTextFile(history, &indexLastC ,fileName);
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
void addToTotal(int index, CALCULATION *history) {
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &history[index].number);
    getchar();

    history[index].sumPre = index == 0 ? history[index].sumPre : history[index-1].sumPost;
    history[index].sumPost = history[index].sumPre + history[index].number;
    printf("%d+%d=%d\n", history[index].sumPre, history[index].number, history[index].sumPost);
}

// writes complusory caluclations to binary file specified by user (FILENAME)
void writeHistoryToTextFile(CALCULATION *history, int lastIndex, char *FILENAME) {
    FILE *fp = NULL;

    if ((fp = fopen(FILENAME, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    for(int i=0; i<lastIndex; i++) {
        fprintf(fp, "%d+%d=%d\n", history[i].sumPre, history[i].number, history[i].sumPost);
    }

    printf("\nTiedosto '%s' kirjoitettu.\n", FILENAME);

    fclose(fp);
}


// read old session and save into table defined in main-function, pointer is passed as first argumennt
void readHistoryToTextFile(CALCULATION *history, int *lastIndex, char *FILENAME) {
    FILE *fp = NULL;
    *lastIndex = 0;

    if ((fp = fopen(FILENAME, "r")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("\nTiedostossa oleva laskuhistoria:\n");
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        sscanf(line, "%d+%d=%d", &history[*lastIndex].sumPre, &history[*lastIndex].number, &history[*lastIndex].sumPost);
        printf("%d+%d=%d\n", history[*lastIndex].sumPre, history[*lastIndex].number, history[*lastIndex].sumPost);
        ++(*lastIndex);
    }

    printf("Tiedosto '%s' luettu ja tulostettu.\n", FILENAME);
    fclose(fp);
}