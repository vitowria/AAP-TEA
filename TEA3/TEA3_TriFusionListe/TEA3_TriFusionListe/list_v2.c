//
//  list_v2.c
//  TEA3
//
//  Created by Vitória Bastos on 08/12/22.
//

#include <assert.h>

//#define CLEAR2CONTINUE
#include "include/traces.h"

//#define DEBUG
#include "include/check.h"

//#include "elt.h" // T_elt
#include "list_v2.h" // prototypes
#include "elt.h" // T_elt

/*
typedef struct node {
    T_elt data;
    struct node *pNext;
} T_node, * T_list;
*/

static T_node * newNode(T_elt e) {
    // Créer une nouvelle cellule contenant l'élément e

    T_node * pNode;
    CHECK_IF(pNode = malloc(sizeof(T_node)), NULL, "malloc allocateNode");
    pNode->data = e;
    pNode->pNext = NULL;

    return pNode;
}

T_node * addNode (T_elt e, T_node * n) {
    // Créer une maille (node), la remplir
    // et l'accrocher en tête d'une liste existante (ou vide)
    // Renvoyer la nouvelle tête

    T_node * pNode;
    pNode = newNode(e);
    pNode->pNext = n;
    return pNode;
}

void showList(T_list l) {
    // Afficher la liste en commençant par sa tête
    // A faire en itératif

    if (l==NULL) {
        printf("Liste Vide !\n");
        return;
    }

    while(l != NULL) {
        printf("%s ", toString(l->data));
        l = l->pNext;
    }
}

void freeList(T_list l) {
    // Libérer la mémoire de toutes les cellules de la liste l
    // A faire en itératif

    T_node * pAux;
    // Il faut un pointeur auxiliaire :
    // on ne doit libérer qu'après avoir enregistré quelque part
    // l'adresse de la maille suivante

    assert(l != NULL);

    while(l != NULL) {
        #ifdef DEBUG
        printf("Freeing %s\n", toString(l->data));
        #endif
        
        pAux = l->pNext;
        free(l);
        l = pAux;
    }
}

T_elt getFirstElt(T_list l) {
    // Renvoyer l'élément contenu dans la cellule de tête de la liste

    assert(l != NULL);

    return l->data;
}

T_list removeFirstNode(T_list l) {
    // Supprimer la tête de la liste
    // Renvoyer la nouvelle liste privée de sa première cellule

    assert(l!= NULL);
    T_node * p =l->pNext;
    free(l);
    return p;
}

// A produire en version récursive (+ tard dans le sujet)

void showList_rec(T_list l) {
    // Afficher la liste en commençant par sa tête
    // A faire en récursif

    if (l == NULL) {
        // case de base
        return;
    } else {
        // cas général
        printf("%s ", toString(l->data));
        showList_rec(l->pNext);
    }
}

void showList_inv_rec(T_list l) {
    // Afficher la liste en commençant par sa queue
    // A faire en récursif

    if (l == NULL) {
        // case de base
        return;
    } else {
        // cas général
        showList_inv_rec(l->pNext);
        printf("%s ", toString(l->data));
    }
}

void freeList_rec(T_list l) {
    // Libérer la mémoire de toutes les cellules de la liste l
    // A faire en récursif

    if (l == NULL) {
        return;
    } else {
        freeList_rec(l->pNext);
        printf("Libération de %s\n",toString(l->data));
        free(l);
    }
}


/*            New Methods            */

unsigned int getSizeIte(const T_list l){

    int size = 0;
    T_list aux = l;
    while(aux!=NULL){
        size++;
        aux = aux->pNext;
    }

    return size;
}

unsigned int getSizeRec(const T_list l){

    if(l != NULL) return 1 + getSizeRec(l->pNext);
    else return 0;
}

T_list tailAddNodeIte(T_elt e, T_list l){

    if(l!=NULL){
        T_list aux = l;
        while(aux->pNext!=NULL){
            aux = aux->pNext;
        }

        aux->pNext = newNode(e);
        return l;
    }
    else return newNode(e);
}

T_list tailAddNodeRec(T_elt e, T_list l){

    if(l == NULL) return newNode(e);
    l->pNext = tailAddNodeRec(e, l->pNext);

    return l;
}


T_list sortAddNodeIte(T_elt e, T_list l){

    if(l!=NULL){
        T_list next, aux = l;

        while(aux && aux->pNext && e > aux->pNext->data){
            aux = aux->pNext;
        }

        next = aux->pNext;
        aux->pNext = newNode(e);
        aux->pNext->pNext = next;

        return l;
    }
    else return newNode(e);
}

T_list sortAddNodeRec(T_elt e, T_list l){

    if(l && l->pNext){
        if(l->pNext->data > e){
            T_list next = l ->pNext;
            l->pNext = newNode(e);
            l->pNext->pNext = next;
            return l;
        }
        else return addNode(l->data, sortAddNodeRec(e, l->pNext));
    }
    else{
        l->pNext = newNode(e);
        return l;
    }
}

int inListIte(T_elt e, const T_list l){

    T_list aux = l;
    while(aux!=NULL){
        if(aux->data == e) return 1;
        aux = aux->pNext;
    }

    return 0;
}

int inListRec(T_elt e, const T_list l){
    T_list aux = l;

    if(aux != NULL) {
        return (e == aux->data) || inListRec(e,aux->pNext);
    }
    else return 0;
}

T_list removeDuplicatesIte(T_list l){

    T_list unique = NULL, aux = l;
    while(aux!=NULL){
        
        if(inListIte(aux->data, unique)){
            #ifdef DEBUG
            printf("Removing %d\n", aux->data);
            #endif
        }
        else{
            unique = tailAddNodeRec(aux->data, unique);
        }
        aux = aux->pNext;
    }

    if(l != NULL) freeList(l);

    return unique;
}

T_list removeDuplicatesRec(T_list l){
    if(l != NULL){
        if(inListRec(l->data,l->pNext))
            return removeDuplicatesRec(removeFirstNode(l));
        l->pNext = removeDuplicatesRec(l->pNext);
    }
    return l;
}
