#Divisible par 4 mais pas par 6

print("Nombres divisibles par 4 mais pas par 6 :\n")
for i in range(1, 1001):
    if i % 4 == 0 and i % 6 != 0:
        print(i, end=" ")
print()

#Divisible par 8 et pairs

print("\nNombres pairs et divisibles par 8 :\n")
for i in range(1, 1001):
    if i % 2 == 0 and i % 8 == 0:
        print(i, end=" ")
print()

#Divisibilité par 5 ou 7 mais pas par 10 

print("\nNombres divisibles par 5 ou 7 mais pas par 10 :\n")
for i in range(1, 1001):
    if (i % 5 == 0 or i % 7 == 0) and i % 10 != 0:
        print(i, end=" ")
print()
