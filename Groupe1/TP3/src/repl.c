#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Prototypes des fonctions pour les commandes
void afficher_version();
void afficher_aide();
void traiter_echo(char *commande);
void traiter_quit(int *continuer);
void afficher_date();
void to_lowercase(char *str);

// Structure pour lier les commandes à leurs fonctions
typedef struct {
    char *nom_commande;
    void (*fonction_sans_args)();
    void (*fonction_avec_args)(char *commande);
} Commande;

// Fonction pour convertir une chaîne en minuscules
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Fonction pour afficher la version de l'interpréteur
void afficher_version() {
    printf("Version 1.0 de l'interpréteur de commandes.\n");
}

// Fonction pour afficher l'aide
void afficher_aide() {
    printf("Commandes disponibles :\n");
    printf(" - echo <texte> : Affiche le texte saisi\n");
    printf(" - date : Affiche la date et l'heure actuelles\n");
    printf(" - version : Affiche la version de l'interpréteur\n");
    printf(" - aide/help : Affiche cette aide\n");
    printf(" - quitter/quit : Quitte l'interpréteur\n");
}

// Fonction pour traiter la commande echo
void traiter_echo(char *commande) {
    printf("Echo: ");
    for (int i = 5; commande[i] != '\0'; i++) {
        printf("%c", commande[i]);
    }
    printf("\n");
}

// Fonction pour traiter la commande quit/quitter
void traiter_quit(int *continuer) {
    printf("Arrêt...\n");
    *continuer = 0;
}

// Fonction pour afficher la date et l'heure actuelles
void afficher_date() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Date actuelle: %02d-%02d-%04d %02d:%02d:%02d\n",
           tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
           tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main() {
    int continuer = 1; // Variable pour contrôler la boucle principale

    // Tableau de commandes en anglais et en français
    Commande commandes[] = {
        {"version", afficher_version, NULL},
        {"help", afficher_aide, NULL},
        {"aide", afficher_aide, NULL},
        {"date", afficher_date, NULL},
        {"echo", NULL, traiter_echo},
        {"quit", (void (*)(char *))traiter_quit, NULL},
        {"quitter", (void (*)(char *))traiter_quit, NULL},
        {NULL, NULL, NULL} // Fin du tableau
    };

    // Boucle principale qui lit et traite les commandes utilisateur
    while (continuer) {
        printf("> "); // Affiche le prompt de commande

        // Buffer pour stocker la commande utilisateur
        char commande[1024];

        // Lit la commande utilisateur et la stocke dans le buffer
        fgets(commande, sizeof(commande), stdin);

        // Enlève le caractère de fin de ligne ajouté par fgets
        commande[strcspn(commande, "\n")] = 0;

        // Convertir la commande en minuscules pour gérer la casse
        to_lowercase(commande);

        // Traitement de la commande "quit" et "quitter" séparément
        if (strcmp(commande, "quit") == 0 || strcmp(commande, "quitter") == 0) {
            traiter_quit(&continuer);
            continue; // Retourne au début de la boucle
        }

        // Vérification et traitement des autres commandes
        int commande_reconnue = 0; // Variable pour vérifier si la commande est reconnue
        for (int i = 0; commandes[i].nom_commande != NULL; i++) {
            // Utiliser strcmp pour les commandes exactes sans arguments
            if (commandes[i].fonction_sans_args != NULL && strcmp(commande, commandes[i].nom_commande) == 0) {
                commandes[i].fonction_sans_args();  // Exécute la fonction sans arguments
                commande_reconnue = 1;
                break;
            }
            // Pour les commandes comme "echo" qui prennent des arguments, on utilise strncmp
            else if (commandes[i].fonction_avec_args != NULL && strncmp(commande, commandes[i].nom_commande, strlen(commandes[i].nom_commande)) == 0) {
                commandes[i].fonction_avec_args(commande);  // Exécute la fonction avec arguments
                commande_reconnue = 1;
                break;
            }
        }

        // Si la commande n'est pas reconnue
        if (!commande_reconnue) {
            printf("Commande non reconnue. Tapez 'aide' ou 'help' pour voir les commandes disponibles.\n");
        }

        printf("\n"); // Saut de ligne après la sortie
    }

    return 0;
}
