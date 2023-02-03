#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elt.h"
#include "list.h"
#include "stack_cld.h"

T_elt operation(int a, int b, char op);//qui fait les operations
T_elt operation(int a, int b, char op){
  T_elt out;
  switch(op){
    case SOMME:
        out.result = a + b;						
        break;
    case SOUSTRACTION:
        if(a-b<0){
          out.status=RESULTAT_NONENTIER;
          out.result=-1;
        }
        else{
          out.result = a - b;
          out.status='e';
        }
        break;
    case DIVISION:
        if(a%b!=0){
          out.status=RESULTAT_NONENTIER;
          out.result=-1;
        }
        else{
          out.result = a / b;
          out.status='e';
        }
        break;
    case MULTIPLICATION:
        out.result = a * b;
        out.status='e';
        break;
    }
  
  return out;
}

#ifdef IMPLEMENTATION_DYNAMIC_LINKED


T_list s2list(char *exp) {
  char *pt, op[100];
  strcpy(op, exp);
  // float num;
  T_node *Lista = NULL;
  pt = strtok(op, " ");
  T_elt e;

  while (pt != NULL) {
    if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
      e.result = -1;
      e.status = pt[0];
      Lista = tailAddNode(eltdup(e), Lista);
    } else {
      e.result = atoi(pt);
      e.status = OPERANDE; 
      Lista = tailAddNode(eltdup(e), Lista);      
    }
    //printf("%s\n", toString(e));
    pt = strtok(NULL, " ");
  }
  return Lista;
}


T_elt rpn_eval(char *exp){
  T_list Lista = NULL;
  Lista = s2list(exp);
  T_stack Pilha;
  Pilha = newStack();
  T_node *pAux = Lista;
  T_elt e, e1, e2, aux, aux2;
  aux.status = EXPRESSION_INVALIDE;
  aux.result = -1;
  
  while(pAux != NULL){

    e = pAux->data;

    if(e.status == OPERANDE){
      push(e, &Pilha);
    }
    else if(e.result == -1){
      if(getSize(Pilha) < 2) return aux;
      e2 = pop(&Pilha);
      e1 = pop(&Pilha);
      
    push(operation(e1.result, e2.result, e.status), &Pilha);

    }

    pAux = pAux->pNext;
  }
  
	if(Pilha != NULL && getSize(Pilha) == 1) {
    aux = top(&Pilha);
    aux.status = EXPRESSION_VALIDE;
        
    return aux;
  }
  else{
    return aux;
  }
  }


#endif

//-------------------------------------------------------------------------------------------------------


#ifdef IMPLEMENTATION_DYNAMIC_CONTIGUOUS

T_list s2list(char *exp) {
  char *pt, op[100];
  strcpy(op, exp);
  // float num;
  T_node *Lista = NULL;
  pt = strtok(op, " ");
  T_elt e;

  while (pt != NULL) {
    if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
      e.result = -1;
      e.status = pt[0];
      Lista = tailAddNode(eltdup(e), Lista);
    } else {
      e.result = atoi(pt);
      e.status = OPERANDE; 
      Lista = tailAddNode(eltdup(e), Lista);
    }
    //printf("%s\n", toString(e));
    pt = strtok(NULL, " ");
  }
  return Lista;
}

T_elt rpn_eval(char * exp){
    T_list Lista = NULL;
    Lista = s2list(exp);
    T_stack Pilha;
    Pilha = newStack();
    T_node *pAux = Lista;
    T_elt e, e1, e2, aux, aux2;
    aux.status = EXPRESSION_INVALIDE;
    aux.result = -1;
    
    while(pAux != NULL){

      e = pAux->data;

      if(e.status == OPERANDE){
        push(e, &Pilha);
      }
      else if(e.result == -1){
        if(getSize(Pilha) < 2) return aux;
        e2 = pop(&Pilha);
        e1 = pop(&Pilha);

        
     push(operation(e1.result, e2.result, e.status), &Pilha);


      }

      pAux = pAux->pNext;
    }

      if(Pilha != NULL && getSize(Pilha) == 1) {
      aux = top(&Pilha);
      aux.status = EXPRESSION_VALIDE;
      
      
      return aux;
    }
    else{
      return aux;
    }
    
    
}
#endif
//-------------------------------------------------------------------------------------------------------
#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS

T_list s2list(char * exp){
    char *pt, op[100];
    strcpy(op, exp);
    // float num;
    T_node *Lista = NULL;
    pt = strtok(op, " ");
    T_elt e;

    while (pt != NULL) {
      if (pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*') {
        e.result = -1;
        e.status = pt[0];
        Lista = tailAddNode(eltdup(e), Lista);
      } else {
        e.result = atoi(pt);
        e.status = OPERANDE; 
        Lista = tailAddNode(eltdup(e), Lista);
      }
      //printf("%s\n", toString(e));
      pt = strtok(NULL, " ");
    }
    return Lista;
  }

T_elt rpn_eval(char * exp){
    T_list Lista = NULL;
    Lista = s2list(exp);
    T_stack Pilha;
    Pilha = newStack();
    T_node *pAux = Lista;
    T_elt e, e1, e2, aux, aux2;
    aux.status = EXPRESSION_INVALIDE;
    aux.result = -1;
    
    while(pAux != NULL){

      e = pAux->data;

      if(e.status == OPERANDE){
        push(e, &Pilha);
      }
      else if(e.result == -1){
        if(getSize(Pilha) < 2) return aux;
        e2 = pop(&Pilha);
        e1 = pop(&Pilha);

        
				push(operation(e1.result, e2.result, e.status), &Pilha);
			
			}

      pAux = pAux->pNext;
    }
   
      if(Pilha != NULL && getSize(Pilha) == 1) {
      aux = top(&Pilha);
      aux.status = EXPRESSION_VALIDE;
      return aux;
    }
    else{
      return aux;
    }
	}

#endif
//#endif
//-------------------------------------------------------------------------------------------------------



