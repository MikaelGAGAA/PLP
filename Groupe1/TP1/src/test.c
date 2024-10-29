#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    float taille;

    printf("saisissez un nombre :\n");
    scanf("%f", &taille);
    srand(time(NULL)); // Initialisation de l'aléatoire
    
    for (int i = 1; i<=taille; i++) {
        for(int j = 1; j<= i; j++){

         int random_value = rand() % 2;

            if (random_value == 0) {
                
                printf("# ");
            }
            else {
                printf("* ");
            }
        }
    printf("\n");
    }
    return 0;
}
