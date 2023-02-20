#include <stdio.h>

int main(void) {
    float list[4] = {1.4, 5.4, 1.0, 6.1};
    float *pList = list;

    for(int i=0; i<(sizeof(list)/sizeof(float)); i++) {
        printf("%d: %.2f\n", i+1, *pList);
        ++pList;
    }

    return 0;
}