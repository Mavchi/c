/*
    Tekijä: Aleksander Khlebnikov
    Päivämäärä: 4.2.2023 
    Tiedosto: L3T1.c
*/
#include <stdio.h>

float rectangleArea(float l, float w);

int main(void) {
    float l, w;
    
    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &l);
    getchar();
    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &w);
    getchar();

    printf("Suorakulmion pinta-ala on %.2f.\n", rectangleArea(l, w));
    printf("Kiitos ohjelman käytöstä.\n");

    return 0;
}

float rectangleArea(float l, float w) {
    return l*w;
}