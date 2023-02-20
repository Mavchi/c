/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 15.2.2023
    Tiedosto: L5T2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 26

typedef struct Team {
    char name[MAX_LENGTH];
    int score;
} TEAM;

// Ask user for name of file to be read.
void getFileName(char *name);

// Find team with smalllest score
void worstTeam(char *fileName);

int main(void) {
    char fileName[MAX_LENGTH];

    getFileName(fileName);
    if (strlen(fileName) == 0) {
        perror("Give name of file");
        exit(0);
    }
    printf("Tiedosto '%s' luettu.\n", fileName);

    worstTeam(fileName);

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}


// Ask user for name of file to be read. Returns pointer given to function
void getFileName(char *name) {
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", name);
    getchar();
}

// Find team with smalllest score
void worstTeam(char *fileName) {
    FILE *fp = NULL;
    TEAM worstTeam;
    strcpy(worstTeam.name, "");

    if( (fp=fopen(fileName, "r")) == NULL) {
        perror("Ei voitu avata tiedostoa, lopetetaan");
        exit(0);
    }

    char line[MAX_LENGTH+5];
    while ( fgets(line, MAX_LENGTH+5, fp) != NULL) {
        char *name=NULL, *score=NULL;

        if ((name = strtok(line, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", line);
            exit(0);
        }
        if ((score = strtok(NULL, "\n")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", line);
            exit(0);
        }

        // jos tyhjä niin alustetaan ja käynnistetään luuppi uudestaan conituella
        if (strlen(worstTeam.name) == 0) {
            strcpy(worstTeam.name, name);
            worstTeam.score = atoi(score);
            continue;
        }

        // verrataan
        if (atoi(score) < worstTeam.score) {
            strcpy(worstTeam.name, name);
            worstTeam.score = atoi(score);
        }
        name=NULL;
        score=NULL;
    }

    printf("Pienin pistemäärä oli joukkueella '%s' %d pisteellä.\n", worstTeam.name, worstTeam.score);
    printf("%c\n", worstTeam.name[0]);
    fclose(fp);
}