#include <stdio.h> 

int main() {

   int tableau[100];

   for (int compteur = 0; compteur < sizeof(tableau) / sizeof(tableau[0]); compteur++) {
       tableau[compteur] = tableau[compteur] * 2;
   }

   return 0;
}
//Le premier programme se base uniquement sur la taille en octets, sans tenir compte de la taille des éléments, c'est l'erreur.