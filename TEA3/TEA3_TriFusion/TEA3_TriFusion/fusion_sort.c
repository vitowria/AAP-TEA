#include <string.h>
#include <stdio.h>
#include "test_utils.h"
#include "include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

void fusionner(T_elt t [], int d, int m, int f); 
void fusionsort(void *base, int d, int f, int (*compare_ints)(const void *, const void *));
int compare_ints(const void* a, const void* b);


T_data fusionSort(T_data d, int n) {
    stats.nbComparisons ++;
    T_elt *base= d.pElt;
  fusionsort(base, 0, n-1, compare_ints);
    return genData(0,base);
	// A faire en TEA
}


void fusionsort(void *base, int d, int f, int (*compare_ints)(const void *, const void *)){


if (d < f){
int m = d+(f-d)/2;
// Recursively sorting both the halves
fusionsort(base, d, m, compare_ints);
fusionsort(base, m+1, f, compare_ints);
fusionner(base, d, m, f);
}

    
}


void fusionner(T_elt t [], int d, int m, int f) {
    T_elt aux[f - d + 1]; // !! Allocation dynamique sur la pile (standard C99)
	int i, j, k;
	memcpy(aux, &t[d], (f - d + 1) * sizeof(T_elt));	// Copie des données à fusionner
	stats.nbOperations += (f - d + 1);

	i = 0; j = m - d + 1; k = 0;
	while (i <= m - d && j <= f - d) {
        stats.nbComparisons+=2;
        stats.nbOperations++;
        if (aux[i] <= aux[j]) 	{
			t[d + k++] = aux[i++];	// aux[i] est plus petit : on le place dans t 
		}
		else {
	 		t[d + k++] = aux[j++];	// aux[j] est plus petit : on le place dans t 
		}
	}
    stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
    for (; i <= m - d; t[d + k++] = aux[i++]); // le reste du tableau gauche
    stats.nbOperations += (m - d - i > 0) ? m - d - i : 0;
    for (; j <= f - d; t[d + k++] = aux[j++]); // le reste du tableau droit
   // return t;
}



int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

}
 

