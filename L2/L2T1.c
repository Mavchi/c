#include <stdio.h>

int main(void) {
    int returnedExercises, number;
    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d", &returnedExercises);

    if (returnedExercises >= 0 && returnedExercises <= 14){
        number = 0;
    } else if (returnedExercises >= 15 && returnedExercises <= 17) {
        number = 1;
    } else if (returnedExercises >= 18 && returnedExercises <= 20) {
        number = 2;
    } else if (returnedExercises >= 21 && returnedExercises <= 23) {
        number = 3;
    } else if (returnedExercises >= 24 && returnedExercises <= 26) {
        number = 4;
    } else if (returnedExercises >= 27 && returnedExercises <= 30) {
        number = 5;
    } else {
        printf("Kurssilla on vain 30 tehtävää.\n");
        return 0;
    }

    printf("Olet palauttanut %d tehtävää, joten arvosanasi on %d.\n", returnedExercises, number);

    return 0;
}