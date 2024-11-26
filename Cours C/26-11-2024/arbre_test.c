#include <stdio.h>
#include <stdlib.h>

struct noeud {
    int val;
    struct noeud *fg, *fd;
};

// Fonction pour ajouter un élément dans l'arbre binaire (ton implémentation existante)
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

// Fonction pour afficher l'arbre en pré-ordre
void ppgp(struct noeud *r) {
    if (r != NULL) {
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}

// Fonction pour supprimer un nœud directement
struct noeud *supprime_noeud(struct noeud *r, struct noeud *supp) {
    if (r == NULL || supp == NULL) {
        return r; // Rien à faire si l'arbre est vide ou le nœud à supprimer est NULL
    }

    if (supp->val < r->val) {
        // Le nœud à supprimer est dans le sous-arbre gauche
        r->fg = supprime_noeud(r->fg, supp);
    } else if (supp->val > r->val) {
        // Le nœud à supprimer est dans le sous-arbre droit
        r->fd = supprime_noeud(r->fd, supp);
    } else {
        // Le nœud à supprimer est trouvé
        if (r->fg == NULL && r->fd == NULL) {
            // Cas 1 : le nœud est une feuille
            free(r);
            return NULL;
        } else if (r->fg == NULL) {
            // Cas 2 : le nœud n'a qu'un fils droit
            struct noeud *temp = r->fd;
            free(r);
            return temp;
        } else if (r->fd == NULL) {
            // Cas 2 : le nœud n'a qu'un fils gauche
            struct noeud *temp = r->fg;
            free(r);
            return temp;
        } else {
            // Cas 3 : le nœud a deux enfants
            struct noeud *successeur = r->fd;
            while (successeur->fg != NULL) {
                successeur = successeur->fg; // Trouver le plus petit nœud du sous-arbre droit
            }
            r->val = successeur->val; // Remplacer la valeur du nœud à supprimer
            r->fd = supprime_noeud(r->fd, successeur); // Supprimer le successeur
        }
    }
    return r;
}

// Fonction pour rechercher un nœud dans l'arbre
struct noeud *rechercher(struct noeud *r, int val) {
    if (r == NULL || r->val == val) {
        return r;
    }
    if (val < r->val) {
        return rechercher(r->fg, val);
    }
    return rechercher(r->fd, val);
}

int main() {
    struct noeud *r = NULL;

    // Création de l'arbre
    r = ajout(r, 33);
    r = ajout(r, 17);
    r = ajout(r, 9);
    r = ajout(r, 4);
    r = ajout(r, 20);

    printf("Arbre avant suppression (pré-ordre) : ");
    ppgp(r);
    printf("\n");

    // Recherche du nœud à supprimer
    struct noeud *a_supprimer = rechercher(r, 33);

    // Suppression du nœud
    r = supprime_noeud(r, a_supprimer);

    printf("Arbre après suppression (pré-ordre) : ");
    ppgp(r);
    printf("\n");

    return 0;
}