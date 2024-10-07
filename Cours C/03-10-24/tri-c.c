#include <stdio.h>
#include <stdlib.h>
void printabl(int tab[], int taille)
{

    for (int i = 0; i < taille; i++)
    {
        printf("%d;", tab[i]);
    }
    printf("\n");
}

// on va inserer une valeur dans un tableau trié
void insertElementInTab(int *tab, int p, int element)
{
    int i = p - 1;
    while (i >= 0 && tab[i] > element)
    {
        tab[i + 1] = tab[i];
        i--;
    }

    tab[i + 1] = element;
}

void trieParInsertion(int *tab, int taille){

    int i;
    for(i=1; i < taille;i++)
    {     
        insertElementInTab(tab, i, tab[i]);
    }
}


// complexité : log de n ( en base 2 )
int dicho(int *tab, int taille, int e){

    int debut = 0;
    int fin = taille -1;
    int mid;
    while(debut < fin)
    {
        mid = (debut + fin)/2;
        if(tab[mid] == e){
            return mid;
        }
        if(tab[mid] < e){
            debut = mid +1;
        }else{
            fin = mid -1;
        }
    }
    return -1; 
}




int main()
{

    int tab[] = {1, 2, 11, 20, 22, 25, 30, 45, 40};
    int tabNotSort[] = {13, 14, 6, 8, 2, 1, 45, 56};
    //insertElementInTab(tabNotSort, 5, 4);
    //printabl(tab, 9);
    trieParInsertion(tabNotSort,8);
    printabl(tabNotSort, 8);
    printf("%d\n", dicho(tabNotSort, 8, 8));


}