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
