from typing import List
import pdb

def double_values(tableau: List[int]) -> None:
    for compteur in range(len(tableau)):
        tableau[compteur] *= 2
        pdb.set_trace()

    return tableau

# Créer un tableau d'exemple
tableau: List[int] = [1, 2, 3, 4, 5]

# Appeler la fonction et stocker le résultat
resultat = double_values(tableau)

# Afficher le résultat final
print(resultat)