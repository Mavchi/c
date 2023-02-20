#include <stdio.h>

int main(void){
    int a, b;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &a);
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &b);

    printf("%d * %d = %d\n", a+1, b, (a+1)*b);
    printf("(%d / %d) - %d = %d\n", a, b, 10, (a/b)-10);
    printf("%d %% %d = %d\n", a, b-1, a%(b-1));

    return 0;
}