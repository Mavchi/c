#include <stdio.h>
#include <stdlib.h>
typedef struct asiakas
{
    int iNumero;
    struct asiakas *pSeuraava;
} ASIAKAS;

ASIAKAS *lisaaSolmu(ASIAKAS *pA, int x)
{
    ASIAKAS *pUusi, *ptr;

    // Muistin varaus
    if ((pUusi = (ASIAKAS *)malloc(sizeof(ASIAKAS))) == NULL)
    {
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    // Uuden alkion arvojen määrittäminen
    pUusi->iNumero = x;
    pUusi->pSeuraava = NULL;
    // Uuden alkion jäsenmuuttujien arvojen asettaminen
    if (pA == NULL)
    { // lista on tyhjä -> eka alkio
        pA = pUusi;
    }
    else
    { // lista ei tyhjä -> viimeinen alkio
        ptr = pA;
        while (ptr->pSeuraava != NULL)
            ptr = ptr->pSeuraava;
        ptr->pSeuraava = pUusi;
    }
    return (pA);
}
ASIAKAS *tulosta(ASIAKAS *pA)
{
    ASIAKAS *ptr = pA;
    while (ptr != NULL)
    {
        printf("Nyt palvelemme numeroa %d.\n", ptr->iNumero);
        ptr = ptr->pSeuraava;
    }
    return (pA);
}

ASIAKAS *tyhjenna(ASIAKAS *pA)
{
    ASIAKAS *ptr = pA;
    while (ptr != NULL)
    {
        pA = ptr->pSeuraava;
        free(ptr);
        ptr = pA;
    }
    return (pA);
}

int main(void)
{
    ASIAKAS *pAlku = NULL;
    int i;

    // Listan luominen, 3 alkiota kokeeksi
    for (i = 0; i < 3; i++)
    {
        pAlku = lisaaSolmu(pAlku, i);
    }
    // Listan läpikäynti
    tulosta(pAlku);
    // Muistin vapauttaminen
    pAlku = tyhjenna(pAlku);
    printf("Viimeisen asiakkaan jälkeen ei ollut ketään.\n");
    return (0);
}