// fichier: parseur.c
#include <stdio.h>
#include <stdlib.h>
#include "parseur.h"

// Fonction qui analyse les jetons et renvoie une expression arithmétique
Expression parse(Token *tokens) {
    Expression expr;
    int index = 0;

    // Vérification du premier opérande
    if (tokens[index].type != TOKEN_NUMBER) {
        printf("Erreur : opérande manquant.\n");
        exit(EXIT_FAILURE);
    }
    expr.operande1 = tokens[index].value;
    index++;

    // Vérification de l'opérateur
    if (tokens[index].type != TOKEN_OPERATOR) {
        printf("Erreur : opérateur manquant.\n");
        exit(EXIT_FAILURE);
    }
    expr.operation = tokens[index].op;
    index++;

    // Vérification du second opérande
    if (tokens[index].type != TOKEN_NUMBER) {
        printf("Erreur : deuxième opérande manquant.\n");
        exit(EXIT_FAILURE);
    }
    expr.operande2 = tokens[index].value;

    return expr;
}


// La fonction parse() va recevoir les jetons du tokenizeur et extraire les opérandes et l'opérateur de l'expression.