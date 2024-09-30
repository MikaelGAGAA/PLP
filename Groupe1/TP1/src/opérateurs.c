#include <stdio.h>

int main() {
    
    int a = 16;
    int b = 3;

    // Addition
    printf("Addition : %d + %d = %d\n", a, b, a + b);

    // Soustraction
    printf("Soustraction : %d - %d = %d\n", a, b, a - b);

    // Multiplication
    printf("Multiplication : %d * %d = %d\n", a, b, a * b);

    // Division
    printf("Division : %d / %d = %d\n", a, b, a / b);  // Division entière

    // Modulo
    printf("Modulo : %d %% %d = %d\n", a, b, a % b);  // %% pour afficher %

    // Vérifier si a est égal à b
    printf("a == b : %d\n", a == b);  // Affiche 1 si vrai, 0 sinon

    // Vérifier si a est supérieur à b
    printf("a > b : %d\n", a > b);  // Affiche 1 si vrai, 0 sinon

    return 0;
}
