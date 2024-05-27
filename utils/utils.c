#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

// Funcție pentru a calcula minimul dintre două numere
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Funcție pentru calcularea numarului minim de schimbări
int minim_schimbari(char *sir1, char *sir2)
{
    // Lugimile celor doua siruri
    int lungime_s1 = strlen(sir1);
    int lungime_s2 = strlen(sir2);

    // Alocarea memoriei pentru matricea dp
    int **dp = NULL;

    dp = (int **)malloc((lungime_s1 + 1) * sizeof(int *));

    for (int i = 0; i <= lungime_s1; i++)
    {
        dp[i] = (int *)malloc((lungime_s2 + 1) * sizeof(int));
    }

    // Calcularea numarului minim de schimbări
    for (int i = 0; i <= lungime_s1; i++)
    {
        for (int j = 0; j <= lungime_s2; j++)
        {
            // Dacă primul șir este gol, costul este egal cu lungimea celui de-al doilea șir
            if (i == 0)
            {
                dp[i][j] = j;
            }
            // Dacă al doilea șir este gol, costul este egal cu lungimea primului șir
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            // Dacă ultimele caractere ale celor două șiruri sunt egale, costul rămâne același
            else if (sir1[i - 1] == sir2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // Dacă ultimele caractere sunt diferite, luăm minimul dintre inserare, ștergere și înlocuire, și adăugăm 1
            else
            {
                dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }

    int rezultat = dp[lungime_s1][lungime_s2];

    // Eliberarea memoriei
    for (int i = 0; i <= lungime_s1; i++)
    {
        free(dp[i]);
    }
    free(dp);

    // Returarea numarului minim de schimbări
    return rezultat;
}

// Funcție pentru generarea unui fragment de cod invalid pe baza exemplului
void generare_fragment_cod(char *sablon, char *fragment_cod, int lungime_maxima)
{
    int lungime = strlen(sablon);
    int numar_schimbari = rand() % (lungime_maxima / 2);

    // Copiază șablonul în fragment_cod pentru a începe modificările
    strcpy(fragment_cod, sablon);

    // Aplicați modificări aleatorii fragmentului de cod
    for (int i = 0; i < numar_schimbari; i++)
    {
        int pozitie = rand() % lungime;
        int metoda = rand() % 3;

        if (metoda == 0)
        {
            // Înlocuiește caracterul de la poziția aleatorie cu un caracter aleator din 'a' până la 'z'
            fragment_cod[pozitie] = (rand() % 26) + 'a';
        }
        else if (metoda == 1)
        {
            // Inserează un caracter aleator la poziția aleasă
            char temp[lungime_maxima + 1];
            strncpy(temp, fragment_cod, pozitie);
            temp[pozitie] = (rand() % 26) + 'a';
            strcpy(temp + pozitie + 1, fragment_cod + pozitie);
            strcpy(fragment_cod, temp);
            lungime++;
        }
        else if (metoda == 2)
        {
            // Șterge caracterul de la poziția aleatorie
            if (lungime > 1)
            {
                strcpy(fragment_cod + pozitie, fragment_cod + pozitie + 1);
                lungime--;
            }
        }
    }

    fragment_cod[lungime] = '\0';
}
