#include <stdio.h>

int main() {
    
    char c = 'A';
    signed char sc = -100;
    unsigned char uc = 255;

    short s = -32768;
    unsigned short us = 65535;

    int i = -2147483648;
    unsigned int ui = 4294967295;

    long int li = -9223372036854775807L;
    unsigned long int uli = 18446744073709551615UL;

    long long int lli = -9223372036854775807LL;

    float f = 3.14F;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846L;

    printf("char : %c\n", c);
    printf("signed char : %d\n", sc);
    printf("unsigned char : %u\n", uc);

    printf("short : %d\n", s);
    printf("unsigned short : %u\n", us);

    printf("int : %d\n", i);
    printf("unsigned int : %u\n", ui);

    printf("long int : %ld\n", li);
    printf("unsigned long int : %lu\n", uli);

    printf("long long int : %lld\n", lli);

    printf("float : %f\n", f);
    printf("double : %lf\n", d);
    printf("long double : %Lf\n", ld);

    return 0;
}
