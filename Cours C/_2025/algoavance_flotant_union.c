// Correction Exercice 2 – Représentation flottante avec union en C

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define S_INT 32
#define F_BIAS 127
#define S_MANTISSA 23

union nf {
    int i;
    float f;
};

// 1. Vérification de l'exemple donné
void verif_exemple() {
    union nf x;
    int n = 0x3f800000;
    x.i = n;
    printf("Exemple : x.i = 0x%x, x.f = %f\n", x.i, x.f); // Doit afficher : x.f = 1.0
}

// 2. Extraction du signe, de l'exposant et de la mantisse
int affsem(unsigned int *s, unsigned int *e, unsigned int *m, unsigned int n) {
    *s = (n >> 31) & 0x1;
    *e = (n >> S_MANTISSA) & 0xFF;
    *m = n & ((1 << S_MANTISSA) - 1);
    return 0;
}

// 3. Conversion manuelle d’un entier vers un float (IEEE754)
union nf fromIntToFloat(int n) {
    union nf infl;
    unsigned int s, e, m;
    unsigned int absn = (n < 0) ? -n : n;
    s = (n < 0);

    int position = 31;
    while (position > 0 && ((absn >> position) & 1) == 0)
        position--;

    e = position + F_BIAS;

    if (position > 23) {
        m = (absn >> (position - 23)) & ((1 << 23) - 1);
    } else {
        m = (absn << (23 - position)) & ((1 << 23) - 1);
    }

    infl.i = (s << 31) | (e << 23) | m;
    return infl;
}

// 4. Addition manuelle (normalisée uniquement, version simplifiée)
float add_float(float a, float b) {
    union nf ua, ub, res;
    ua.f = a;
    ub.f = b;

    unsigned sa, ea, ma;
    unsigned sb, eb, mb;

    affsem(&sa, &ea, &ma, ua.i);
    affsem(&sb, &eb, &mb, ub.i);
 
    ma |= (1 << 23);
    mb |= (1 << 23);

    if (ea > eb) {
        mb >>= (ea - eb);
        eb = ea;
    } else {
        ma >>= (eb - ea);
        ea = eb;
    }

    unsigned mr;
    if (sa == sb)
        mr = ma + mb;
    else
        mr = (ma > mb) ? (ma - mb) : (mb - ma);

    unsigned sr = (ma > mb) ? sa : sb;

    int shift = 0;
    while ((mr & (1 << 24)) == 0 && mr != 0) {
        mr <<= 1;
        shift++;
    }

    mr >>= 1;
    shift--;

    unsigned er = ea - shift;
    unsigned mantissa = (mr >> 1) & ((1 << 23) - 1);

    res.i = (sr << 31) | (er << 23) | mantissa;
    return res.f;
}

// 5. Multiplication manuelle (version simplifiée, normalisée)
float mul_float(float a, float b) {
    union nf ua, ub, res;
    ua.f = a;
    ub.f = b;

    unsigned sa, ea, ma;
    unsigned sb, eb, mb;

    affsem(&sa, &ea, &ma, ua.i);
    affsem(&sb, &eb, &mb, ub.i);

    ma |= (1 << 23);
    mb |= (1 << 23);

    uint64_t prod = (uint64_t)ma * (uint64_t)mb;
    prod >>= 23;

    unsigned sr = sa ^ sb;
    unsigned er = ea + eb - F_BIAS;
    unsigned mr = prod & ((1 << 23) - 1);

    res.i = (sr << 31) | (er << 23) | mr;
    return res.f;
}

int main() {
    verif_exemple();

    union nf f = fromIntToFloat(5);
    printf("5 converti = %f\n", f.f);

    float res_add = add_float(1.0f, 2.0f);
    printf("1.0 + 2.0 = %f\n", res_add);

    float res_mul = mul_float(1.5f, 2.0f);
    printf("1.5 * 2.0 = %f\n", res_mul);

    return 0;
}
