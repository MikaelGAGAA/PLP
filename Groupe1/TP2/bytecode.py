import math
import dis

def calculer_aire(rayon: float) -> float:
    #return math.pi * rayon * rayon
    return 58.68                                       #Les instructions LOAD_FAST, BINARY_MULTIPLY, et autres opérations sont supprimées, 
                                #car Python n'a plus besoin d'exécuter ces calculs. Il se contente de charger une valeur constante et de la retourner.
def main() -> None:
    rayon : float = 5.0
    aire : float = calculer_aire(rayon)
    print(f"L'aire du cercle de rayon {rayon:.2f} est {aire:.2f}")

if __name__ == "__main__":
    # Utilisation de dis pour afficher le bytecode de la fonction
    dis.dis(calculer_aire)
    main()

#Chaque ligne dans cette sortie représente une instruction bytecode spécifique qui est exécutée par l'interpréteur Python.

#  0 LOAD_GLOBAL              0 (math)
#             2 LOAD_ATTR                1 (pi)
#               4 LOAD_FAST                0 (rayon)
#               6 BINARY_MULTIPLY
#               8 LOAD_FAST                0 (rayon)
#              10 BINARY_MULTIPLY
#              12 RETURN_VALUE
# L'aire du cercle de rayon 5.00 est 78.54

# LOAD_ATTR : Charge un attribut d'un objet. Par exemple, lorsque tu accèdes à math.pi, Python charge l'attribut pi de l'objet math.

# LOAD_CONST : Charge une constante, comme un nombre ou une chaîne de caractères, depuis la table des constantes dans la fonction.

# RETURN_VALUE : Renvoie la valeur au sommet de la pile comme résultat de la fonction.

# 2. Le bytecode devient plus court, car les opérations mathématiques et les chargements de variables sont supprimés. 
#Il se réduit à simplement charger la constante et la renvoyer, ce qui améliore l'efficacité de l'exécution.

# 3. a faire