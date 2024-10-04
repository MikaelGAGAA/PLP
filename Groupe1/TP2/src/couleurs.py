class Couleur:
    def __init__(self, r, g, b, a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

    def __eq__(self, other):
        return (self.r, self.g, self.b, self.a) == (other.r, other.g, other.b, other.a)

    def __hash__(self):
        return hash((self.r, self.g, self.b, self.a))

    def __str__(self):
        return f"{self.r:02x} {self.g:02x} {self.b:02x} {self.a:02x}"

def compter_occurrences(couleurs):
    occurrences = {}
    
    for couleur in couleurs:
        if couleur in occurrences:
            occurrences[couleur] += 1
        else:
            occurrences[couleur] = 1
    
    return occurrences

if __name__ == "__main__":
    # Liste de 100 couleurs (ajoutez d'autres couleurs si nécessaire)
    couleurs = [
        Couleur(0xff, 0x23, 0x23, 0x45),
        Couleur(0xff, 0x00, 0x23, 0x12),
        Couleur(0xff, 0x23, 0x23, 0x45),
        # Ajoutez d'autres couleurs ici
    ]
    
    # Comptage des occurrences
    occurrences = compter_occurrences(couleurs)
    
    # Affichage des résultats
    print("Couleurs distinctes et occurrences :")
    for couleur, count in occurrences.items():
        print(f"{couleur} : {count}")
