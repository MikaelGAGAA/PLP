#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Fonction pour donner la priorité des opérateurs
int priorite(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // Priorité pour les autres cas
}

// Fonction pour vérifier si un caractère est un opérateur
int estOperateur(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Fonction pour convertir une expression infixée en postfixée
void infixeVersPostfixe(char* infixe, char* postfixe) {
    char pile[MAX]; // Pile pour stocker les opérateurs
    int top = -1;   // Initialiser le sommet de la pile
    int k = 0;      // Indice pour le tableau postfixe

    for (int i = 0; i < strlen(infixe); i++) {
        char c = infixe[i];

        // Ignorer les espaces
        if (isspace(c)) {
            continue;
        }

        // Si c'est un opérande (nombre), l'ajouter à la sortie
        if (isdigit(c)) {
            postfixe[k++] = c;
        }
        // Si c'est une parenthèse ouvrante '('
        else if (c == '(') {
            pile[++top] = c; // Empile la parenthèse ouvrante
        }
        // Si c'est une parenthèse fermante ')'
        else if (c == ')') {
            // Dépiler jusqu'à rencontrer une parenthèse ouvrante '('
            while (top != -1 && pile[top] != '(') {
                postfixe[k++] = pile[top--];
            }
            top--; // Supprimer la parenthèse ouvrante '(' de la pile
        }
        // Si c'est un opérateur
        else if (estOperateur(c)) {
            // Dépiler les opérateurs de priorité supérieure ou égale
            while (top != -1 && priorite(pile[top]) >= priorite(c)) {
                postfixe[k++] = pile[top--];
            }
            pile[++top] = c; // Empile l'opérateur courant
        }
    }

    // Ajouter les opérateurs restants dans la pile à la sortie
    while (top != -1) {
        postfixe[k++] = pile[top--];
    }

    postfixe[k] = '\0'; // Fin de la chaîne de sortie
}

int main() {
    char infixe[MAX], postfixe[MAX];

    // Exemple d'entrée : "(3 + 4) * 5"
    printf("Entrez une expression infixee : ");
    fgets(infixe, MAX, stdin);

    // Conversion infixée -> postfixée
    infixeVersPostfixe(infixe, postfixe);

    // Affichage du résultat en notation postfixée
    printf("Expression en notation postfixee : %s\n", postfixe);

    return 0;
}
