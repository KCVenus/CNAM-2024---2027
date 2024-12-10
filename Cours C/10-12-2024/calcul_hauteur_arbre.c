#include <stdio.h>
#include <stdlib.h>

struct noeud {
    int val, hauteur, difference;
    struct noeud *fg, *fd, *parent;
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

int hauteur(struct noeud *arbre){
    
    if (arbre == NULL) return 0;

    int hauteur_gauche = hauteur(arbre->fg), hauteur_droite = hauteur(arbre->fd);
    return (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite) +1;
} 

int diff_hauteur(struct noeud *arbre){
    if (arbre == NULL ) return 0;
    return hauteur(arbre->fg) - hauteur(arbre->fd);


}


void ppgp(struct noeud *r) {
    if (r != NULL) {
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}


struct noeud * rotation_droite(struct noeud *arbre){


} 

struct noeud * rotation_gauche(struct noeud *arbre){


}







int main() {
    struct noeud *r = NULL;
    int a ;

    r = ajout(r, 33);
    r = ajout(r, 17);
    r = ajout(r, 9);
    r = ajout(r, 4);
    r = ajout(r, 20);
    ppgp(r);
    printf("\n");
    printf("profondeur ");
    a = hauteur(r);
    printf("%d\n", a);

    printf("diff profondeur");
    a = diff_hauteur(r);
    printf("%d\n", a);

}





