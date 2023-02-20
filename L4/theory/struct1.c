#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[20];
    int opNro;
} STUDENT;

int main(int argc, char *argv[]) {
    STUDENT student;
    STUDENT *pStudent;
    pStudent = &student;
    strcpy(student.name, "Alexander");
    student.opNro = 12;

    printf("Name: '%s' and student number: '%d'\n", (*pStudent).name, (*pStudent).opNro);
    printf("Name: '%s' and student number: '%d'\n", pStudent->name, pStudent->opNro);

    return 0;
}