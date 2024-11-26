#include <stdio.h>
#include <stdlib.h>



struct maillon
{
    struct noeud * n;
    struct maillon * suivant;
};

struct file{
    struct maillon * tete;
    struct maillon * queueu;
};

struct noeud
{
    int val;
    struct noeud *fg, *fd;
};


void enfile (struct file *f, struct noeud* noeud){

    struct maillon * ptr;
    ptr =(struct maillon *) malloc ( sizeof(struct maillon));

    if(f->queueu != NULL){
        f->queueu->suivant = ptr;
        f->queueu = ptr;
    }else{
        f->tete=ptr;
        f->queueu =ptr;
    }
    ptr->n = noeud;
    ptr->suivant = NULL;

}



struct noeud* defile(struct file * f){

    struct maillon *ptr;
    struct noeud *tmp;

    if(f->tete == f->queueu){
        tmp = f->tete->n;
        ptr = f->tete;
        free(ptr);
        f->tete = NULL;
        f->queueu = NULL;
        return tmp;
    }

    if(f->tete !=NULL){
        tmp = f->tete->n; // étape 1
        ptr = f->tete;      // étape 2 
        f->tete = ptr->suivant;     // étape 3 
        free(ptr);
        return tmp;
    }else{

        printf("la liste est vide aled oskour");
    }

}


void ajoutePetit(struct noeud *arbre, struct noeud *noeud)  
{
    if (noeud->val < arbre->val) 
    { 
        if (arbre->fg == NULL) 
        {
            arbre->fg = noeud;
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
        }
        else
        {
            ajoutePetit(arbre->fd, noeud);  
            
    }
}
}


void afficheListChaine(struct file *f)
{
    struct maillon *tmp = f->tete;
    while (tmp != NULL)
    {
        printf("%d; ", tmp->n->val);
        tmp = tmp->suivant;
    }
    printf("\n"); 
}

//parcours en largeur par la gauche d'un arbre binaire
void parcour_arbre_largeur(struct noeud *r, struct file *f)
{
    struct noeud * n;
    enfile(f, r);
    while(f->tete != NULL){
        n = defile(f);
        printf("%d; ", n->val);
        
        if(n->fg != NULL)
            enfile(f, n->fg);
        if(n->fd != NULL)
            enfile(f, n->fd);
    }
}


int main(){
    struct file *f =(struct file *) malloc ( sizeof(struct file));
    f->tete = NULL;
    f->queueu = NULL;

    struct noeud *a,*b,*c,*d, *n, *m;

    a = (struct noeud*)malloc(sizeof(struct noeud));
    a->val = 3;
    a->fg = NULL;
    a->fd = NULL;

    b = (struct noeud*)malloc(sizeof(struct noeud));
    b->val = 6;
    b->fg = a;

    c = (struct noeud*)malloc(sizeof(struct noeud));
    c->val = 9;
    c->fg = NULL;
    b->fd = c;

    d = (struct noeud*)malloc(sizeof(struct noeud));
    d->val = 12;
    d->fd = NULL;
    d->fg = NULL;
    c->fd = d;

    n = (struct noeud*)malloc(sizeof(struct noeud));
    n->val = 8;
    n->fd = NULL;
    n->fg = NULL;
    
    m = (struct noeud*)malloc(sizeof(struct noeud));
    m->val = 5;
    m->fd = NULL;
    m->fg = NULL;
    
    ajoutePetit(b, n);
    ajoutePetit(b, m);


    parcour_arbre_largeur(b, f);

    printf("\n");
}