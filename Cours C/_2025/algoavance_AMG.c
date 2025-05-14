// Correction Exercice 3 – Algorithme de Malcolm-Gentleman

#include <stdio.h>
#include <float.h>
#include <math.h>

void algorithme_malcolm_float() {
    float A = 1.0f;
    float B = 1.0f;

    while (((A + 1.0f) - A) - 1.0f == 0.0f) {
        A = 2.0f * A;
    }

    while (((A + B) - A) - B != 0.0f) {
        B = B + 1.0f;
    }

    printf("[FLOAT] Valeur finale de A = %.0f\n", A);
    printf("[FLOAT] Valeur finale de B = %.0f\n", B);
}

void algorithme_malcolm_double() {
    double A = 1.0;
    double B = 1.0;

    while (((A + 1.0) - A) - 1.0 == 0.0) {
        A = 2.0 * A;
    }

    while (((A + B) - A) - B != 0.0) {
        B = B + 1.0;
    }

    printf("[DOUBLE] Valeur finale de A = %.0f\n", A);
    printf("[DOUBLE] Valeur finale de B = %.0f\n", B);
}

int main() {
    printf("--- Algorithme de Malcolm-Gentleman ---\n");
    algorithme_malcolm_float();
    algorithme_malcolm_double();
    return 0;
}

