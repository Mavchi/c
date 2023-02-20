#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/*
fscanf(tietovirta, formaattimerkkijono, muuttujalista);
fprintf(tietovirta, formaattimerkkijono, muuttujalista);
• fscanf lukee tiedostoa tietovirta ja fprintf kirjoittaa sinne. Muuten näiden funktioiden
toiminta on vastaava kuin printf ja scanf.
fgets(merkkitaulukko, merkkien enimmäismäärä, tietovirta);
fputs(merkkitaulukko, tietovirta);
• fgets lukee tietovirrasta rivin tai merkkien enimmäismäärän verran merkkejä – 1 ja
sijoittaa ne merkkitaulukkoon. fputs kirjoittaa merkkitaulukon tietovirtaan.
• Luettaessa käyttäjältä syötteitä fgets’llä pitää merkkitaulukossa olla tilaa merkkijonon
loppumerkille sekä rivinvaihtomerkille käyttäjän antamien merkkien lisäksi.
fread(osoitin, koko, määrä, tietovirta);
fwrite(osoitin, koko, määrä, tietovirta);
• Nämä funktiot ovat binaaritiedostojen käsittelyyn:
o fread lukee tietovirrasta koko-muuttujan kokoisia lohkoja määrä-kappaletta ja
sijoittaa ne muistipaikkaan osoitin.
o fwrite kirjoittaa tietovirtaan muistipaikassa osoitin olevan tiedon, jota on kokomuuttujan kokoisissa lohkoissa määrä-kappaletta.
Alla on muutama muu hyödyllinen tiedostonkäsittelyfunktio. Niihin tarkempia tietoja ja
käyttöohjeita löytyy man-sivuilta.
• fgetc(tietovirta);
• fputc(merkki, tietovirta);
• rewind(tietovirta);
• ftell(tietovirta);
• fseek(tietovirta, sijainti, alku);
• feof(tietovirta);
• remove(tiedosto);
• rename(nimi, uusi_nimi); 
*/

int main(void) {
    FILE *file;
    if((file = fopen("hello.txt", "w")) == NULL) {
        perror("Tiedoston avaus");
        exit(0);
    }
    fprintf(file, "Hello World!\n");
    fclose(file);

    FILE *file2;
    char aLine[50];
    file2 = fopen("hello.txt", "r");
    fgets(aLine, 50, file2);
    printf("%s", aLine);
    fclose(file2);

    return 0;
}