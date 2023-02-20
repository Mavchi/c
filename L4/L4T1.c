#include <stdio.h>
#include <string.h>

#define MAX_WIDTH   50

typedef struct song {
    char name[MAX_WIDTH];
    char artist[MAX_WIDTH];
    char length[MAX_WIDTH];
    int yearOfRelease;
} SONG;

void getDataUserInputs(SONG *pSong);

int main(void) {
    SONG song;
    getDataUserInputs(&song);

    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", song.name, song.artist);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %d.\n", song.length, song.yearOfRelease);
    printf("Kiitos ohjelman käytöstä.");

    return 0;
}

void getDataUserInputs(SONG *pSong) {
    printf("Anna kappaleen nimi: ");
    fgets(pSong->name, MAX_WIDTH, stdin);
    (*pSong).name[strlen((*pSong).name)-1] = '\0';
    printf("Anna kappaleen esittäjä: ");
    fgets(pSong->artist, MAX_WIDTH, stdin);
    (*pSong).artist[strlen((*pSong).artist)-1] = '\0';
    printf("Anna kappaleen pituus: ");
    fgets(pSong->length, MAX_WIDTH, stdin);
    (*pSong).length[strlen((*pSong).length)-1] = '\0';
    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%d", &pSong->yearOfRelease);
    getchar();
}