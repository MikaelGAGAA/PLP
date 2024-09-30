# # Demander à l'utilisateur de saisir la taille
# taille = int(input("Entrez une valeur pour taille (strictement inférieure à 10) : "))

# # Vérifier que la taille est correcte
# if taille > 10 or taille <= 0:
#     print("Erreur : la taille doit être strictement inférieure à 10 et positive.")
# else:
#     # Générer le triangle avec des boucles for
#     for i in range(1, taille + 1):
#         for j in range(1, i + 1):
#             # Alternance entre * et #
#             if j % 2 == 0:
#                 print("#", end=" ")
#             else:
#                 print("*", end=" ")
#         print()  # Passer à la ligne suivante après chaque itération
# Demander à l'utilisateur de saisir la taille

#avec while

taille = int(input("Entrez une valeur pour taille (strictement inférieure à 10) : "))

if taille >= 10 or taille <= 0:
    print("Erreur : la taille doit être strictement inférieure à 10 et positive.")
else:
    i = 1
    
    while i <= taille:
        j = 1
        while j <= i:
            
            if j % 2 == 0:
                print("#", end=" ")
            else:
                print("*", end=" ")
            j += 1
        print()  # Pour passer à la ligne suivante
        i += 1
