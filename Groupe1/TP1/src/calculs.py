num1 = int(input("Entrez le premier nombre : "))
num2 = int(input("Entrez le deuxième nombre : "))
op = input("Entrez un opérateur (+, -, *, /, %, &, |, ~) : ")

match op:
    case '+':
        result = num1 + num2
        print(f"{num1} + {num2} = {result}")
    case '-':
        result = num1 - num2
        print(f"{num1} - {num2} = {result}")
    case '*':
        result = num1 * num2
        print(f"{num1} * {num2} = {result}")
    case '/':
        if num2 != 0:
            result = num1 / num2
            print(f"{num1} / {num2} = {result}")
        else:
            print("Erreur : Division par zéro.")
    case '%':
        if num2 != 0:
            result = num1 % num2
            print(f"{num1} % {num2} = {result}")
        else:
            print("Erreur : Modulo par zéro.")
    case '&':
        result = num1 & num2
        print(f"{num1} & {num2} = {result}")
    case '|':
        result = num1 | num2
        print(f"{num1} | {num2} = {result}")
    case '~':
        result = ~num1
        print(f"~{num1} = {result}")
    case _:
        print("Opérateur non reconnu.")
