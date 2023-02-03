#include <assert.h>
#include <stdio.h>

#include "include/traces.h"

#include "elt.h"
#include "list.h"
#include "rpn.h"
#include "stack_cld.h"

int* dropfromTab(int* tableau, int index, int length);

//make ./TEA2AAP.exe

int main(void) {


  /////////////////////////////////////////////////
  // Partie 2 - Exploration d’un arbre à la volée//
  /////////////////////////////////////////////////

  // a,b,c,d,e,f pour les nombres i,j,k... pour les operateurs

  int ValeurCherche = 90; 
  int nombres[6]={3, 10, 7, 5, 16,88};
  int length = 6;
  
  char operateurs[] = {'+', '-', '*','/'};
  int *nombres_mod;
  int v1,v2,v1_2,v3,v1_2_3,v4,v1_2_3_4,v5,v1_2_3_4_5,v6;
  int a,b,c,d,e,f,i,j,k,l,m;

  T_elt test;
  char op[100];

  for(a=0; a<6;a++){
    v1 = nombres[a];
    printf("\n Premier nombre: %d \n",v1);
    for(b=0; b<5; b++){
      nombres_mod = dropfromTab(nombres, a, length);
      v2 = nombres_mod[b];
      printf("Deuxième nombre: %d \n",v2);
      for(i=0; i<4; i++){
        printf("Operateur: %c\n", operateurs[i]);
        sprintf(op, "%d %d %c", v1, v2, operateurs[i]);
        test = rpn_eval(op);
        printf("Result: %d\n", test.result);
        
        if(test.result == ValeurCherche){
          printf("La combinaison pour calculer le valeur est (en RPN): %d %c %d = %d \n", v1, operateurs[i], v2, test.result);
          return 0;
        }
        if(test.result == -1) continue;
        v1_2=test.result;
        
        for(c=0; c<4; c++){
          printf("\n Combinaison 1°,2°: %d \n",v1_2);
          nombres_mod = dropfromTab(nombres, a, length);
          nombres_mod = dropfromTab(nombres_mod, b, length-1);
          v3 = nombres_mod[c];
          printf("\nTroisième nombre: %d \n",v3);
          for(j=0; j<4; j++){
            printf("Operateur: %c\n", operateurs[j]);
            sprintf(op, "%d %d %c", v1_2, v3, operateurs[j]);
            test = rpn_eval(op);
            printf("%d\n", test.result);
            
            if(test.result == ValeurCherche){
              printf("La combinaison pour calculer le valeur est (en RPN): %d %c %d = %d \n", v1_2, operateurs[j], v3, test.result);
              return 0;
            }
            if(test.result == -1) continue;
            v1_2_3=test.result;

            for(d=0; d<3; d++){
              printf("\n Combinaison 1°,2°,3°: %d \n",v1_2_3);
              nombres_mod = dropfromTab(nombres, a, length);
              nombres_mod = dropfromTab(nombres_mod, b, length-1);
              nombres_mod = dropfromTab(nombres_mod, c, length-2);
              v4 = nombres_mod[d];
              printf("\nQuatrième nombre: %d \n",v4);
              for(j=0; j<4; j++){
                printf("Operateur: %c\n", operateurs[j]);
                sprintf(op, "%d %d %c", v1_2_3, v4, operateurs[j]);
                test = rpn_eval(op);
                printf("%d\n", test.result);
                
                if(test.result == ValeurCherche){
                  printf("La combinaison pour calculer le valeur est (en RPN): %d %c %d = %d \n", v1_2_3, operateurs[j], v4, test.result);
                  return 0;
                }
                if(test.result == -1) continue;
                v1_2_3_4=test.result;

                for(e=0; e<2; e++){
                  printf("\n Combinaison 1°,2°,3°,4°: %d \n",v1_2_3_4);
                  nombres_mod = dropfromTab(nombres, a, length);
                  nombres_mod = dropfromTab(nombres_mod, b, length-1);
                  nombres_mod = dropfromTab(nombres_mod, c, length-2);
                  nombres_mod = dropfromTab(nombres_mod, d, length-3);
                  v5 = nombres_mod[e];
                  printf("\nCinqième nombre: %d \n",v5);
                  for(j=0; j<4; j++){
                    printf("Operateur: %c\n", operateurs[j]);
                    sprintf(op, "%d %d %c", v1_2_3_4, v5, operateurs[j]);
                    test = rpn_eval(op);
                    printf("%d\n", test.result);
                    if(test.result == ValeurCherche){
                      printf("La combinaison pour calculer le valeur est (en RPN): %d %c %d = %d \n", v1_2_3_4, operateurs[j], v5, test.result);
                      return 0;
                    }
                    if(test.result == -1) continue;
                    v1_2_3_4_5=test.result;

                    for(f=0; f<1; f++){
                      printf("\n Combinaison 1°,2°,3°,4°,5°: %d \n",v1_2_3_4);
                      nombres_mod = dropfromTab(nombres, a, length);
                      nombres_mod = dropfromTab(nombres_mod, b, length-1);
                      nombres_mod = dropfromTab(nombres_mod, c, length-2);
                      nombres_mod = dropfromTab(nombres_mod, d, length-3);
                      nombres_mod = dropfromTab(nombres_mod, d, length-4);
                      v6 = nombres_mod[f];
                      printf("\nSixième nombre: %d \n",v6);
                      for(j=0; j<4; j++){
                        printf("Operador: %c\n", operateurs[j]);
                        sprintf(op, "%d %d %c", v1_2_3_4_5, v6, operateurs[j]);
                        test = rpn_eval(op);
                        printf("%d\n", test.result);
                        if(test.result == ValeurCherche){
                          printf("La combinaison pour calculer le valeur est (en RPN): %d %c %d = %d \n", v1_2_3_4_5, operateurs[j], v6, test.result);
                          return 0;
                        }
                      }
                    }
                  }
                } 
              }
            }
          }
        }
      }
    }
  } 

  return 0;
}

int* dropfromTab(int* tableau, int index, int length){
  
  int *new_tableau = (int*)malloc((length-1) * sizeof(int));
  int j = 0;
  
  for (int i = 0; i < length; i++){
    if(i == index) continue;
    new_tableau[j] = tableau[i];
    j++;
  }
  return new_tableau;
}
