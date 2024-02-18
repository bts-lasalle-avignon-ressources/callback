#include <stdio.h>
#include <stdlib.h>

int somme(int, int);
int produit(int, int);
int operation(int, int, int(*)(int, int));

int somme(int a, int b)
{
    return (a + b);
}

int produit(int a, int b)
{
    return (a * b);
}

int operation(int a, int b, int (*f)(int, int))
{
    return ((*f)(a, b));
}

int main(int argc, char *argv[])
{
    int a = 2, b = 3;

    printf("%d + %d = %d\n", a, b, operation(a, b, somme));
    printf("%d x %d = %d\n", a, b, operation(a, b, produit));

    return 0;
}
