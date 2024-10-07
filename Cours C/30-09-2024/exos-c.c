#include <stdio.h>
#include <stdlib.h>

int plutpetit() {
    int tableau[] = {5, 2, 8, 1, 9};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int plus_petit = tableau[0];

    for (int i = 1; i < taille; i++) {
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }

    printf("Le plus petit nombre est : %d\n", plus_petit);
    return 0;
}

void printabl(int tab[],int taille){

    for(int i =0; i<taille; i++){
        printf("%d;", tab[i]);
    }
    printf("\n");
}

// fonction pour trier un tableau de n elements
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
    printabl(tab,7);
}

// faire un tableau qui trie qu'entre 2 indinces données

int triTabeEntre2valeurs(int *tab, int taille, int d, int f){
    int i, j, min, tmp;
    for (i=d; i<=f; i++){

        min = i;
    
            for(j=i+1; j<f; j++){
                if(tab[j]<tab[min]){
                    min = j;
                }
            }
        tmp = tab[min];
        tab[min]=tab[i];
        tab[i] = tmp;
    }
    printabl(tab,7);
}


// diviser un tableau en 2 pour le trier dans un nouveau tableau apres


void fusion(int *tab, int taille, int n) {
    int *tmp = (int *)malloc(taille * sizeof(int));
    int i = 0, j = n + 1, k = 0;

    while (i <= n && j < taille) {
        if (i <= n && (j >= taille || tab[i] < tab[j])) {
            tmp[k++] = tab[i++];
        } else {
            tmp[k++] = tab[j++];
        }
    }
    while (i <= n) {
        tmp[k++] = tab[i++];
    }
    while (j < taille) {
        tmp[k++] = tab[j++];
    }
    for (i = 0; i < taille; i++) {
        tab[i] = tmp[i];
    }

    free(tmp);
    printabl(tab, taille);
}


// on va trier un tableau en mettant les chiffres impaire a droite et les impaires a gauche

int triPairImpair(int *tab,int taille)
{
    int i = 0, j = taille - 1, tmp;
   
    while(i != j)
    {
        if(tab[i]%2 != 0) {
            tmp = tab[j];
            tab[j] = tab[i];
            tab[i] = tmp;
            j--;
        }else{
            i++;
        }
    }
    printabl(tab, taille);
}




int main(){
    //plutpetit();
    int tab[] = {-31, 4, 3, 8, 6, 2, 1};
    //tritab(tab,7);
    //triTabeEntre2valeurs(tab, 7, 2, 6);
    //fusion(tab, 7, 4);
    // triFusion(tab,7,4);
    //printf("\n%d;", tab[2]);
    int m;
    m = triPairImpair(tab, 7);

}