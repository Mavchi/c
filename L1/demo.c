/*#include <stdio.h>
#include <string.h>
int main(void) {
 char merkkijono[20] = "Kirsi Virtanen";
 printf("'%s'\n", merkkijono);
 strcpy(merkkijono, "Matti");
 printf("'%s'\n", merkkijono);
 merkkijono[5] = ' '; // Poistetaan Matti-sanan perästä loppumerkki
 printf("'%30s'\n", merkkijono);
 return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
int main(void) {
 char c;
 char nimi[30];

 printf("Anna merkki: ");
 scanf("%c", &c);
 getchar();
 printf("Anna etunimesi (max 28 merkkiä): "); // nimi + \n + NULL
 fgets(nimi, 30, stdin); // luetaan nimi + \n ja lisätään NULL
 // scanf("%s", nimi);
 nimi[strlen(nimi)-1] = '\0';
 printf("Nimesi on '%s' ja merkki oli %c.\n", nimi, c);
 return(0);
}
*/

#include <stdio.h>

int main(void){
    float a=1, b=2;
    printf("a=%d,\tb=%6.3lf\n", a, b);

    float c = 1.12345;
    printf("%5.2f\n", c);

    float d = (float)2 / 3;
    printf("%f\n", d);

    return 0;
}