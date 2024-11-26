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
 
struct noeud *supprime_noeud(struct noeud *r, struct noeud *supp) {
    struct noeud *pere = NULL;

    if (r == NULL || supp == NULL) {
        return 0;                             // si c'est vide ( null ) on stop 
    }

    if (r->fg->val == supp->val || r->fd->val == supp->val) {
        pere = r;                            // on stock le parent dans la variable pere
    } else {
        supprime_noeud(r->fg, supp);
        supprime_noeud(r->fd, supp);
    }
    return pere;
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
    // ppgp(r);
    printf("%d ", parent->val);
}