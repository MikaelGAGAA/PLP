#include <stdio.h>

int main() {
    // int taille;

    // // Demander la taille du triangle
    // printf("Entrez une valeur pour taille (strictement inférieure à 10) : ");
    // scanf("%d", &taille);

    // // Vérifier que la taille est valide
    // if (taille > 10 || taille <= 0) {
    //     printf("Erreur: la taille doit être strictement inférieure à 10 et positive.\n");
    //     return 1;
    // }

    // // Générer le triangle avec des boucles for
    // for (int i = 1; i <= taille; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         // Alternance entre * et #
    //         if (j % 2 == 0) {
    //             printf("# ");
    //         } else {
    //             printf("* ");
    //         }
    //     }
    //     printf("\n");  // Passer à la ligne suivante après chaque itération de la boucle interne
    // }

    // return 0;

 int taille, i = 1;

    // Demander la taille du triangle
    printf("Entrez une valeur pour taille (strictement inférieure à 10) : ");
    scanf("%d", &taille);

    // Vérifier que la taille est valide
    if (taille > 10 || taille <= 0) {
        printf("Erreur: la taille doit être strictement inférieure à 10 et positive.\n");
        return 1;
    }

    // Générer le triangle avec une boucle while
    while (i <= taille) {
        int j = 1;
        while (j <= i) {
            if (j % 2 == 0) {
                printf("# ");
            } else {
                printf("* ");
            }
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}

