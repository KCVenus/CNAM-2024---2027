#include <stdio.h>
#include <stdlib.h>


int tritab(int *tab, int taille){
    int i, j, min, tmp;
    for (i=0; i<taille; i++){

        min = i;
    
            for(j=i+1; j<taille; j++){
                if(tab[j]<tab[min]){
                    min = j;
                }
            }
        tmp = tab[min];
        tab[min]=tab[i];
        tab[i] = tmp;
    }
}


void tri_ligne(int *tab, int n, int m){

    for(int i=0 ; i< m ; i++){
            tritab(tab+i*n, n);
    }
}

void Echanger2Lignes(int *tab, int n, int m, int ligne1, int ligne2){
    
    int tmp;
    for(int i =0; i < n; i++){
        tmp = tab[ligne1*n+i];
        tab[ligne1*n +i] = tab[ligne2 * n +i];
        tab[ligne2*n +i] = tmp;
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
        printf("\n");  // Ajouter une nouvelle ligne après chaque ligne de la matrice, car c'est des tableaux a 1 dimension
    }
}


void transpose(int *tab, int n){

    int tmp;
    for(int i = 1; i < n ; i++){

        for(int j = 0; j < i ; j++){

            tmp = tab[i*n+j];
            tab[i*n+j] = tab[j*n+i];
            tab[j*n+i] = tmp;

        }
    }

}

void main (){

    int tab[] = {5, 1, 5, 7, 9, 4 , 4,8 , 3, 4, 6,2,4,7,5,2};
    //AfficheMatrice(tab,4);
    printf("\n");
    //tri_ligne(tab, 4, 4);
    //tritab(tab,16);
    //Echanger2Lignes(tab, 4,4, 1, 3);
    AfficheMatrice(tab, 4);
    printf("\n");
    transpose(tab, 4);
    AfficheMatrice(tab, 4);

}