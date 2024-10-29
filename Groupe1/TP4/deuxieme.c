#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Ex 4.3

// Structure de pile pour stocker les opérandes
typedef struct {
    int data[MAX];
    int top;
} Pile;

// Initialiser la pile
void initPile(Pile* pile) {
    pile->top = -1;
}

// Vérifier si la pile est vide
int estVide(Pile* pile) {
    return pile->top == -1;
}

// Empiler un élément
void empiler(Pile* pile, int valeur) {
    if (pile->top < MAX - 1) {
        pile->data[++(pile->top)] = valeur;
    } else {
        printf("Erreur : Pile pleine\n");
    }
}

// Dépiler un élément
int depiler(Pile* pile) {
    if (!estVide(pile)) {
        return pile->data[(pile->top)--];
    } else {
        printf("Erreur : Pile vide\n");
        return 0;
    }
}

// Fonction pour évaluer une expression postfixée
int evaluerPostfixe(char* postfixe) {
    Pile pile;
    initPile(&pile);

    for (int i = 0; i < strlen(postfixe); i++) {
        char c = postfixe[i];

        // Ignorer les espaces
        if (isspace(c)) {
            continue;
        }

        // Si c'est un opérande (nombre)
        if (isdigit(c)) {
            // Convertir le caractère en entier et l'empiler
            empiler(&pile, c - '0');
        }
        // Si c'est un opérateur
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Dépiler les deux derniers opérandes
            int operande2 = depiler(&pile);
            int operande1 = depiler(&pile);
            int resultat;

            // Effectuer l'opération en fonction de l'opérateur
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
            // Empiler le résultat
            empiler(&pile, resultat);
        }
    }

    // Le résultat final est le dernier élément de la pile
    return depiler(&pile);
}

int main() {
    char postfixe[MAX];

    // Exemple d'entrée
    printf("Entrez une expression en notation postfixee : ");
    fgets(postfixe, MAX, stdin);

    // Évaluation de l'expression postfixée
    int resultat = evaluerPostfixe(postfixe);

    // Affichage du résultat
    printf("Le resultat de l'expression est : %d\n", resultat);

    return 0;
}
