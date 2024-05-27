#ifndef CODE_UTLIS_H
#define CODE_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcție pentru a calcula minimul dintre două numere
int min(int a, int b);

// Funcție pentru calcularea distanței Levenshtein
int minim_schimbari(char *sir1, char *sir2);

// Funcție pentru generarea unui fragment de cod invalid pe baza exemplului
void generare_fragment_cod(char *sablon, char *fragment_cod, int lungime_maxima);

#endif // CODE_UTLIS_H
