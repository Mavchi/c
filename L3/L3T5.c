/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 04.02.2023
    Tiedosto: L3T5.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH_STRINGS 30

// init random generator for rand() using input from user
void initRandom();
// how many chars to generate for pool
int howMany();
// generate new character and if acceptable add into string 's'
void addNewChar(char *s);
// find character 'c'
int isC(char *s);

int main(void) {
    int count = 0;
    char text[MAX_LENGTH_STRINGS];

    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");
    initRandom();
    count = howMany();

    for(int i=0; i<count; i++) {
        addNewChar(text);
    }

    if (isC(text)) {
        printf("\nMerkkijonosta löydettiin merkki 'c',\n");
    } else {
        printf("\nMerkkijonossa ei ollut merkkiä 'c'.\n");
    }
    printf("Generoitiin merkkijono '%s', jossa on %ld merkkiä.\n", text, strlen(text));
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}

// init random generator for rand() using input from user
void initRandom() {
    int seed;
    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &seed);
    getchar();
    srand(seed);
}

// how many chars to generate for pool
int howMany() {
    int n;
    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &n);
    getchar();
    return n;
}

// generate new character and if acceptable add into string 's'
void addNewChar(char *s) {
    int random = (rand() % 95) + 32;
    char c = (char)random;
    if (isalnum(c) || isalpha(c) || isspace(c)) {
        //printf("acceptable char %c, now %s\n", c, s);
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
    } else {
        //printf("char %c, now %s\n", c, s);
        return;
    }
}

// find character 'c'
int isC(char *s) {
    for(int i=0; i<strlen(s); i++) {
        if (s[i] == 'c') {
            return 1;
        }
    }
    return 0;
}