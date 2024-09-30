#include <stdio.h>

int main() {
    int num1, num2;
    char op;
    int result;

    printf("Entrez le premier nombre : ");
    scanf("%d", &num1);
    
    printf("Entrez le deuxième nombre : ");
    scanf("%d", &num2);
    
    printf("Entrez un opérateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);

    switch(op) {
        case '+':
            result = num1 + num2;
            printf("%d + %d = %d\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%d * %d = %d\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%d / %d = %d\n", num1, num2, result);
            } else {
                printf("Erreur : Division par zéro.\n");
            }
            break;
        case '%':
            if (num2 != 0) {
                result = num1 % num2;
                printf("%d %% %d = %d\n", num1, num2, result);
            } else {
                printf("Erreur : Modulo par zéro.\n");
            }
            break;
        case '&':
            result = num1 & num2;
            printf("%d & %d = %d\n", num1, num2, result);
            break;
        case '|':
            result = num1 | num2;
            printf("%d | %d = %d\n", num1, num2, result);
            break;
        case '~':
            result = ~num1;
            printf("~%d = %d\n", num1, result);
            break;
        default:
            printf("Opérateur non reconnu.\n");
            break;
    }

    return 0;
}
