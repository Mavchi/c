#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Annoit liikaa parametreja.\n");
        exit(0);
    } else if (argc < 3) {
        printf("Et antanut tarpeeksi parametreja.\n");
        exit(0);
    }

    FILE *fp = NULL;
    if ( (fp = fopen(argv[1], "r")) == NULL ){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    char line[MAX_LENGTH];
    int count = 0;
    while ( (fgets(line, MAX_LENGTH, fp)) != NULL ) {
        if (count >= atoi(argv[2])) {
            break;
        }

        printf("%s", line);
        if( line[strlen(line)-1] != '\n') {
            printf("\n");
        }
        ++count;
    }

    printf("\n");
    if (count < atoi(argv[2])) {
        printf("Tiedostossa ei ole enempää rivejä luettavaksi.\n");
    }
    printf("Tiedostosta '%s' luettu %d riviä.\n", argv[1], count);

    fclose(fp);
    return 0;
}