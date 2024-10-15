#include <stdio.h>
#include <stdlib.h>



int maxi(int *tab, int taille)
{

    if (taille == 1)
    {
        return tab[0];
    }
    else
    {
        int maximum = maxi(tab, taille - 1);

        if (tab[taille - 1] > maximum)
        {
            return tab[taille - 1];
        }
        else
        {
            return maximum;
        }
    }
}


int main(){
    int tab[] = {5, 1, 5, 7, 9, 4, 4, 8, 2, 4, 6, 2, 4, 7, 5, 2};
    printf("\n%d", maxi(tab,16));
}