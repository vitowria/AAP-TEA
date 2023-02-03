#ifndef _ELT_H_
	#define _ELT_H_ // prévient les includes multiples

	/////////////////////////////////////////////////////////////////////////
	// CHOISIR ICI CE QUE REPRESENTE LE TYPE T_elt 
	//#define ELT_CHAR		// un caractère ?
	//#define ELT_INT		// un entier (choix par défaut) ?
	//#define ELT_RPN	
//une chaîne de caractères ?
	/////////////////////////////////////////////////////////////////////////

	//https://stackoverflow.com/questions/2998864/how-to-add-a-or-condition-in-ifdef

#define RESULTAT_ENTIER 'a'
#define RESULTAT_NONENTIER 'b'
#define RESULTAT_INTERMEDIARE 'f'
#define EXPRESSION_VALIDE 'c'
#define EXPRESSION_INVALIDE 'd'
#define SOMME '+'
#define SOUSTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'
#define OPERANDE 'e'    

	#if ! defined(ELT_CHAR) && ! defined(ELT_INT) && ! defined(ELT_STRING) && !defined(ELT_RPN)
	#define ELT_RPN
	#endif

	#ifdef ELT_CHAR
	typedef char T_elt;
	#endif

	#ifdef ELT_INT
	typedef int T_elt; 
	#endif

	#ifdef ELT_STRING
	typedef char * T_elt; 
	#endif
    
    #ifdef ELT_RPN
    typedef struct{
        int result;
        char status;
    } T_elt;
    #endif
	// valable pour tous les types de T_elt 
	
  char * toString(T_elt e); 
	T_elt genElt(void);
  T_elt eltdup(T_elt);
#endif 

