import sys

print(f"Taille de int : {sys.getsizeof(0)} octets")
print(f"Taille de float : {sys.getsizeof(0.0)} octets")
print(f"Taille de bool : {sys.getsizeof(True)} octets")
print(f"Taille de str (chaîne vide) : {sys.getsizeof('')} octets")
print(f"Taille de str (chaîne 'Bonjour') : {sys.getsizeof('Bonjour')} octets")
print(f"Taille de list (liste vide) : {sys.getsizeof([])} octets")
print(f"Taille de list ([1, 2, 3]) : {sys.getsizeof([1, 2, 3])} octets")
print(f"Taille de tuple (tuple vide) : {sys.getsizeof(())} octets")
print(f"Taille de tuple ((1, 2, 3)) : {sys.getsizeof((1, 2, 3))} octets")
print(f"Taille de dict (dictionnaire vide) : {sys.getsizeof({})} octets")
print(f"Taille de dict ({{'a': 1, 'b': 2}}) : {sys.getsizeof({'a': 1, 'b': 2})} octets")
