// Correction Exercice 5 – Suite de Muller-Kahane

#include <stdio.h>
#include <math.h>

#define N 30

// Formule récursive
void suite_muller_classique() {
    double u[N];
    u[0] = 11.0 / 2.0;
    u[1] = 61.0 / 11.0;

    for (int n = 1; n < N - 1; n++) {
        u[n + 1] = (111.0 - (1130.0 / u[n]) + (3000.0 / (u[n] * u[n - 1])));
    }

    printf("Suite de Muller (récursive) :\n");
    for (int i = 0; i < N; i++) {
        printf("u[%d] = %.15f\n", i, u[i]);
    }
    printf("\nLimite apparente = %.15f\n", u[N - 1]);
}

// Formule fermée : un = (5^(n+1) + 6^(n+1)) / (5^n + 6^n)
double suite_muller_fermee(int n) {
    return (pow(5, n + 1) + pow(6, n + 1)) / (pow(5, n) + pow(6, n));
}

void suite_muller_theorique() {
    printf("Suite de Muller (formule fermée) :\n");
    for (int i = 0; i < N; i++) {
        printf("u[%d] = %.15f\n", i, suite_muller_fermee(i));
    }
    printf("\nLimite théorique = %.15f\n", suite_muller_fermee(N - 1));
}

int main() {
    printf("--- Exercice 5 : Suite de Muller-Kahane ---\n\n");

    suite_muller_classique();
    printf("\n---------------------------------------------\n\n");
    suite_muller_theorique();

    return 0;
}

/*
Observations :
- En récursif, la suite diverge à cause des erreurs d’arrondi et effets de cancellation.
- En formule fermée, les valeurs sont stables et convergent vers 6.
- La précision influence fortement le résultat. Une version MPFR permet de confirmer la limite.
*/
