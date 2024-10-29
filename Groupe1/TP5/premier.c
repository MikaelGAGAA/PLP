#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_VARS 100
#define MAX_NAME_LEN 100
#define MAX_INPUT_LEN 200

// Ex 5.1

// Enum pour les types de données
typedef enum {
    ENTIER,
    REEL,
    CHAINE
} Type;

// Structure pour une variable
typedef struct {
    char nom[MAX_NAME_LEN];
    Type type;
    union {
        int entier;
        double reel;
        char chaine[MAX_INPUT_LEN];
    } valeur;
    int est_definie;
} Variable;

// Table de symboles pour les variables
Variable table_de_symboles[MAX_VARS];
int nb_variables = 0;

// Trouver une variable dans la table
int trouver_variable(const char* nom) {
    for (int i = 0; i < nb_variables; i++) {
        if (strcmp(table_de_symboles[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Ajouter ou mettre à jour une variable dans la table
void definir_variable(const char* nom, Type type, void* valeur) {
    int index = trouver_variable(nom);

    // Nouvelle variable
    if (index == -1) {
        index = nb_variables++;
        strncpy(table_de_symboles[index].nom, nom, MAX_NAME_LEN);
        table_de_symboles[index].type = type;
        table_de_symboles[index].est_definie = 1;
    }
    // Si la variable existe déjà, vérifier le type
    else {
        if (table_de_symboles[index].type != type) {
            printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
            return;
        }
    }

    // Affecter la valeur selon le type si le type est correct
    if (type == ENTIER) {
        table_de_symboles[index].valeur.entier = *(int*)valeur;
    } else if (type == REEL) {
        table_de_symboles[index].valeur.reel = *(double*)valeur;
    } else if (type == CHAINE) {
        strncpy(table_de_symboles[index].valeur.chaine, (char*)valeur, MAX_INPUT_LEN);
    }

    // Afficher le message de confirmation
    printf("Variable %s définie avec la valeur ", nom);
    if (type == ENTIER) {
        printf("%d (entier)\n", table_de_symboles[index].valeur.entier);
    } else if (type == REEL) {
        printf("%lf (nombre réel)\n", table_de_symboles[index].valeur.reel);
    } else if (type == CHAINE) {
        printf("\"%s\" (chaîne de caractères)\n", table_de_symboles[index].valeur.chaine);
    }
}


// Obtenir la valeur d'une variable
void obtenir_variable(const char* nom) {
    int index = trouver_variable(nom);
    if (index == -1 || !table_de_symboles[index].est_definie) {
        printf("Erreur : la variable %s n'est pas définie\n", nom);
        return;
    }

    printf("Valeur de la variable %s : ", nom);
    if (table_de_symboles[index].type == ENTIER) {
        printf("%d\n", table_de_symboles[index].valeur.entier);
    } else if (table_de_symboles[index].type == REEL) {
        printf("%lf\n", table_de_symboles[index].valeur.reel);
    } else if (table_de_symboles[index].type == CHAINE) {
        printf("\"%s\"\n", table_de_symboles[index].valeur.chaine);
    }
}

// Fonction pour nettoyer le symbole '>' au début
void nettoyer_symbole_debut(char* commande) {
    if (commande[0] == '>' && isspace(commande[1])) {
        memmove(commande, commande + 2, strlen(commande) - 1);
    }
}

// Analyser et traiter la commande
void interpreter_commande(char* commande) {
    nettoyer_symbole_debut(commande);  // Nettoyer le symbole '> ' s'il est présent

    char nom[MAX_NAME_LEN];
    char valeur[MAX_INPUT_LEN];
    double reel;
    int entier;

    // Détection d'une affectation (exemple : x = 12)
    if (sscanf(commande, "%s = %s", nom, valeur) == 2) {
        int index = trouver_variable(nom);

        // Vérifier si la valeur est un nombre réel en priorité
        if (sscanf(valeur, "%lf", &reel) == 1 && strchr(valeur, '.')) {
            // Si la variable existe et son type ne correspond pas, afficher une erreur
            if (index != -1 && table_de_symboles[index].type != REEL) {
                printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
                return;
            }
            // Définir la variable comme réel
            definir_variable(nom, REEL, &reel);
        }
        // Vérifier si la valeur est un entier
        else if (sscanf(valeur, "%d", &entier) == 1) {
            // Si la variable existe et son type ne correspond pas, afficher une erreur
            if (index != -1 && table_de_symboles[index].type != ENTIER) {
                printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
                return;
            }
            // Définir la variable comme entier
            definir_variable(nom, ENTIER, &entier);
        }
        // Sinon, considérer que c'est une chaîne de caractères
        else if (valeur[0] == '"' && valeur[strlen(valeur) - 1] == '"') {
            valeur[strlen(valeur) - 1] = '\0'; // Retirer le guillemet de fin
            // Si la variable existe et son type ne correspond pas, afficher une erreur
            if (index != -1 && table_de_symboles[index].type != CHAINE) {
                printf("Erreur : changement de type non autorisé pour la variable %s\n", nom);
                return;
            }
            definir_variable(nom, CHAINE, valeur + 1); // Retirer le guillemet de début
        } else {
            printf("Erreur : valeur non reconnue\n");
        }
    }
    // Si une seule variable est saisie (exemple : x)
    else if (sscanf(commande, "%s", nom) == 1) {
        obtenir_variable(nom);
    } else {
        printf("Commande non reconnue\n");
    }
}




// Fonction principale de l'interpréteur
void interpreteur() {
    char commande[MAX_INPUT_LEN];

    while (1) {
        printf("> ");
        fgets(commande, MAX_INPUT_LEN, stdin);

        // Suppression du saut de ligne
        commande[strcspn(commande, "\n")] = '\0';

        // Quitter l'interpréteur
        if (strcmp(commande, "quit") == 0) {
            break;
        }

        // Traiter la commande saisie
        interpreter_commande(commande);
    }
}

int main() {
    setlocale(LC_ALL, ""); // Permet l'utilisation de l'UTF-8 pour les noms de variables
    printf("Bienvenue dans l'interpréteur avec gestion des variables. Tapez 'quit' pour sortir.\n");
    interpreteur();
    return 0;
}
