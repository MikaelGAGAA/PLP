import random

# Demander à l'utilisateur de saisir un nombre
taille = int(float(input("Saisissez un nombre : ")))

# Boucle principale pour chaque ligne
for i in range(1, taille + 1):
    # Boucle pour afficher les caractères sur chaque ligne
    for j in range(i):
        # Générer une valeur aléatoire pour décider entre "#" et "*"
        if random.randint(0, 1) == 0:
            print("#", end=" ")
        else:
            print("*", end=" ")
    print()  # Nouvelle ligne après chaque ligne de symboles
