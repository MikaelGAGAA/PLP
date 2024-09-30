#include <stdio.h>
//Divisible par 4 mais pas par 6

// int main() {
//     int i;
//     for( i=1; i<=1000; i++) {
//         if(i % 4==0 && i % 6 !=0) {
//             printf("%d ", i);
//         }
//     }
//     printf("\n");

//     return 0;
// }

// Divisible par 8 et pairs

// int main() {
//     int i;
//     for( i=1; i<=1000; i++) {
//         if(i % 2==0 && i % 8==0) {
//             printf("%d ", i);
//         }
//     }
//     printf("\n");

//     return 0;
// }

// Divisibilité par 5 ou 7 mais pas par 10 

int main() {
   
    for (int i = 1; i <= 1000; i++) {
        if ((i % 5 == 0 || i % 7 == 0) && i % 10 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
