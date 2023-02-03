//
//  list_v2.h
//  TEA3
//
//  Created by Vitória Bastos on 08/12/22.
//
#pragma once

#include "elt.h" // T_elt
#define DEBUG

#ifndef _LIST_H_
#define _LIST_H_

typedef struct node {
    T_elt data;
    struct node *pNext;
} T_node, * T_list;

T_node * addNode (T_elt e, T_node * n);
void showList(T_list l);
void freeList(T_list l);
T_elt getFirstElt(T_list l);
T_list removeFirstNode(T_list l);
void showList_rec(T_list l);
void showList_inv_rec(T_list l);
void freeList_rec(T_list l);

//New Methods
unsigned int getSizeIte(const T_list l);
unsigned int getSizeRec(const T_list l);
T_list tailAddNodeIte(T_elt e, T_list l);
T_list tailAddNodeRec(T_elt e, T_list l);
T_list sortAddNodeIte(T_elt e, T_list l);
T_list sortAddNodeRec(T_elt e, T_list l);
int inListIte(T_elt e, const T_list l);
int inListRec(T_elt e, const T_list l);
T_list removeDuplicatesIte(T_list l);
T_list removeDuplicatesRec(T_list l);


#endif 
