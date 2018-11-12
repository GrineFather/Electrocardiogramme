#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 1000

int afficher_donnees(int argc, char *argv[])
{
    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("Battements.csv", "r");

    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
        fclose(fichier);
    }
    return 0;
}

