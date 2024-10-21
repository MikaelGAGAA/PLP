#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Fonction pour évaluer une expression postfixée
int evaluerPostfixe(char* postfixe) {
    int pile[MAX]; // Pile pour stocker les opérandes
    int top = -1;  // Pointeur sur le sommet de la pile

    for (int i = 0; postfixe[i] != '\0'; i++) {
        char c = postfixe[i];

        // Ignorer les espaces
        if (isspace(c)) {
            continue;
        }

        // Si c'est un opérande (nombre), l'ajouter à la pile
        if (isdigit(c)) {
            pile[++top] = c - '0';  // Convertir le caractère en entier et l'empiler
        }
        // Si c'est un opérateur
        else {
            // Dépiler les deux derniers opérandes
            int operande2 = pile[top--];
            int operande1 = pile[top--];

            // Effectuer l'opération en fonction de l'opérateur
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

            // Empiler le résultat
            pile[++top] = resultat;
        }
    }

    // Le résultat final est le dernier élément restant dans la pile
    return pile[top];
}

int main() {
    char postfixe[MAX];

    // Exemple d'entrée : "3 4 5 * +"
    printf("Entrez une expression postfixee : ");
    fgets(postfixe, MAX, stdin);

    // Évaluer l'expression postfixée
    int resultat = evaluerPostfixe(postfixe);

    // Afficher le résultat
    printf("Résultat de l'expression : %d\n", resultat);

    return 0;
}
