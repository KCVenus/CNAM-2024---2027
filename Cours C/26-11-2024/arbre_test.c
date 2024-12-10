#include <stdio.h>
#include <stdlib.h>

struct noeud {
    int val;
    struct noeud *fg, *fd;
};

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

void ppgp(struct noeud *r) {
    if (r != NULL) {
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}

struct noeud *supprime_noeud(struct noeud *r, struct noeud *supp) {
    if (r == NULL || supp == NULL) {
        return r; 
    }
    if (supp->val < r->val) {
        r->fg = supprime_noeud(r->fg, supp);
    } else if (supp->val > r->val) {
        r->fd = supprime_noeud(r->fd, supp);
    } else {
        if (r->fg == NULL && r->fd == NULL) {       // Cas 1  le noeud est une feuille
            free(r);
            return NULL;
        } else if (r->fg == NULL) {                  // Cas 2 le noeud a 1 fils droit
            struct noeud *temp = r->fd;
            free(r);
            return temp;
        } else if (r->fd == NULL) {                  // Cas 2  le noeud a 1 fils gauche
            struct noeud *temp = r->fg;
            free(r);
            return temp;
        } else {                                      // Cas 3 le noeud a 2 enfants
            struct noeud *successeur = r->fd;
            while (successeur->fg != NULL) {
                successeur = successeur->fg;            // Trouver le plus petit noeud du sous-arbre droit
            }
            r->val = successeur->val; 
            r->fd = supprime_noeud(r->fd, successeur);  // on zigouille le + petit
        }
    }
    return r;
}

struct noeud *recherche_neoud(struct noeud *r, int val) {
    if (r == NULL || r->val == val) {
        return r;
    }
    if (val < r->val) {
        return recherche_neoud(r->fg, val);
    }
    return recherche_neoud(r->fd, val);
}

int main() {
    struct noeud *r = NULL;

    r = ajout(r, 33);
    r = ajout(r, 17);
    r = ajout(r, 9);
    r = ajout(r, 4);
    r = ajout(r, 20);

    printf("Arbre de depart: ");
    ppgp(r);
    printf("\n");

    struct noeud *a_supp = recherche_neoud(r, 33);
    r = supprime_noeud(r, a_supp);

    printf("Arbre après  supp :");
    ppgp(r);
    printf("\n");

}