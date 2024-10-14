#include <stdio.h>
#include "lexer.h"
#include "parseur.h"
#include "evaluation.h"

int main() {
    char input[1024];
    printf("Entrez une expression arithmétique : ");
    fgets(input, sizeof(input), stdin);

    // Tokenization (Lexer)
    Token *tokens = tokenize(input);

    // Parsing (Parser)
    Expression expr = parse(tokens);

    // Evaluation
    double resultat = evaluer(expr);
    printf("Résultat : %f\n", resultat);

    // Libérer la mémoire
    free(tokens);

    return 0;
}

//Main principal

// Nous avons décomposé le problème en trois étapes majeures :

// Le tokenizeur, qui découpe la chaîne d'entrée en jetons ;
// Le parseur, qui transforme ces jetons en une représentation interne ;
// L'évaluateur, qui résout l'expression mathématique.
// Chaque étape gère ses propres erreurs et est modulaire pour permettre des ajouts futurs 
// (comme prendre en charge les parenthèses ou d'autres opérations). 
// N'hésite pas à poser des questions si tu veux plus de détails ou des clarifications sur une des parties !

