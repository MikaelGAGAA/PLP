import math

rayon = float(input("Entrez le rayon du cercle : "))

aire = math.pi * rayon * rayon
perimetre = 2 * math.pi * rayon

print(f"L'aire du cercle est : {aire:.2f}")   #pour n'avoir que 2 chiffres après la virgule
print("Le périmètre du cercle est : ", perimetre)
