#include <stdio.h>
#include <string.h>

#define TAILLE_TABLEAU 100

// Définition de la structure Couleur
typedef struct {
    unsigned char r, g, b, a;
} Couleur;

// Définition de la structure pour les couleurs distinctes
typedef struct {
    Couleur couleur;
    int occurrences;
} CouleurDistincte;

// Fonction pour comparer deux couleurs
int comparer_couleurs(Couleur c1, Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

// Fonction pour ajouter ou mettre à jour une couleur distincte
void ajouter_couleur(CouleurDistincte distinctes[], int *taille_distinctes, Couleur nouvelle_couleur) {
    for (int i = 0; i < *taille_distinctes; i++) {
        if (comparer_couleurs(distinctes[i].couleur, nouvelle_couleur)) {
            distinctes[i].occurrences++;
            return;
        }
    }
    
    // Si la couleur n'existe pas encore, on l'ajoute
    distinctes[*taille_distinctes].couleur = nouvelle_couleur;
    distinctes[*taille_distinctes].occurrences = 1;
    (*taille_distinctes)++;
}

int main() {
    // Tableau de 100 couleurs
    Couleur tableau[TAILLE_TABLEAU] = {
        {0xff, 0x23, 0x23, 0x45},
        {0xff, 0x00, 0x23, 0x12},
        {0xff, 0x23, 0x23, 0x45},
        // Ajoutez d'autres couleurs ici
    };
    
    // Tableau pour stocker les couleurs distinctes
    CouleurDistincte distinctes[TAILLE_TABLEAU];
    int taille_distinctes = 0;

    // Parcours du tableau de couleurs et comptage des occurrences
    for (int i = 0; i < TAILLE_TABLEAU && tableau[i].r != 0; i++) {
        ajouter_couleur(distinctes, &taille_distinctes, tableau[i]);
    }

    // Affichage des couleurs distinctes et de leurs occurrences
    printf("Couleurs distinctes et occurrences :\n");
    for (int i = 0; i < taille_distinctes; i++) {
        printf("%02x %02x %02x %02x : %d\n", 
            distinctes[i].couleur.r, distinctes[i].couleur.g, 
            distinctes[i].couleur.b, distinctes[i].couleur.a, 
            distinctes[i].occurrences);
    }

    return 0;
}
