#include <stdio.h>
#include <stdlib.h>

struct noeud{
    int val;
    struct noeud *fg, *fd;
};

struct noeud *ajout(struct noeud *r, int e){

    struct noeud *ptr;
    if(r != NULL){
        if(r->val <=e){
            if(r->fd == NULL){
                ptr = (struct noeud *)malloc(sizeof(struct noeud));
                ptr->fg = NULL;
                ptr->fd = NULL;
                ptr->val = e;
                r->fd = ptr;
                return r;
            }
            r->fd =  ajout( r->fd , e);
            return r;
        } 
        else
        { 
            if(r->fg == NULL){
                    ptr = (struct noeud *)malloc(sizeof(struct noeud));
                    ptr->fg = NULL;
                    ptr->fd = NULL;
                    ptr->val = e;
                    r->fg = ptr;
                return r;
            }
            r->fg =  ajout( r->fg , e);
            return r;
        }
    } 
    else { 
        ptr = (struct noeud *)malloc(sizeof(struct noeud));
        ptr->fg = NULL;
        ptr->fd = NULL;
        ptr->val = e;
        return ptr;
    }

}

void ppgp(struct noeud *r){
    if ( r != NULL){ 
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}
 
struct noeud *supprime_noeud(struct noeud *r, int val) {
    if (r == NULL) {
        return NULL;
    }
    if (val < r->val) {
        r->fg = supprime_noeud(r->fg, val);
    } else if (val > r->val) {
        r->fd = supprime_noeud(r->fd, val);
    } else {
        if (r->fg == NULL && r->fd == NULL) {
            free(r);
            return NULL;
        } else if (r->fg == NULL) {
            struct noeud *temp = r->fd;
            free(r);
            return temp;
        } else if (r->fd == NULL) {
            struct noeud *temp = r->fg;
            free(r);
            return temp;
        } else {
            struct noeud *successeur = r->fd;
            while (successeur->fg != NULL) {
                successeur = successeur->fg;
            }
            r->val = successeur->val;
            r->fd = supprime_noeud(r->fd, successeur->val);
        }
    }
    return r;
}

int main(){

    struct noeud *r = NULL;
    struct noeud *e;
    struct noeud *parent = NULL;
    e->val = 4;

    r = ajout(r , 33);
    r = ajout(r , 17);
    r = ajout(r , 9);
    r = ajout(r , 4);
    r = ajout(r , 20);
    parent = supprime_noeud(r, e);
    printf("%d ", parent->val);
}
int main() {
    struct noeud *r = NULL;

    // Création de l'arbre
    r = ajout(r, 33);
    r = ajout(r, 17);
    r = ajout(r, 9);
    r = ajout(r, 4);
    r = ajout(r, 20);

    printf("Arbre avant suppression : ");
    afficher_inordre(r);
    printf("\n");

    // Suppression d'un nœud
    r = supprime_noeud(r, 17);

    printf("Arbre après suppression : ");
    afficher_inordre(r);
    printf("\n");