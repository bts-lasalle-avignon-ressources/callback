#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int rechercher(int t[], size_t taille, bool (*callback)(int element, int valeur), int valeur)
{
    int index = -1;
    
    for(int i = 0; i < taille; i++)
    {
        if(callback(t[i], valeur))
            //index = i;
            return i;
    }
     
    return index;
}

bool egale(int element, int valeur)
{
    if(element == valeur)
    {
        return true;
    }
    
    return false;
}

bool plusGrande(int element, int valeur)
{
    if(element > valeur)
    {
        return true;
    }
    
    return false;
}

bool plusPetite(int element, int valeur)
{
    if(element < valeur)
    {
        return true;
    }
    
    return false;
}

int main(int argc, char *argv[])
{
    const int taille = 5;
    int t[] = {1, 2, 3, 4, 5};

    printf("== 0 ? position = %d\n", rechercher(t, taille, egale, 0));
    printf("== 2 ? position = %d\n", rechercher(t, taille, egale, 2));
    printf("== 5 ? position = %d\n", rechercher(t, taille, egale, 5));
    printf("== 10 ? position = %d\n", rechercher(t, taille, egale, 10));

    printf("> 0 ? position = %d\n", rechercher(t, taille, plusGrande, 0));
    printf("> 2 ? position = %d\n", rechercher(t, taille, plusGrande, 2));
    printf("> 5 ? position = %d\n", rechercher(t, taille, plusGrande, 5));
    printf("> 10 ? position = %d\n", rechercher(t, taille, plusGrande, 10));

    printf("< 0 ? position = %d\n", rechercher(t, taille, plusPetite, 0));
    printf("< 2 ? position = %d\n", rechercher(t, taille, plusPetite, 2));
    printf("< 5 ? position = %d\n", rechercher(t, taille, plusPetite, 5));
    printf("< 10 ? position = %d\n", rechercher(t, taille, plusPetite, 10));

    return 0;
}
