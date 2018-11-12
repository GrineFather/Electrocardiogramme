#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int tab[],int deb,int fin)
{
 const int pivot = tab[deb];
 int pos=deb;
 int i;
 if (deb>=fin)
 return;
  
 for (i=deb; i<fin ; i++)
 {
   if (tab[i]<pivot)
   {
   tab[pos]=tab[i];
   pos++;
   tab[i]=tab[pos];
   tab[pos]=pivot;
 }
 }
 tri_tab_recursif(tab,deb,pos);
 tri_tab_recursif(tab,pos+1,fin);
}

void search(int n, struct inhabitant *a){
    char prenomsearch[MAX_STR_SIZE];
    char nomsearch[MAX_STR_SIZE];
    printf("Prenom et nom a chercher : \n");
    scanf("%s%s", prenomsearch, nomsearch);
    for (int i=0; i<n; i++)
    {
        if (strcmp(a[i].prenom, prenomsearch)==0 && strcmp(a[i].nom, nomsearch)==0)
        {
            printf("%d, %s, %s, %d\n", a[i].distance, a[i].prenom,a[i].nom, a[i].zip);
        }
    }
    printf("Fin de la recherche");
}
