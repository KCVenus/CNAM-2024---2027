#include <stdio.h>
#include <stdlib.h>

void Matrice(int *a, int *b, int *c, int taille)
{
    int i, j, k;

    for (i = 0; i < taille; i++)
    {
        for (j = 0; j < taille; j++)
        {
            c[i*taille+j] = 0; //On initialise à 0
            for (k = 0; k < taille; k++)
            {                
                // multiplie ici : produit de C(i;j) = A(i;j)*B(i;j);
                c[i*taille+j] += a[i*taille+k] * b[k*taille+j];
            }
        }
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

int main()
{
    int matA[4] = {1, 2, 3, 4};
    int matB[4] = {1, 0, 0, 1};
    int matC[4] = {0};  // Initialiser la matrice résultat 
    int taille = 2;

    printf("Matrice A:\n");
    AfficheMatrice(matA, taille);

    printf("\nMatrice B:\n");
    AfficheMatrice(matB, taille);

    Matrice(matA, matB, matC, taille);

    printf("\nMultiplication (Matrice C):\n");
    AfficheMatrice(matC, taille);

}
