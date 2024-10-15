#include <stdio.h>
#include <stdlib.h>

void fusion(int *tab, int d, int m, int f) {
    int *tmp = (int *)malloc((f - d + 1) * sizeof(int));
    int i = d, j = m + 1, k = 0;

    while (i <= m && j <= f) {
        if (tab[i] <= tab[j]) {
            tmp[k++] = tab[i++];
        } else {
            tmp[k++] = tab[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = tab[i++];
    }
    while (j <= f) {
        tmp[k++] = tab[j++];
    }

    for (i = d, k = 0; i <= f; i++, k++) {
        tab[i] = tmp[k];
    }

    free(tmp);
}

void TriFusion(int* tab, int debut, int fin){
    if(debut < fin){
        int milieu = (debut + fin) / 2;
        TriFusion(tab, debut, milieu);
        TriFusion(tab, milieu + 1, fin);
        fusion(tab, debut, milieu, fin);
    }
}

void AfficherTab(int* tab, int taille){
    printf("[%d",tab[0]);
    for(int i = 1; i<taille; i++){
        printf(",%d",tab[i]);
    }
    printf("]\n");
}

int main(){
    int tableau[] = {1,36,9,17,16,50,2,85,13,63,42,100};
    TriFusion(tableau, 0, 11);
    AfficherTab(tableau, 12);
    return 0;
}
