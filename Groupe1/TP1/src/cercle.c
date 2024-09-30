// #include <stdio.h>

// #define PI 3.14159

// int main() {
//     float rayon, aire, perimetre;

//     printf("Entrez le rayon du cercle : ");
//     scanf("%f", &rayon);

//     aire = PI * rayon * rayon;
//     perimetre = 2 * PI * rayon;

//     printf("L'aire du cercle est : %.2f\n", aire);
//     printf("Le périmètre du cercle est : %.2f\n", perimetre);

//     return 0;
// }

#include <stdio.h>

int main() {

    float aire, perimetre, rayon, pi;

    pi = 3.14159;

    printf("Entrez le rayon du cercle: ");
    scanf("%f", &rayon);

    aire = pi*rayon*rayon;

    perimetre = 2*pi*rayon;

    printf("l'aire du cercle est : %f\n", aire);

    printf("le perimetre du cercle est : %f\n", perimetre);

    return 0;
}
