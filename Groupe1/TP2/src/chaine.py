# Fonction pour calculer la longueur d'une chaîne
def longueur_chaine(chaine):
    longueur = 0
    for _ in chaine:  # Parcourt chaque caractère jusqu'à la fin
        longueur += 1
    return longueur

# Fonction pour copier une chaîne dans une autre
def copier_chaine(source):
    destination = ''  # Crée une nouvelle chaîne vide
    for char in source:  # Ajoute chaque caractère de la source à la destination
        destination += char
    return destination

# Fonction pour concaténer deux chaînes
def concatener_chaine(chaine1, chaine2):
    resultat = ''  # Crée une chaîne vide pour le résultat
    for char in chaine1:  # Copie la première chaîne dans le résultat
        resultat += char
    for char in chaine2:  # Ajoute la deuxième chaîne à la suite de la première
        resultat += char
    return resultat

# Fonction principale
def main():
    # Demander à l'utilisateur de saisir deux chaînes
    chaine1 = input("Entrez la première chaîne : ")
    chaine2 = input("Entrez la deuxième chaîne : ")

    # Calcul de la longueur des chaînes
    print(f"Longueur de la première chaîne ('{chaine1}'): {longueur_chaine(chaine1)}")
    print(f"Longueur de la deuxième chaîne ('{chaine2}'): {longueur_chaine(chaine2)}")

    # Copie de la première chaîne
    copie_chaine1 = copier_chaine(chaine1)
    print(f"Copie de la première chaîne : {copie_chaine1}")

    # Concaténation des deux chaînes
    chaine_concatenee = concatener_chaine(chaine1, chaine2)
    print(f"Concaténation des deux chaînes : {chaine_concatenee}")

# Appeler la fonction principale
if __name__ == "__main__":
    main()
