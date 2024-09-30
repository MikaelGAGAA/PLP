num = int(input("Entrez un nombre entier : "))

if num == 0:
    print("Représentation binaire : 0")
else:
    # Initialiser une chaîne vide pour stocker les bits
    binary_representation = ""

    # Boucle pour convertir le nombre en binaire
    while num > 0:
        bit = num % 2  # Obtenir le bit de poids faible
        binary_representation = str(bit) + binary_representation  # Ajouter le bit au début de la chaîne
        num = num // 2

    print(f"Représentation binaire : {binary_representation}")
