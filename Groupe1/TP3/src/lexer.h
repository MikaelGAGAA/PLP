#ifndef LEXER_H
#define LEXER_H
// Chaque jeton sera un type structuré représentant un opérateur ou un nombre 
// Types de jetons
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_ERROR,
    TOKEN_END
} TokenType;

// Structure d'un jeton
typedef struct {
    TokenType type;
    double value;  // Pour les nombres
    char op;       // Pour les opérateurs
} Token;

// Prototypes des fonctions du lexer
Token *tokenize(const char *expression);

#endif // LEXER_H



//Le rôle du tokenizeur (ou lexer) est de découper une chaîne de caractères représentant une expression mathématique en éléments (ou jetons). 
//Chaque élément peut être un nombre, un opérateur, ou un caractère non valide à gérer en cas d'erreur.