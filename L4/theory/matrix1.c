#include <stdio.h>

int main(void) {
    int m[2][2][2] = {
        {{1,2},{3,4}},
        {{5,6},{7,8}}
    };

    printf("m[1][0][0] is %d\n", m[1][0][0]);
    printf("m[0][0][1] is %d\n", m[0][1][1]);
    printf("m[0][1][0] is %d\n", m[0][1][0]);

    return 0;
}