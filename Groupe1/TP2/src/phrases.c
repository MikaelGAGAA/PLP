#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Fonction pour compter le nombre d'occurrences d'une sous-chaîne dans une chaîne
int compter_occurrences(const char *ligne, const char *phrase) {
    int count = 0;
    const char *tmp = ligne;
    while ((tmp = strstr(tmp, phrase)) != NULL) {
        count++;
        tmp += strlen(phrase); // Avancer après la phrase trouvée
    }
    return count;
}

int main() {
    char nom_fichier[100];
    char phrase[100];
    char ligne[MAX_LINE_LENGTH];
    FILE *fichier;
    int num_ligne = 0;
    
    // Demande du nom du fichier
    printf("Entrez le nom du fichier : ");
    scanf("%s", nom_fichier);
    
    // Demande de la phrase à rechercher
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    scanf(" %[^\n]", phrase);
    
    // Ouverture du fichier
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return 1;
    }
    
    // Lecture du fichier ligne par ligne
    while (fgets(ligne, MAX_LINE_LENGTH, fichier) != NULL) {
        num_ligne++;
        int occurrences = compter_occurrences(ligne, phrase);
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, occurrences);
        }
    }
    
    // Fermeture du fichier
    fclose(fichier);
    
    return 0;
}
