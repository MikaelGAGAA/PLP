#include <stdio.h>
#include <string.h>

// Définition de la structure Etudiant
struct Etudiant {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float notes[3];  // Par exemple, trois notes
};

// Fonction pour saisir les informations d'un étudiant
void saisir_etudiant(struct Etudiant* etudiant) {
    printf("Saisir le nom : ");
    scanf("%s", etudiant->nom);
    
    printf("Saisir le prénom : ");
    scanf("%s", etudiant->prenom);
    
    printf("Saisir l'adresse : ");
    scanf(" %[^\n]s", etudiant->adresse);  // Permet la saisie d'une adresse avec espaces

    for (int i = 0; i < 3; i++) {
        printf("Saisir la note %d : ", i + 1);
        scanf("%f", &etudiant->notes[i]);
    }
}

// Fonction pour afficher les informations d'un étudiant
void afficher_etudiant(const struct Etudiant* etudiant) {
    printf("Nom: %s\n", etudiant->nom);
    printf("Prénom: %s\n", etudiant->prenom);
    printf("Adresse: %s\n", etudiant->adresse);
    printf("Notes: %.2f, %.2f, %.2f\n", etudiant->notes[0], etudiant->notes[1], etudiant->notes[2]);
}

int main() {
    struct Etudiant etudiants[5];

    // Saisie des informations pour 5 étudiants
    for (int i = 0; i < 5; i++) {
        printf("Saisie des informations de l'étudiant %d\n", i + 1);
        saisir_etudiant(&etudiants[i]);
        printf("\n");
    }

    // Affichage des informations des 5 étudiants
    printf("Affichage des informations des étudiants :\n");
    for (int i = 0; i < 5; i++) {
        printf("\nInformations de l'étudiant %d:\n", i + 1);
        afficher_etudiant(&etudiants[i]);
    }

    return 0;
}
