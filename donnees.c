#include <stdio.h>
#include <stdlib.h>

struct coeur
{
  int batt;
};

void afficher_donnees(int n, struct coeur *a)
{
  FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
 
    fichier = fopen("Battements.csv", "r");
 
    if (fichier != NULL)
    {
        fgets(chaine, TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        printf("%s", chaine); // On affiche la chaîne
 
        fclose(fichier);
    }
}
