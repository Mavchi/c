#include <stdio.h>

#define MIN 3
#define MAX 10

int main(void){
    int n;
    printf("Anna kokonaisluku väliltä %d - %d: ", MIN, MAX);
    scanf("%d", &n);
    printf("\n");

    if( n>=MIN && n<=MAX) {
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
    }

    printf("\n");
    return 0;
}