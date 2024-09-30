#include <stdio.h>

// Fonction pour calculer la longueur d'une chaîne
int longueur_chaine(const char* str) {
    int longueur = 0;
    while (str[longueur] != '\0') {  // Boucle jusqu'à rencontrer '\0'
        longueur++;
    }
    return longueur;
}

// Fonction pour copier une chaîne dans une autre
void copier_chaine(char* destination, const char* source) {
    int i = 0;
    while (source[i] != '\0') {  // Copie caractère par caractère
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';  // Ajout du caractère de fin de chaîne '\0'
}

// Fonction pour concaténer deux chaînes
void concatener_chaine(char* destination, const char* source1, const char* source2) {
    int i = 0, j = 0;

    // Copie de source1 dans destination
    while (source1[i] != '\0') {
        destination[i] = source1[i];
        i++;
    }

    // Ajout de source2 à la fin de destination
    while (source2[j] != '\0') {
        destination[i] = source2[j];
        i++;
        j++;
    }

    destination[i] = '\0';  // Ajout du caractère de fin de chaîne '\0'
}

int main() {
    // Test de la fonction longueur_chaine
    char chaine[] = "Bonjour";
    printf("Longueur de la chaîne '%s': %d\n", chaine, longueur_chaine(chaine));

    // Test de la fonction copier_chaine
    char source[] = "Salut";
    char destination[100];  // Assurez-vous que la destination a assez d'espace
    copier_chaine(destination, source);
    printf("Chaîne copiée: %s\n", destination);

    // Test de la fonction concatener_chaine
    char source1[] = "Bonjour";
    char source2[] = " le monde!";
    char destination_concat[100];  // Assurez-vous que la destination a assez d'espace
    concatener_chaine(destination_concat, source1, source2);
    printf("Chaîne concaténée: %s\n", destination_concat);

    return 0;
}
