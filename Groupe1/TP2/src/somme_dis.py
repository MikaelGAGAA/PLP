import dis

def calculer_somme(n: int) -> int:
    somme = 0
    for i in range(n):
        somme += i
    return somme 


'''def calculer_somme(n: int) -> int:
       somme = 0
       i = 0
       while i < n:
           somme += i
           i += 1
       return somme
'''
def main() -> None:
    n = 10
    resultat = calculer_somme(n)
    print(f"La somme des entiers de 0 à {n-1} est {resultat}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_somme)
    main()

# avec la boucle FOR :
# LOAD_CONST               1 (0)    # Initialisation de la variable 'somme' à 0
# STORE_FAST               1 (somme)

# LOAD_FAST                0 (n)    # Charger l'argument 'n' pour l'itérer
# GET_ITER                          # Obtenir un itérateur sur la séquence range(n)
# FOR_ITER                14 (to 24) # Instruction pour commencer la boucle, se dirige vers la fin si l'itérateur est épuisé
# STORE_FAST               2 (i)    # Stocker la valeur actuelle de l'itérateur dans 'i'

# LOAD_FAST                1 (somme) # Charger la valeur actuelle de 'somme'
# LOAD_FAST                2 (i)    # Charger la valeur de 'i'
# INPLACE_ADD                      # Effectuer l'addition de 'somme' et 'i'
# STORE_FAST               1 (somme) # Stocker la nouvelle valeur de 'somme'

# JUMP_ABSOLUTE            8        # Retourner au début de la boucle (FOR_ITER)
# LOAD_FAST                1 (somme) # Charger la valeur finale de 'somme'
# RETURN_VALUE                     # Retourner la valeur finale
# 
# GET_ITER : Cette instruction est utilisée pour obtenir un itérateur de l'objet passé, dans ce cas, la séquence range(n). Elle transforme un objet iterable en itérateur, ce qui permet la boucle.
# FOR_ITER : C'est l'instruction principale qui contrôle la boucle. Elle récupère l'élément suivant de l'itérateur. Si l'itérateur est épuisé, il saute à la fin de la boucle.
# JUMP_ABSOLUTE : Une instruction de saut inconditionnel qui renvoie au début de la boucle pour effectuer l'itération suivante.
# INPLACE_ADD : Cette instruction effectue une addition entre deux valeurs et stocke le résultat dans la variable somme.
# RETURN_VALUE : Cette instruction renvoie la valeur finale calculée (la somme des entiers).

# Avec la boucle While :

#   3           0 LOAD_CONST               1 (0)    # Initialisation de 'somme'
#               2 STORE_FAST               1 (somme)
#               4 LOAD_CONST               1 (0)    # Initialisation de 'i'
#               6 STORE_FAST               2 (i)

#   4     >>    8 LOAD_FAST                2 (i)    # Charger 'i'
#              10 LOAD_FAST                0 (n)    # Charger 'n'
#              12 COMPARE_OP               0 (<)    # Comparer 'i' et 'n'
#              14 POP_JUMP_IF_FALSE       30        # Si 'i >= n', sauter à la fin (ligne 30)

#   5          16 LOAD_FAST                1 (somme) # Charger 'somme'
#              18 LOAD_FAST                2 (i)    # Charger 'i'
#              20 INPLACE_ADD                      # Ajouter 'i' à 'somme'
#              22 STORE_FAST               1 (somme) # Stocker la nouvelle valeur de 'somme'

#   6          24 LOAD_FAST                2 (i)    # Charger 'i'
#              26 LOAD_CONST               2 (1)    # Charger la constante 1
#              28 INPLACE_ADD                      # Incrementer 'i'
#              30 STORE_FAST               2 (i)    # Stocker la nouvelle valeur de 'i'
#              32 JUMP_ABSOLUTE            8        # Retourner à la ligne 8 pour continuer la boucle

#   7     >>   34 LOAD_FAST                1 (somme) # Charger 'somme' finale
#              36 RETURN_VALUE                     # Retourner la somme

# COMPARE_OP : Cette instruction compare les valeurs de i et n. Elle est utilisée pour vérifier la condition de la boucle while (dans ce cas, i < n).
# POP_JUMP_IF_FALSE : Si la comparaison retourne False, cette instruction saute à l’adresse spécifiée (ligne 30 dans ce cas), ce qui correspond à la fin de la boucle.
# INPLACE_ADD : Cette instruction est commune avec la boucle for. Elle ajoute i à somme directement sans créer un nouvel objet.
# JUMP_ABSOLUTE : C'est similaire à la boucle for, utilisée pour retourner au début de la boucle while (ligne 8) après l'incrémentation de i.
# SETUP_LOOP (non affichée ici) : Prépare l'environnement pour la gestion des exceptions dans une boucle (comme une boucle avec un break).
# POP_BLOCK (non affichée ici) : À la fin de la boucle, cette instruction est utilisée pour sortir du contexte de la boucle, en nettoyant la pile de contrôle.
# comparaison : 
# Boucle for : L'instruction FOR_ITER est plus optimisée car elle gère à la fois l'itération et le test de fin de boucle. 
# Elle est donc plus concise et n'a pas besoin de COMPARE_OP ou de POP_JUMP_IF_FALSE.
# Boucle while : Cette structure nécessite un test explicite de la condition avec COMPARE_OP et des instructions supplémentaires 
# pour gérer manuellement l'incrémentation de la variable d'itération (i).