#include <stdio.h>

int main(void) {
    int luku1 = 2, luku2 = 13, suurempi;
    suurempi = (luku1 > luku2) ? luku1 : luku2;
    printf("Suurempi luku olisi %d.\n", suurempi); 

    char str[] = "C-kieli on kivaa.";
    char *ptr;
    ptr = str;
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}