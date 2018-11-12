#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_SIZE 20

#define PERSONS_TO_SAVE_FILE "evacuation_plan0.txt"



struct inhabitant {
int ;
};

void show(int n, struct inhabitant *a) {
int i;
for(i = 0; i < n; ++i) {
printf("%d, %s, %s, %dn", a[i].distance, a[i].prenom, a[i].nom, a[i].zip);
}
}

void printout(FILE *s, int n, struct inhabitant *a) {
int i;
for(i = 0; i < n; ++i) {
fprintf(s, "%d %s %s %dn", a[i].distance, a[i].prenom, a[i].nom, a[i].zip);
}
}

void read(FILE *s, struct inhabitant **h, int *m) {
int i, ntok;
struct inhabitant *tmph;

ntok = fscanf(s, "%d", m);

if(ntok != 1 || *m < 0) {
fprintf(stderr, "Unable to read file.n");
exit(-1);
}

if((*h = (struct inhabitant *)malloc(sizeof(struct inhabitant) * (*m))) == NULL) {
fprintf(stderr, "Unable to allocate space for inhabitants.n");
exit(-1);
}

tmph = *h;
for(i = 0; i < (*m); ++i) {
ntok = fscanf(s, "%d %s %s %d", &(tmph[i].distance), (char *)&(tmph[i].prenom), (char *)&(tmph[i].nom), (int *)&(tmph[i].zip));
if(ntok != 4) {
fprintf(stderr, "File wrongly formatted.n");
exit(-1);
}
}
}

void fuse(struct inhabitant *a, struct inhabitant *tmp, int s0, int e0, int s1, int e1, int (cmp)(struct inhabitant *, struct inhabitant *)){

int i2 = s0;
for(; s0 < e0 && s1 < e1; ) {
if(cmp(&a[s0], &a[s1]) <= 0) {
tmp[i2++] = a[s0++];
}
else {
tmp[i2++] = a[s1++];
}
}
for(; s0 < e0; ++s0) {
tmp[i2++] = a[s0];
}
for(; s1 < e1; ++s1) {
tmp[i2++] = a[s1];
}
}

void divide(int s, int e, struct inhabitant *a, struct inhabitant *tmp, int (cmp)(struct inhabitant *, struct inhabitant *), int f) {
int m;

m = (s + e) / 2;
if(e - s > 2) {
divide(s, m, tmp, a, cmp, f++);
divide(m, e, tmp, a, cmp, f++);
}

fuse(a, tmp, s, m, m, e, cmp);
}

void sort(int n, struct inhabitant *a, int (cmp)(struct inhabitant *, struct inhabitant *)) {
struct inhabitant *tmp;

if((tmp = malloc(n * sizeof(struct inhabitant))) == NULL) {
fprintf(stderr, "Unable to malloc enough memory in sorting function.n");
exit(-1);
}

memcpy(tmp, a, n * sizeof(struct inhabitant));

divide(0, n, a, tmp, cmp, 0);

memcpy(a, tmp, n * sizeof(struct inhabitant));

free(tmp);
}

int compare_inhabitants_by_distance(struct inhabitant *a, struct inhabitant *b) {
return a->distance < b->distance ? -1 : a->distance > b->distance;
}

int compare_inhabitants_by_zipcode(struct inhabitant *a, struct inhabitant *b) {
return a->zip < b->zip ? -1 : a->zip > b->zip;
}

#define PERSONS_TO_SAVE_FILE_IN "evacuation_plan0.txt"
#define PERSONS_TO_SAVE_FILE_OUT "better_evacuation_plan0.txt"

/*void search(int n, struct inhabitant *a){
char prenomsearch[MAX_STR_SIZE];
char nomsearch[MAX_STR_SIZE];
printf("Prenom et nom à chercher : n");
scanf("%s%s", prenomsearch, nomsearch);
for (int i=0; i<n; i++){
if (strcmp(a[i].prenom, prenomsearch)==0 && strcmp(a[i].nom, nomsearch)==0){
printf("%d, %s, %s, %dn", a[i].distance, a[i].prenom,a[i].nom, a[i].zip);
}
}
printf("Fin de la recherche");
}
*/
int main(int argc, char **argv) {
FILE *s;
int n;




if((s = fopen(PERSONS_TO_SAVE_FILE_IN, "r")) == NULL) {
fprintf(stderr, "Unable to open file.");
exit(-1);
}

read(s, &inhabs0, &n);

sort(n,inhabs0,compare_inhabitants_by_zipcode);
sort(n,inhabs0,compare_inhabitants_by_distance);
search(n,inhabs0);


if((s = fopen(PERSONS_TO_SAVE_FILE_OUT, "w+")) == NULL) {
fprintf(stderr, "Unable to open file.");
exit(-1);
}
printout(s, n, inhabs0);
fclose(s);

free(inhabs0);

return EXIT_SUCCESS;
}
