#include <stdio.h>
#include <stdlib.h>
#include "evaluation.h"

// Fonction pour évaluer une expression
double evaluer(Expression expr) {
    switch (expr.operation) {
        case '+':
            return expr.operande1 + expr.operande2;
        case '-':
            return expr.operande1 - expr.operande2;
        case '*':
            return expr.operande1 * expr.operande2;
        case '/':
            if (expr.operande2 == 0) {
                printf("Erreur : division par zéro.\n");
                exit(EXIT_FAILURE);
            }
            return expr.operande1 / expr.operande2;
        default:
            printf("Erreur : opérateur inconnu.\n");
            exit(EXIT_FAILURE);
    }
}
