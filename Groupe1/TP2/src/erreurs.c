#include <stdio.h> 

int main() {

   int tableau[100];

   // Boucle pour parcourir les éléments du tableau
   for (int compteur = 0; compteur < sizeof(tableau) / sizeof(tableau[0]); compteur++) {
       tableau[compteur] = tableau[compteur] * 2;
   }

   return 0;
}
