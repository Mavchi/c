#include <stdio.h>
#include <stdlib.h>

#define WIDTH 3

// asks user name for a data file that saves input and resulting matrixes
void askFileName(char *fileName);
// tulostaa ja kirjoittaa matriisia näytölle ja tiedostoon
void writeMatrix(int m[WIDTH][WIDTH], char *name, FILE *stream);

int main(void) {
    int m1[WIDTH][WIDTH], m2[WIDTH][WIDTH];
    char fileName[40];
    FILE *fp = NULL;

    askFileName(fileName);

    printf("Anna arvot lähtömatriisille: \n");
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("Rivi %d, alkio %d: ", i+1, j+1);
            scanf("%d", &m1[i][j]);
            getchar();
        }
    }


    // open file to write
    if ((fp = fopen(fileName, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    printf("\n");
    writeMatrix(m1, "Lähtömatriisi", stdout);
    writeMatrix(m1, "Lähtömatriisi", fp);

    // transpose
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<WIDTH; j++) {
            m2[j][i] = m1[i][j];
        }
    }
    writeMatrix(m2, "Lähtömatriisin transpoosi", stdout);
    writeMatrix(m2, "Lähtömatriisin transpoosi", fp);

    printf("Tiedosto '%s' kirjoitettu.\n", fileName);
    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

// asks user name for a data file that saves input and resulting matrixes
void askFileName(char *fileName) {
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", fileName);
    getchar();
}

// tulostaa ja kirjoittaa matriisia näytölle ja tiedostoon
void writeMatrix(int m[WIDTH][WIDTH], char *name, FILE *stream) {
    fprintf(stream, "%s: \n", name);
    for (int i=0; i<WIDTH; i++) {
        fprintf(stream, "%4d %4d %4d \n", m[i][0], m[i][1], m[i][2]);
    }
    fprintf(stream, "\n");
}