// main.c
// Ce fichier contient le point d'entrée principal du programme
// pour calculer et afficher le volume et la surface d'une sphère.

#include <stdio.h>   // Pour l'utilisation de printf
#include "sphere.h"  // Inclusion des prototypes des fonctions

int main() {
    float rayon = 5.0;  // Exemple de rayon

    // Appel des fonctions pour calculer le volume et la surface
    float surface = calculer_surface(rayon);
    float volume = calculer_volume(rayon);

    // Affichage des résultats
    printf("Pour une sphère de rayon %.2f :\n", rayon);
    printf("Surface = %.2f\n", surface);
    printf("Volume  = %.2f\n", volume);

    return 0;
}

// L'option -O3 active des optimisations plus agressives que -O2. Elle inclut l'inlining des petites fonctions 
//pour éviter les appels de fonction répétitifs, l'optimisation des boucles pour améliorer l'efficacité des calculs intensifs, 
//et d'autres techniques qui réduisent la taille du code ou améliorent la vitesse d'exécution. 
//Ces optimisations sont particulièrement bénéfiques dans des programmes qui effectuent des calculs mathématiques complexes, 
//comme c'est le cas ici avec le calcul de volumes et surfaces.Cela conclut la création et la compilation du programme.