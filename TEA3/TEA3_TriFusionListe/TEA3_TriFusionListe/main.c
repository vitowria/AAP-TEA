#include <stdio.h>
#include <stdlib.h>

#include "include/traces.h"

#include "test_utils.h"
#include "list.h"
#include "elt.h"
//#include "fusion_sort.c"

// Ajouter ici les prototypes des fonctions à tester
T_list fusionSortList(T_list l, int n);

T_mode m[] = {
	{MODE_TAB_ORDONNE, "ordonne", 0, 1}, 
	{MODE_TAB_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_TAB_INVERSE, "inverse", 0, 1}, 
	{MODE_EVAL_X, "x=2.0", 2.0, 0}, 
	{MODE_TAB_ORDONNE, "ordonne (x=59)", 59, 0}, 
	{MODE_TAB_ORDONNE, "hanoi", 1, 0}
};

// mode, label, x, checkOrder 

int main(int argc, char *argv[])
{
  //int n=4;  
	T_list l = NULL;

	l = addNode(10, l);
	l = addNode(14, l);
	l = addNode(2, l);
	l = addNode(28, l);
	l = addNode(90, l);
printf("Before sort: ");
    showList(l); NL();

    l = fusionSortList(l, getSizeIte(l));

    printf("After sort: ");
    showList(l); NL();

	return 0;


	



	
}




