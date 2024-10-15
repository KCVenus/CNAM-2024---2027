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


int tritab(int *tab, int taille)
{
    int i, j, min, tmp;
    for (i = 0; i < taille; i++)
    {

        min = i;

        for (j = i + 1; j < taille; j++)
        {
            if (tab[j] < tab[min])
            {
                min = j;
            }
        }
        tmp = tab[min];
        tab[min] = tab[i];
        tab[i] = tmp;
    }
}

void tri_ligne(int *tab, int n, int m)
{

    for (int i = 0; i < m; i++)
    {
        tritab(tab + i * n, n);
    }
}

void Echanger2Lignes(int *tab, int n, int m, int ligne1, int ligne2)
{

    int tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = tab[ligne1 * n + i];
        tab[ligne1 * n + i] = tab[ligne2 * n + i];
        tab[ligne2 * n + i] = tmp;
    }
}

void AfficheMatrice(int *tab, int taille)
{
    int i, j;
    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille; j++)
        {
            printf("%d ", tab[i * taille + j]);
        }
        printf("\n"); // Ajouter une nouvelle ligne après chaque ligne de la matrice, car c'est des tableaux a 1 dimension
    }
}

void transpose(int *tab, int n)
{

    int tmp;
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {

            tmp = tab[i * n + j];
            tab[i * n + j] = tab[j * n + i];
            tab[j * n + i] = tmp;
        }
    }
}
int trival(int *tab, int v, int taille) {
    int i = 0, j = taille - 1, tmp;
   
    while(i < j)
    {
        if(tab[i] >= v) {
            tmp = tab[j];
            tab[j] = tab[i];
            tab[i] = tmp;
            j--;
        }else{
            i++;
        }
    }
    if(tab[i] >=v){
        return i;
    }
    return i+1;
}

void tri3types(int *tab, int taille) {
    int pos1 = 0;             
    int pos2 = 0;             
    int pos3 = taille - 1;    
    int temp;

    while (pos2 <= pos3) {
        if (tab[pos2] == 1) {
            
            temp = tab[pos1];
            tab[pos1] = tab[pos2];
            tab[pos2] = temp;
            pos1++;
            pos2++;  
        } else if (tab[pos2] == 2) {  
            pos2++;
        } else if (tab[pos2] == 3) {  
            temp = tab[pos2];
            tab[pos2] = tab[pos3];
            tab[pos3] = temp;
            pos3--; 
        }
    }
}

    // exactement la meme chose qu'au dessus sauf qu'on va utiliser que 2 valeurs 

void tri3Valeurs( int *tab, int taille){

    int pos1 = 0;
    int pos2 = taille -1;
    int i = 0;
    int tmp;


    while ( i != pos2){

        if (tab[i] == 1) {
            tmp = tab[pos1];
            tab[pos1] = tab[i];
            tab[i] = tmp;
            pos1++;
        }
        if (tab[i] == 3){
            tmp = tab[pos2];
            tab[pos2] = tab[i];
            tab[i] = tmp;
            pos2--;
        }else{
            i++;
        }    
    }
}




int main()
{

    int tab[] = {5, 1, 5, 7, 9, 4, 4, 8, 2, 4, 6, 2, 4, 7, 5, 2};
    int tab3[] = {3, 1, 2, 1, 2, 1, 3, 2, 1, 2};
    // AfficheMatrice(tab,4);
    printf("\n");
    // tri_ligne(tab, 4, 4);
    // tritab(tab,16);
    // Echanger2Lignes(tab, 4,4, 1, 3);
    // AfficheMatrice(tab, 4);
    //printf("\n");
    //transpose(tab, 4);
    //AfficheMatrice(tab, 4);
    printabl(tab3,10);
    tri3types(tab3,10);
    printf("\n");
    printabl(tab3,10);
    tri3Valeurs(tab3, 10);
    printabl(tab3,10);


    //printabl(tab,16);
    // trival(tab, 3, 16);
    //printabl(tab,16);
    //printf("\n%d", trival(tab, 3,16));


}