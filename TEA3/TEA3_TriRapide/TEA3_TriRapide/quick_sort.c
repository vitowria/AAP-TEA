#include<stdio.h>
#include "test_utils.h"
#include "include/traces.h"

// TODO : placer les compteurs aux endroits appropriés :
// stats.nbOperations ++;
// stats.nbComparisons ++;

int Partitionnement (T_elt t [], int g, int d); 
void quick_sort(T_elt *tab, int d, int f);
int comparer(T_elt e1, T_elt e2);
void echanger(T_elt t[], int i1, int i2);


int comparer(T_elt e1, T_elt e2){
    
    stats.nbComparisons++;
    return e1-e2;
}
 


void echanger(T_elt t[], int i1, int i2){
    T_elt aux = t[i1];
        t[i1] = t[i2];
        t[i2] = aux;
}


void quick_sort(T_elt *tab, int d, int f){
    int iPivot;
    //int *tab=t.pElt;
    //echanger(tab, d + rand() % (f - d), f);
    stats.nbComparisons ++;
    if (f > d) {
        iPivot = Partitionnement(tab, d, f);
        quick_sort(tab, d, iPivot - 1);
        quick_sort(tab, iPivot+1, f);
        
    }
}


    
T_data quickSort(T_data t, int n) {
    int *tab=t.pElt;
    quick_sort(tab, 0, n-1);
    return genData(0, tab);
}


int Partitionnement (T_elt t [], int g, int d){ 
	int pg=g , pd=d-1; // On utilise g et d comme « pointeurs » qui se déplacent
	// On choisit le dernier élément comme pivot

	while (pg<pd) {
		// On déplace pg et pd jusqu’à trouver des valeurs incohérentes % pivot

		while ( (pg<pd) &&  (comparer(t[pg],t[d]) <=0) ) {pg++ ;	stats.nbComparisons ++;}
		while ( (pg<pd) && (comparer(t[pd],t[d])>0) ) {pd-- ; stats.nbComparisons ++;}

		// Comment compter correctement ? On utilise une fonction de comparaison...
		if (pg < pd) {
			echanger(t,pg,pd); 
			pg++ ; pd-- ; 
		}
	}
    stats.nbOperations++;
    if (comparer(t[pg],t[d]) <= 0) pg++ ;
   
    stats.nbOperations=3+stats.nbOperations;
    echanger(t, pg, d) ;

	return pg ; 
}



