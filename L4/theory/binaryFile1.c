#include <stdio.h>
#include <stdlib.h>

#define COUNT 3

typedef struct person {
    char name[20];
    int age;
} PERSON;

/*
 *  This main() deploys persons-array into Persons.bin-file
 *
int main(void) {
    PERSON persons[COUNT] = {{"Ville", 5}, {"Kalle", 6}, {"Erkki", 56}};
    PERSON *pPerson = persons;

    FILE *fp = NULL;
    if( (fp = fopen("Persons.bin", "wb")) == NULL ) {
        perror("Couldnt open file Persons.bin");
        exit(1);
    }

    fwrite(pPerson, sizeof(persons), 1, fp);
    fclose(fp);

    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);
    ++pPerson;
    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);
    ++pPerson;
    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);

    return 0;
}
*/

/*
 *  This main() employs persons-array from Persons.bin-file
 *
 * */
int main(void) {
    PERSON persons[COUNT];
    PERSON *pPerson = persons;

    FILE *fp = NULL;
    if( (fp = fopen("Persons.bin", "rb")) == NULL ) {
        perror("Couldnt open file Persons.bin");
        exit(1);
    }

    fread(persons, sizeof(persons), 1, fp);
    fclose(fp);

    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);
    ++pPerson;
    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);
    ++pPerson;
    printf("Name is '%s', and age %d.\n", pPerson->name, pPerson->age);

    return 0;
}