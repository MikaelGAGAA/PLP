#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_INPUT_LEN 200
#define MAX_STACK_SIZE 100
#define MAX_VARS 100
#define MAX_NAME_LEN 100

// Structure pour les variables
typedef struct {
    char nom[MAX_NAME_LEN];
    int valeur;
    int est_definie;
} Variable;

Variable table_de_symboles[MAX_VARS];
int nb_variables = 0;

// Ajouter une variable dans la table de symboles
void definir_variable(const char* nom, int valeur) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(table_de_symboles[i].nom, nom) == 0) {
            table_de_symboles[i].valeur = valeur;
            table_de_symboles[i].est_definie = 1;
            return;
        }
    }
    strncpy(table_de_symboles[nb_variables].nom, nom, MAX_NAME_LEN);
    table_de_symboles[nb_variables].valeur = valeur;
    table_de_symboles[nb_variables].est_definie = 1;
    nb_variables++;
}

// Trouver une variable dans la table de symboles
int obtenir_valeur_variable(const char* nom, int* valeur) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(table_de_symboles[i].nom, nom) == 0 && table_de_symboles[i].est_definie) {
            *valeur = table_de_symboles[i].valeur;
            return 1;
        }
    }
    return 0;
}

// Vérification de la priorité des opérateurs
int priorite(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Fonction pour extraire l'expression mathématique de l'expression lambda
int extraire_lambda(const char* commande, char* expression, char* argument) {
    const char* debut = "(lambda x.";
    int longueur_debut = strlen(debut);
    
    // Vérifier que la commande commence par "(lambda x."
    if (strncmp(commande, debut, longueur_debut) != 0) {
        printf("Erreur : syntaxe incorrecte, l'expression doit commencer par '(lambda x.'\n");
        return 0;
    }

    // Trouver la parenthèse fermante qui termine l'expression
    const char* fin = strchr(commande + longueur_debut, ')');
    if (!fin) {
        printf("Erreur : syntaxe incorrecte, parenthèse fermante manquante.\n");
        return 0;
    }

    // Calculer la longueur de l'expression et l'extraire
    int longueur_expression = fin - (commande + longueur_debut);
    strncpy(expression, commande + longueur_debut, longueur_expression);
    expression[longueur_expression] = '\0';

    // Extraire l'argument après la parenthèse fermante
    sscanf(fin + 1, "%s", argument);

    return 1;
}

// Remplacer toutes les occurrences de 'x' par une valeur donnée dans l'expression
void remplacer_x(char* expression, const char* valeur) {
    char resultat[MAX_INPUT_LEN] = "";
    char* pos = expression;

    while ((pos = strstr(pos, "x")) != NULL) {
        strncat(resultat, expression, pos - expression); // Ajoute la partie avant 'x'
        strcat(resultat, valeur); // Remplace 'x' par la valeur
        pos += 1; // Passe le caractère 'x'
        expression = pos; // Avance dans l'expression
    }
    strcat(resultat, expression); // Ajoute le reste de l'expression
    strncpy(expression, resultat, MAX_INPUT_LEN); // Met à jour l'expression
}

// Convertir une expression infixée en notation postfixée
void infixeVersPostfixe(const char* infixe, char* postfixe) {
    char stack[MAX_STACK_SIZE];
    int top = -1;
    int k = 0;

    for (int i = 0; infixe[i]; i++) {
        char c = infixe[i];

        if (isdigit(c)) {
            postfixe[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfixe[k++] = stack[top--];
            }
            top--; // Retire la parenthèse ouvrante
        } else if (priorite(c) > 0) { // Si c'est un opérateur
            while (top != -1 && priorite(stack[top]) >= priorite(c)) {
                postfixe[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1) {
        postfixe[k++] = stack[top--];
    }
    postfixe[k] = '\0';
}

// Évaluer une expression postfixée
int evaluerPostfixe(const char* postfixe) {
    int stack[MAX_STACK_SIZE];
    int top = -1;

    for (int i = 0; postfixe[i]; i++) {
        char c = postfixe[i];

        if (isdigit(c)) {
            stack[++top] = c - '0'; // Convertir le caractère en entier
        } else {
            int val2 = stack[top--];
            int val1 = stack[top--];

            switch (c) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
    }
    return stack[top];
}

// Fonction pour évaluer une expression lambda avec un argument fourni
int evaluer_lambda(char* expression, const char* argument) {
    char valeur_remplacement[20];
    int valeur;

    // Vérifier si l'argument est un entier ou une variable définie
    if (sscanf(argument, "%d", &valeur) == 1) {
        snprintf(valeur_remplacement, sizeof(valeur_remplacement), "%d", valeur);
    } else if (obtenir_valeur_variable(argument, &valeur)) {
        snprintf(valeur_remplacement, sizeof(valeur_remplacement), "%d", valeur);
    } else {
        printf("Erreur : la variable %s n'est pas définie\n", argument);
        return 0; // Erreur
    }

    remplacer_x(expression, valeur_remplacement); // Remplace 'x' par la valeur

    // Conversion et évaluation
    char postfixe[MAX_INPUT_LEN];
    infixeVersPostfixe(expression, postfixe);
    return evaluerPostfixe(postfixe); // Renvoie le résultat de l'évaluation
}

int main() {
    setlocale(LC_ALL, "");

    char commande[MAX_INPUT_LEN];
    char expression[MAX_INPUT_LEN];
    char argument[MAX_INPUT_LEN];
    int resultat;

    // Définir une variable exemple
    definir_variable("y", 4); // Exemple de variable y = 4

    // Exemple d'une commande lambda
    printf("Entrez une expression : ");
    fgets(commande, MAX_INPUT_LEN, stdin);
    commande[strcspn(commande, "\n")] = '\0';

    // Extraction de l'expression et de l'argument
    if (extraire_lambda(commande, expression, argument)) {
        resultat = evaluer_lambda(expression, argument);
        printf("Résultat : %d\n", resultat);
    }

    return 0;
}
