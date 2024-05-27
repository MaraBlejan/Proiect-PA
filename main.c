#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils/utils.h"

int main()
{
    // Citirea codului valid
    char sablon[256];

    printf("Introduceti exemplul de cod valid: ");
    scanf(" %[^\n]", sablon); // Citire pana la "\n"

    // Generarea unui fragment de cod invalid pe baza exemplului
    int lungime_maxima = strlen(sablon) * 2;
    char fragment_cod[lungime_maxima + 1];

    generare_fragment_cod(sablon, fragment_cod, lungime_maxima);

    printf("Fragmentul de cod generat: %s\n", fragment_cod);

    // Calcularea numărului minim de schimbări
    int schimbari;

    schimbari = minim_schimbari(sablon, fragment_cod);

    printf("Numarul minim de schimbări: %d\n", schimbari);

    return 0;
}
