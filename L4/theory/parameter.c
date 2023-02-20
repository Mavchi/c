#include <stdio.h>
void eiMuuta(int iArvoparametri)
{
    iArvoparametri = 1000;
}
void muuttaa(int *pMuuttujaparametri)
{
    *pMuuttujaparametri = 1000;
}
int main(void)
{
    int iLuku = 1; /* Määritellään kokonaislukumuuttuja */
    printf("Alussa muuttujan arvo on %d.\n", iLuku);
    /* Kutsutaan funktiota eiMuuta. */
    eiMuuta(iLuku);
    printf("eiMuuta-funktion jälkeen muuttujan arvo on %d.\n", iLuku);
    /* Kutsutaan funktiota muuttaa. */
    muuttaa(&iLuku);
    printf("muuttaa-funktion jälkeen muuttujan arvo %d.\n", iLuku);
    return (0);
}