#ifndef PARSEUR_H
#define PARSEUR_H

#include "lexer.h"

// Structure représentant une expression arithmétique
typedef struct {
    double operande1;
    double operande2;
    char operation; // '+', '-', '*', '/'
} Expression;

// Prototypes des fonctions du parseur
Expression parse(Token *tokens);

#endif // PARSEUR_H


// Le parseur analyse la liste de jetons et construit une représentation interne de l'expression (l'opération et les deux opérandes).