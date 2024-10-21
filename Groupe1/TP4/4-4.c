#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Fonction pour donner la priorité des opérateurs
int priorite(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Fonction pour vérifier si un caractère est un opérateur
int estOperateur(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Fonction pour convertir une expression infixée en postfixée
void infixeVersPostfixe(char* infixe, char* postfixe) {
    char pile[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; i < strlen(infixe); i++) {
        char c = infixe[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            postfixe[k++] = c;
        } else if (c == '(') {
            pile[++top] = c;
        } else if (c == ')') {
            while (top != -1 && pile[top] != '(') {
                postfixe[k++] = pile[top--];
            }
            top--; // Retirer '(' de la pile
        } else if (estOperateur(c)) {
            while (top != -1 && priorite(pile[top]) >= priorite(c)) {
                postfixe[k++] = pile[top--];
            }
            pile[++top] = c;
        }
    }

    while (top != -1) {
        postfixe[k++] = pile[top--];
    }

    postfixe[k] = '\0';
}

// Fonction pour évaluer une expression postfixée
int evaluerPostfixe(char* postfixe) {
    int pile[MAX];
    int top = -1;

    for (int i = 0; postfixe[i] != '\0'; i++) {
        char c = postfixe[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            pile[++top] = c - '0';
        } else {
            int operande2 = pile[top--];
            int operande1 = pile[top--];

            int resultat;
            switch (c) {
                case '+':
                    resultat = operande1 + operande2;
                    break;
                case '-':
                    resultat = operande1 - operande2;
                    break;
                case '*':
                    resultat = operande1 * operande2;
                    break;
                case '/':
                    resultat = operande1 / operande2;
                    break;
                default:
                    printf("Opérateur inconnu : %c\n", c);
                    return -1;
            }

            pile[++top] = resultat;
        }
    }

    return pile[top];
}

// Fonction principale de l'interpréteur
int main() {
    char commande[MAX], postfixe[MAX];

    while (1) {
        printf("> "); // Afficher le prompt de commande
        fgets(commande, MAX, stdin);

        // Supprimer le saut de ligne de la commande saisie
        commande[strcspn(commande, "\n")] = 0;

        // Si la commande est "quit", quitter l'interpréteur
        if (strcmp(commande, "quit") == 0) {
            printf("Arrêt de l'interpréteur.\n");
            break;
        }

        // Vérifier si la commande contient une expression arithmétique
        int expression_arithmetique = 0;
        for (int i = 0; i < strlen(commande); i++) {
            if (estOperateur(commande[i]) || isdigit(commande[i])) {
                expression_arithmetique = 1;
                break;
            }
        }

        if (expression_arithmetique) {
            // Convertir l'expression infixée en postfixée
            infixeVersPostfixe(commande, postfixe);

            // Évaluer l'expression postfixée
            int resultat = evaluerPostfixe(postfixe);

            // Afficher le résultat
            printf("Résultat : %d\n", resultat);
        } else {
            printf("Commande non reconnue.\n");
        }
    }

    return 0;
}
