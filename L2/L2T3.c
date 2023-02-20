#include <stdio.h>
#include <string.h>

int main(void){
    char c;
    printf("Anna merkki: ");
    scanf("%c", &c);
    getchar();
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", c, (int)(c));

    char s[15];
    int sum = 0;
    printf("Anna merkkijono: ");
    scanf("%s", s);
    getchar();

    for(int i=0; i<strlen(s); i++){
        sum += (int)s[i];
    }

    printf("Merkkijonon '%s' merkkien summa on %d.\n\n", s, sum);
    return 0;
}