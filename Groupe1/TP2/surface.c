// surface.c
// Ce fichier contient la fonction pour calculer la surface d'une sphère.

#include <math.h>    // Pour utiliser la constante M_PI
#include "sphere.h"  // Inclusion du fichier d'en-tête contenant les prototypes

// Fonction pour calculer la surface d'une sphère
float calculer_surface(float rayon) {
    return 4 * M_PI * rayon * rayon;  // Surface = 4 * π * r²
}
