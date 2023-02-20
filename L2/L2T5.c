#include <stdio.h>

int main(void){
    int sum = 0, choise;
    printf("Anna kokonaisluku: ");
    scanf("%d", &sum);
    getchar();

    do {
        printf("\nValikko:\n");
        printf("1) Lisää lukuun\n");
        printf("2) Vähennä luvusta\n");
        printf("0) Lopeta\n");
        printf("Valintasi: ");
        scanf("%d", &choise);

        int number; // for additiion and substraction from given number at beginning (sum)
        switch(choise) {
            case 1:
                printf("\nAnna lukuun lisättävä kokonaisluku: ");
                scanf("%d", &number);
                sum += number;
                printf("Luku on nyt %d.\n", sum);
                break;
            case 2:
                printf("\nAnna luvusta vähennettävä kokonaisluku: ");
                scanf("%d", &number);
                sum -= number;
                printf("Luku on nyt %d.\n", sum);
                break;
            case 0:
                printf("\nLopetetaan.\n");
                break;
            default:
                printf("\nTuntematon valinta, yritä uudestaan.\n");
                break;
        }
    } while(choise != 0);

    printf("\nKiitos ohjelman käytöstä.\n");
    return 0;
}