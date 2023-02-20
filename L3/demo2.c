#include <stdio.h>
#include <string.h>
#define LEN 80
// Perustietotyyppi int, float, char arvoparametrinä ja paluuarvona
int summaa(int iLuku1, int iLuku2)
{
    int iSumma = iLuku1 + iLuku2;
    return (iSumma);
}
// Merkkijono parametrinä ja perustietotyyppi paluuarvona
int kysyLuku(char *pPrompti)
{
    int iNumero;
    printf("%s: ", pPrompti);
    scanf("%d", &iNumero);
    getchar(); // Ei jätetä rivinvaihtoa väijymään puskuriin
    return (iNumero);
}
// Merkkijono muuttujaparametrina ja osoite paluuarvona, rakenteinen tietorakenne
char *kysyNimi(char *pPrompti, char *pNimi)
{
    printf("%s: ", pPrompti);
    scanf("%s", pNimi);
    getchar(); // Ei jätetä rivinvaihtoa väijymään puskuriin
    return (pNimi);
}
// Merkkijono muuttujaparametrina ja osoite paluuarvona, rakenteinen tietorakenne
char *kysyRivi(char *pPrompti, char *pRivi)
{
    printf("%s: ", pPrompti);
    fgets(pRivi, LEN, stdin);
    pRivi[strlen(pRivi) - 1] = '\0';
    return (pRivi);
}
// Merkkijonon kopiointi, tila varattu kutsuvassa ohjelmassa, paluuarvona osoitin
char *kopioi(char p1[], char p2[])
{
    int i = 0;
    do
    {
        p1[i] = p2[i];
        i++;
    } while (p1[i - 1] != '\0');
    return (p1);
}
int main(void)
{
    int iIka, iPituus, iNro1 = 1, iNro2 = 2;
    char aNimi1[30], aNimi2[30], aRivi[LEN];
    printf("Lukujen %d ja %d summa on %d.\n", iNro1, iNro2, summaa(iNro1, iNro2));
    iIka = kysyLuku("Anna ikä");
    printf("Ikä on %d.\n", iIka);
    iPituus = kysyLuku("Anna pituus");
    printf("Pituus on %d.\n", iPituus);
    kysyNimi("Anna etunimi", aNimi1);
    kysyNimi("Anna sukunimi", aNimi2);
    printf("Etunimi on %s ja sukunimi on %s.\n", aNimi1, aNimi2);
    kopioi(aNimi1, aNimi2);
    printf("Kopioinnin jälkeen nimi 1 on '%s' ja 2 '%s'.\n", aNimi1, aNimi2);
    kysyRivi("Anna rivi", aRivi);
    printf("Annoit rivin '%s'.\n", aRivi);
    return (0);
}
