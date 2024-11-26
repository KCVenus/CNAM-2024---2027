#include <stdio.h>
#include <stdlib.h>

struct noeud{
    int val;
    struct noeud *fg, *fd;
};

struct noeud *ajout(struct noeud *r, int e){

    struct noeud *ptr;
    ptr = (struct noeud *)malloc(sizeof(struct noeud));
    ptr->fg = NULL;
    ptr->fd = NULL;
    ptr->val = e;
    if(r != NULL){
        if(r->val <=e){
            if(r->fd == NULL){
                r->fd = ptr;
                return r;
            }
            return ajoute( r->fd ,val);
        }
    }

}