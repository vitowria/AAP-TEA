#ifndef rpn_h
#define rpn_h

#include <stdio.h>
#include <string.h>
#include "include/check.h"



#include "elt.h"    // T_elt
#include "list.h"    // T_list, T_node
#include "stack_cld.h" // Pile Methods


//#define IMPLEMENTATION_STATIC_CONTIGUOUS
//#define IMPLEMENTATION_DYNAMIC_CONTIGUOUS
#define IMPLEMENTATION_DYNAMIC_LINKED

#ifdef IMPLEMENTATION_DYNAMIC_LINKED

T_list s2list(char * exp);//qui transforme une expression RPN sous forme de chaîne de caractères en une liste de T_elt
T_elt rpn_eval(char * exp);//qui évalue une expression RPN

#endif

////////////////////////////////////////////////////////////////////

#ifdef IMPLEMENTATION_DYNAMIC_CONTIGUOUS

T_list s2list(char * exp);//qui transforme une expression RPN sous forme de chaîne de caractères en une liste de T_elt
T_elt rpn_eval(char * exp);//qui évalue une expression RPN

#endif
#endif /* rpn_h */

/////////////////////////////////////////////////////////////////////

#ifdef IMPLEMENTATION_STATIC_CONTIGUOUS

T_list s2list(char * exp);//qui transforme une expression RPN sous forme de chaîne de caractères en une liste de T_elt
T_elt rpn_eval(char * exp);//qui évalue une expression RPN

#endif

//////////////////////////////////////////////////////////////////
//#endif /* rpn_h */
//#endif /* rpn_h */