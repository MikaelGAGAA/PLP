#include <stdio.h>

int main() {
    int tableau[100];

    for (int compteur = 0; compteur < sizeof(tableau) / sizeof(tableau[0]); compteur++) {
        tableau[compteur] = compteur * 2;  // Par exemple, on peut initialiser avec des multiples de 2
    }

    return 0;
}
