#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 100

// Ex 4.4

// Structure de pile pour stocker les opérandes
typedef struct {
    int data[MAX];
    int top;
} Pile;

// Initialiser la pile (sommet à -1)
void initPile(Pile* pile) {
    pile->top = -1;
}

// Vérifier si la pile est vide
int estVide(Pile* pile) {
    return pile->top == -1;
}

// Empiler un élément sur la pile
void empiler(Pile* pile, int valeur) {
    if (pile->top < MAX - 1) {
        pile->data[++(pile->top)] = valeur;
    } else {
        printf("Erreur : Pile pleine\n");
    }
}

// Dépiler un élément de la pile
int depiler(Pile* pile) {
    if (!estVide(pile)) {
        return pile->data[(pile->top)--];
    } else {
        printf("Erreur : Pile vide\n");
        return 0;
    }
}

// Donner la priorité des opérateurs pour l'évaluation
int priorite(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Vérifier si un caractère est un opérateur
int estOperateur(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convertir une expression infixée en postfixée
void infixeVersPostfixe(char* infixe, char* postfixe) {
    char pile[MAX];
    int top = -1;
    int k = 0;

    for (int i = 0; i < strlen(infixe); i++) {
        char c = infixe[i];

        if (isspace(c)) {
            continue; // Ignorer les espaces
        }

        if (isdigit(c)) {
            postfixe[k++] = c; // Ajouter les nombres directement
        } else if (c == '(') {
            pile[++top] = c; // Empiler les parenthèses ouvrantes
        } else if (c == ')') {
            // Dépiler jusqu'à rencontrer '('
            while (top != -1 && pile[top] != '(') {
                postfixe[k++] = pile[top--];
            }
            top--; // Retirer '(' de la pile
        } else if (estOperateur(c)) {
            // Dépiler les opérateurs de priorité supérieure ou égale
            while (top != -1 && priorite(pile[top]) >= priorite(c)) {
                postfixe[k++] = pile[top--];
            }
            pile[++top] = c; // Empiler l'opérateur actuel
        }
    }

    // Dépiler les opérateurs restants
    while (top != -1) {
        postfixe[k++] = pile[top--];
    }

    postfixe[k] = '\0'; // Terminer la chaîne postfixée
}

// Évaluer une expression en notation postfixée
int evaluerPostfixe(char* postfixe) {
    Pile pile;
    initPile(&pile);

    for (int i = 0; i < strlen(postfixe); i++) {
        char c = postfixe[i];

        if (isspace(c)) {
            continue; // Ignorer les espaces
        }

        if (isdigit(c)) {
            empiler(&pile, c - '0'); // Convertir et empiler les nombres
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operande2 = depiler(&pile); // Deuxième opérande
            int operande1 = depiler(&pile); // Premier opérande
            int resultat;

            // Calculer selon l'opérateur
            switch (c) {
                case '+': resultat = operande1 + operande2; break;
                case '-': resultat = operande1 - operande2; break;
                case '*': resultat = operande1 * operande2; break;
                case '/':
                    if (operande2 != 0) {
                        resultat = operande1 / operande2;
                    } else {
                        printf("Erreur : Division par zéro\n");
                        return 0;
                    }
                    break;
            }
            empiler(&pile, resultat); // Empiler le résultat
        }
    }
    return depiler(&pile); // Dernier élément : résultat final
}

// Fonction principale de l'interpréteur
void interpreteur() {
    char commande[MAX];
    char postfixe[MAX];

    while (1) {
        printf("> ");
        fgets(commande, MAX, stdin);

        // Retirer le saut de ligne de la commande
        commande[strcspn(commande, "\n")] = '\0';

        // Commande pour quitter l'interpréteur
        if (strcmp(commande, "quit") == 0) {
            break;
        }

        // Détection d'une expression arithmétique
        int est_expression_arithmetique = 0;
        for (int i = 0; i < strlen(commande); i++) {
            if (estOperateur(commande[i]) || isdigit(commande[i])) {
                est_expression_arithmetique = 1;
                break;
            }
        }

        if (est_expression_arithmetique) {
            // Convertir et évaluer l'expression
            infixeVersPostfixe(commande, postfixe);
            int resultat = evaluerPostfixe(postfixe);
            printf("Résultat : %d\n", resultat);
        } else {
            printf("Commande non reconnue : %s\n", commande);
        }
    }
}

int main() {
    printf("Bienvenue dans l'interpréteur. Tapez 'quit' pour sortir.\n");
    interpreteur();
    return 0;
}
