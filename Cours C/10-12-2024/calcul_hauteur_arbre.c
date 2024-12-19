#include <stdio.h>
#include <stdlib.h>
#include "fonctions/noeud.h"
#include "fonctions/affichage.h"


int calhauteur(struct noeud *arbre){
    
    if (arbre == NULL) return 0;

    int hauteur_gauche = hauteur(arbre->fg), hauteur_droite = hauteur(arbre->fd);
    return (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite) +1;
} 

int diff_hauteur(struct noeud *arbre){
    if (arbre == NULL ) return 0;
    return hauteur(arbre->fg) - hauteur(arbre->fd);


}


struct noeud *ajout(struct noeud *r, int e) {
    struct noeud *ptr;
    if (r != NULL) {
        if (r->val <= e) {
            if (r->fd == NULL) {
                ptr = (struct noeud *)malloc(sizeof(struct noeud));
                ptr->fg = NULL;
                ptr->fd = NULL;
                ptr->val = e;
                r->fd = ptr;
                return r;
            }
            r->fd = ajout(r->fd, e);
            return r;
        } else {
            if (r->fg == NULL) {
                ptr = (struct noeud *)malloc(sizeof(struct noeud));
                ptr->fg = NULL;
                ptr->fd = NULL;
                ptr->val = e;
                r->fg = ptr;
                return r;
            }
            r->fg = ajout(r->fg, e);
            return r;
        }
    } else {
        ptr = (struct noeud *)malloc(sizeof(struct noeud));
        ptr->fg = NULL;
        ptr->fd = NULL;
        ptr->val = e;
        return ptr;
    }
}

struct noeud *ajout_actualise(struct noeud *r, int e)
{
    if (r == NULL)
    {
        struct noeud *ptr = (struct noeud *)malloc(sizeof(struct noeud));
        ptr->fg = NULL;
        ptr->fd = NULL;
        ptr->p = NULL;
        ptr->val = e;
        ptr->hauteur = 1;
        ptr->difference = 0;
        return ptr;
    }
    if (e < r->val)
    {
        r->fg = ajout_actualise(r->fg, e);
        r->fg->p = r;
    }
    else if (e >= r->val)
    {
        r->fd = ajout_actualise(r->fd, e);
        r->fd->p = r;
    }
    else
    {
        return r;
    }
    r->hauteur = 1 + (calhauteur(r->fg) > calhauteur(r->fd) ? calhauteur(r->fg) : calhauteur(r->fd));
    r->difference = diff_hauteur(r);
    return r;
}




void ppgp(struct noeud *r) {
    if (r != NULL) {
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}



struct noeud *rotation_gauche(struct noeud *r) {
    struct noeud *L = r->fg; 
    if (L == NULL) {
        return r; 

    r->fg = L->fd;
    if (L->fd != NULL) {
        L->fd->p = r; 
    }

    L->p = r->p;
    if (r->p != NULL) {
        if (r->p->fg == r) {
            r->p->fg = L;
        } else {
            r->p->fd = L;
        }
    }

    L->fd = r;
    r->p = L;

    return L;
}
}




struct noeud *rotation_droite(struct noeud *r) {
    struct noeud *L = r->fg; 

    if (L == NULL) {
        return r;
    }
    r->fg = L->fd;
    if (L->fd != NULL) {
        L->fd->p = r; 
    }
    L->p = r->p;
    if (r->p != NULL) {
        if (r->p->fg == r) {
            r->p->fg = L;
        } else {
            r->p->fd = L;
        }
    }
    L->fd = r;
    r->p = L;
    return L;
}



struct noeud* equilibrage(){
    
}

struct noeud *rotation_droite_gauche(struct noeud *r) {
    if (r == NULL || r->fd == NULL) {
        return r; 
    }
    r->fd = rotation_droite(r->fd);
    return rotation_gauche(r);
}

struct noeud *rotation_gauche_droite(struct noeud *r) {
    if (r == NULL || r->fg == NULL) {
        return r; 
    }
    r->fg = rotation_gauche(r->fg);
    return rotation_droite(r);
}



int main() {
    struct noeud *r = NULL , *rotat = NULL;
    int a ;

    r = ajout_actualise(r, 33);
    r = ajout_actualise(r, 17);
    r = ajout_actualise(r, 9);
    r = ajout_actualise(r, 4);
    r = ajout_actualise(r, 20);
    ppgp(r);
    printf("\n");
    printf("profondeur ");
    a = hauteur(r);
    printf("%d\n", a);

    printf("diff profondeur");
    a = diff_hauteur(r);
    printf("%d\n", a);

    afficherArbre(r);
    rotat = rotation_droit(r);
    afficherArbre(rotat);

}





