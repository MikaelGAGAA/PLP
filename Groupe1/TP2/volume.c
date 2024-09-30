// volume.c
// Ce fichier contient la fonction pour calculer le volume d'une sphère.

#include <math.h>    // Pour utiliser la constante M_PI
#include "sphere.h"  // Inclusion du fichier d'en-tête contenant les prototypes

// Fonction pour calculer le volume d'une sphère
float calculer_volume(float rayon) {
    return (4.0 / 3.0) * M_PI * pow(rayon, 3);  // Volume = 4/3 * π * r³
}
