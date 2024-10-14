#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"

Token *tokenize(const char *expression) {
    Token *tokens = malloc(100 * sizeof(Token)); // On alloue un tableau de jetons
    int index = 0;
    const char *ptr = expression;

    while (*ptr != '\0') {
        // Ignorer les espaces
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }

        // Traiter les nombres
        if (isdigit(*ptr) || *ptr == '.') {
            char *end;
            tokens[index].value = strtod(ptr, &end); // Convertir en nombre
            tokens[index].type = TOKEN_NUMBER;
            ptr = end; // Avancer le pointeur après le nombre
            index++;
            continue;
        }

        // Traiter les opérateurs
        if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            tokens[index].type = TOKEN_OPERATOR;
            tokens[index].op = *ptr;
            ptr++;
            index++;
            continue;
        }

        // Traiter les erreurs (caractères non valides)
        tokens[index].type = TOKEN_ERROR;
        tokens[index].op = *ptr; // On peut signaler quel caractère est incorrect
        index++;
        ptr++;
    }

    tokens[index].type = TOKEN_END; // Marquer la fin des jetons
    return tokens;
}


// parcourt la chaîne de caractères et identifie les différents jetons (nombres, opérateurs, ou erreurs).
// Dans le cas où un caractère non valide est rencontré, nous créons un jeton de type TOKEN_ERROR qui contient l'information sur l'erreur. 
// Lors de la phase de parsing, nous pourrons traiter ces erreurs.