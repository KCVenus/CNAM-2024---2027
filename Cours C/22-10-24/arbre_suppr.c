#include <stdio.h>
#include <stdlib.h>

struct noeud
{
    int val;
    struct noeud *parent, *fg, *fd;
};

void ajoutePetit(struct noeud *arbre, struct noeud *noeud)  
{
    if (noeud->val < arbre->val) 
    { 
        if (arbre->fg == NULL) 
        {
            arbre->fg = noeud;
            noeud->parent = arbre;
        }
        else
        {
            ajoutePetit(arbre->fg, noeud);  
        }
    }
    else  
    {
        if (arbre->fd == NULL)  
        {
            arbre->fd = noeud;
            noeud->parent = arbre;
        }
        else
        {
            ajoutePetit(arbre->fd, noeud);  
            
    }
}
}



struct noeud* supprimer_noeud_arbre(struct noeud *racine, struct noeud *supprime) {
    struct noeud *noeudtemp;

    if (racine == NULL || supprime == NULL) {
        return racine;
    }

    if (racine == supprime) {
        if (racine->fd) {  
            noeudtemp = racine->fd;
            noeudtemp->fg = racine->fg;
            if (racine->fg) racine->fg->parent = noeudtemp;
            noeudtemp->parent = NULL;
            free(racine);
            return noeudtemp;
        } else if (racine->fg) {  
            noeudtemp = racine->fg;
            noeudtemp->parent = NULL;
            free(racine);
            return noeudtemp;
        } else {
            free(racine);
            return NULL;
        }
    }

    return racine;
}
