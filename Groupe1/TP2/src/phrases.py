def compter_occurrences(ligne, phrase):
    return ligne.count(phrase)

def rechercher_phrase(nom_fichier, phrase):
    try:
        # Ouverture du fichier en mode lecture
        with open(nom_fichier, 'r', encoding='utf-8') as fichier:
            lignes = fichier.readlines()
            
        # Lecture et recherche dans chaque ligne
        for num_ligne, ligne in enumerate(lignes, start=1):
            occurrences = compter_occurrences(ligne, phrase)
            if occurrences > 0:
                print(f"Ligne {num_ligne}, {occurrences} fois")
                
    except FileNotFoundError:
        print(f"Le fichier {nom_fichier} n'existe pas.")

if __name__ == "__main__":
    # Demande du nom du fichier
    nom_fichier = input("Entrez le nom du fichier : ")
    
    # Demande de la phrase à rechercher
    phrase = input("Entrez la phrase que vous souhaitez rechercher : ")
    
    # Appel à la fonction de recherche
    rechercher_phrase(nom_fichier, phrase)
