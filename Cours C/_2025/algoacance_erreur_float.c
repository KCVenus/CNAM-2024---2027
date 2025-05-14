// Correction Exercice 4 – Erreurs absolue et relative entre deux flottants consécutifs

#include <stdio.h>
#include <math.h>
#include <float.h>

// Calcule l’epsilon-machine pour float : 2^(-23)
float epsilon_machine() {
    return powf(2.0f, -23);
}

// Calcule ulp(x) pour float
float ulp(float x) {
    float next = nextafterf(x, INFINITY);
    return next - x;
}

// Exprime deux flottants consécutifs et calcule erreurs
void erreur_entre_flottants(float x) {
    float next = nextafterf(x, INFINITY);
    float abserr = fabsf(next - x);
    float relerr = abserr / fabsf(x);

    printf("x           = %.10f\n", x);
    printf("next(x)     = %.10f\n", next);
    printf("abserr      = %.10e\n", abserr);
    printf("relerr      = %.10e\n", relerr);
    printf("ulp(x)      = %.10e\n", ulp(x));
    printf("ε-machine   = %.10e\n", epsilon_machine());
    printf("borne théorique relerr < ε : %s\n",
           (relerr < epsilon_machine()) ? "✅ ok" : "❌ faux");
}

int main() {
    printf("--- Exercice 4 : Erreurs entre deux flottants ---\n\n");

    // Cas classique : deux flottants consécutifs ayant même exposant
    float x = 1.0f;
    erreur_entre_flottants(x);

    printf("\nCas plus grand : x = 2048.0f\n");
    erreur_entre_flottants(2048.0f);

    printf("\nCas très petit : x = 1e-38\n");
    erreur_entre_flottants(1e-38f);

    return 0;
}

/*
Conclusion :
------------
- Deux flottants consécutifs ont un écart égal à ulp(x) = 2^(-23) * 2^e
- L’erreur absolue = ulp(x), l’erreur relative = ulp(x) / |x| = ε
- La borne relative est donc toujours ε-machine ≈ 1.1921e-07 en simple précision (float)
*/
