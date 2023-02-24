#include <stdio.h>
#include <stdlib.h>
// Minimaalinen tietue listalle
typedef struct asiakas
{
    int iNumero;
    struct asiakas *pSeuraava;
} ASIAKAS;
int main(void)
{
    ASIAKAS *pAlku = NULL, *pLoppu = NULL; // Osoittimia listan käyttöön
    ASIAKAS *pUusi, *ptr;                  // Apuosoitin muistin varaukseen ja liukuri
    int i;

    // Listan luominen, 3 alkiota malliksi
    for (i = 0; i < 3; i++)
    {
        // Muistin varaus
        if ((pUusi = (ASIAKAS *)malloc(sizeof(ASIAKAS))) == NULL)
        {
            perror("Muistin varaus epäonnistui");
            exit(1);
        }
        // Uuden alkion jäsenmuuttujien arvojen asettaminen
        pUusi->iNumero = i;
        pUusi->pSeuraava = NULL;
        // Uuden alkion lisääminen listaan viimeiseksi alkioksi
        if (pAlku == NULL)
        {                  // lista on tyhjä, joten
            pAlku = pUusi; // tehdään ensimmäinen alkio
            pLoppu = pUusi;
        }
        else
        { // lista ei ole tyhjä, joten lisätään loppuun
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
        }
    }

    // Listan läpikäynti
    ptr = pAlku;
    while (ptr != NULL)
    {
        printf("Nyt palvelemme numeroa %d.\n", ptr->iNumero);
        ptr = ptr->pSeuraava;
    }
    // Muistin vapauttaminen
    ptr = pAlku;
    while (ptr != NULL)
    {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("Viimeisen asiakkaan jälkeen ei ollut ketään.\n");
    return (0);
}