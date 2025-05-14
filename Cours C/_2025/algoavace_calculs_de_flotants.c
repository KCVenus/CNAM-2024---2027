#include <stdio.h>

#define S_INT 32
#define F_BIAS 127
#define S_MANTISSA 23

union nf {
    int i;
    float f;
};

int affsem(unsigned int *s, unsigned int *e, unsigned int *m, unsigned int n)
{
    *s = n & 0x80000000; // bit de signe 31 
    *e = (n >> 23) & 0xFF; // bits de exposant 30 à 23
    *m = n & 0x7FFFFF;  // bits de mentisse 22 à 0

    return 0;
}

void swap(int *a, int *b){
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

union nf add(union nf a, union nf b){
    union nf c; //c = a+b
    int as, ae, am, bs, be, bm, cs, ce, cm;

    affsem(&as, &ae, &am, a.i);
    affsem(&bs, &be, &bm, b.i);

    if(ae < be || ae == be && am < bm)
    {
        swap(&as, &bs);
        swap(&ae, &be);
        swap(&am, &bm);
    }
    cs = as;
    ce = ae;

    //ajouter le bit implicite
    am |= 1<<23;
    bm |= 1<<23;

    //shift mantisse de b
    bm >>=ae - be;
    
    //ajouter les mantisses
    cm = am + bm;

    if((cm>>23) > 1)
    {
        ++ce;
        cm>>=1;
    }

    //tout rassembler
    c.i = (cs <<31) + (ce<<23) + (cm-(1<<23)); //retirer le bit implicite

    return c;
}

int main(){
    union nf x;
    int n = 0x3f8000F0;
    x.i = n;
    //printf("x.i=0x%x, x.f=%f\n", x.i, x.f);

    unsigned int s, e, m;

    affsem(&s, &e, &m, n);
    printf("Signe: %u, Exposant: %u, Mantisse: 0x%x\n", s, e, m);
        
    return 0;
}