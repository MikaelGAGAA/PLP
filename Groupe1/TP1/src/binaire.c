#include <stdio.h>

int main() {
    int num, i;
    int bits[32]; // Tableau pour stocker les bits du nombre

    printf("Entrez un nombre entier : ");
    scanf("%d", &num);
    
    // Initialisation du tableau des bits
    for (i = 0; i < 32; i++) {
        bits[i] = 0;
    }
    
    i = 0;
    while (num > 0) {
        bits[i] = num % 2;  // Obtenir le bit de poids faible
        num = num / 2;      // Diviser le nombre par 2
        i++;
    }
    
    printf("Représentation binaire : ");
    for (i = 31; i >= 0; i--) {  
        printf("%d", bits[i]);
    }
    
    printf("\n");
    return 0;
}
