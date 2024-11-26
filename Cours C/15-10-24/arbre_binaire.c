#include <stdio.h>
#include <stdlib.h>

struct noeud
{
    int val;
    struct noeud *fg, *fd;
};

// parcours profondeur droite prefixe
void ppdpr(struct noeud * r){
    if (r != NULL){
        printf("%d", r->val);
        ppdpr(r->fd);
        ppdpr(r->fg);
    }

}

// parcours profondeur gauche prefixe
void ppgpr(struct noeud * r){
    if (r != NULL){
        printf("%d", r->val);
        ppgpr(r->fg);
        ppgpr(r->fd);
    }

}

// parcours profondeur gauche infixe
void ppgi(struct noeud * r){
    if (r != NULL){
        ppgi(r->fg);
        printf("%d", r->val);
        ppgi(r->fd);
    }
}

// parcours profondeur droite infixe
void ppdi(struct noeud * r){
    if (r != NULL){
        ppdi(r->fd);
        printf("%d", r->val);
        ppdi(r->fg);
    }
}


// parcours profondeur droite postfixe
void ppdps(struct noeud * r){
    if (r != NULL){
        ppdps(r->fd);
        ppdps(r->fg);
        printf("%d", r->val);

    }
}

// parcours profondeur gauche postfixe
void ppgps(struct noeud * r){
    if (r != NULL){
        ppgps(r->fg);
        ppgps(r->fd);
        printf("%d", r->val);

    }
}




void ajoutePetit(struct noeud *arbre, struct noeud *noeud)
{
    if (arbre->val > noeud->val)
    { 
        if (arbre->fg != NULL && arbre->fg->val > noeud->val)
        {
            ajoutePetit(arbre->fg, noeud);
        }
        else
        {
            arbre->fg = noeud;
        }
    }
    if (arbre->val < noeud->val)
    {
        if (arbre->fd != NULL && arbre->fd->val > noeud->val)
        {
            ajoutePetit(arbre->fd, noeud);
        }
        else
        {
            arbre->fd = noeud;
        }
    }
}

int main(){
    struct noeud *a, *b, *c, *d ,*noeud, *noeud2;
    a = (struct noeud *)malloc(sizeof(struct noeud));
    a->fg = NULL;
    a->fd = NULL;
    a->val = 17;

    b = (struct noeud *)malloc(sizeof(struct noeud));
    b->fg = a;
    b->val = 20;

    c = (struct noeud *)malloc(sizeof(struct noeud));
    c->fg = NULL;
    c->fd = NULL;
    c->val = 25;
    b->fd = c;

    noeud = (struct noeud *)malloc(sizeof(struct noeud));
    noeud->fg = NULL;
    noeud->fd = NULL;
    noeud->val = 13;

    noeud2 = (struct noeud *)malloc(sizeof(struct noeud));
    noeud2->fg = NULL;
    noeud2->fd = NULL;
    noeud2->val = 21;


    // printf("parcours profondeur gauche prefixe: ");
    // ppgpr(b);
    // printf("\n");

    // printf("parcours profondeur droite prefixe: ");
    // ppdpr(b);
    // printf("\n");

    // printf("parcours profondeur gauche infixe: ");
    // ppgi(b);
    // printf("\n");
    // printf("parcours profondeur droite infixe: ");
    // ppdi(b);
    // printf("\n");

    // printf("parcours profondeur gauche postfixe: ");
    // ppgps(b);
    // printf("\n");
    // printf("parcours profondeur droite postfixe: ");
    // ppdps(b);
    // printf("\n");

    ajoutePetit(b,noeud);
    ajoutePetit(b,noeud2);
    printf("parcours profondeur gauche infixe: ");
    ppgi(b);

}