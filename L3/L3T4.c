/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 4.2.2023
    Tiedosto: L3T4.c
*/
#include <stdio.h>

#define MAX_LENGTH_STRING   60

// returns lengths of an string
int len(char *s);
// adds string 'b' to end of string 'a'
void addToFirstString(char *a, char *b);

int main(void) {
    char a[MAX_LENGTH_STRING];
    char b[MAX_LENGTH_STRING];
    
    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(a, MAX_LENGTH_STRING, stdin);
    a[len(a)-1] = '\0';
    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(b, MAX_LENGTH_STRING, stdin);
    b[len(b)-1] = '\0';

    // check if given input too long
    if(len(a)+len(b) >= MAX_LENGTH_STRING-1) {
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
    } else {
        addToFirstString(a,b);
        printf("Yhdistetty merkkijono on:\n");
        printf("'%s'\n", a);
    }

    printf("Kiitos ohjelman käytöstä.\n");
    return 0;
}

// returns lengths of an string
int len(char *s) {
    int i=0;

    while(s[i] != '\0') {
        i++;
    }
    return i;
}

// adds string 'b' to end of string 'a'
void addToFirstString(char *a, char *b) {
    int i1 = len(a);
    int i2 = 0;

    while(b[i2] != '\0'){
        if(i1 >= MAX_LENGTH_STRING-1) {
            break;
        }
        a[i1] = b[i2];
        ++i2;
        ++i1;
    }
    a[i1] = '\0';
}