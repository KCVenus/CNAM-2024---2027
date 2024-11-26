#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int val;
    struct maillon * suivant;
};

struct file{
    struct maillon * tete;
    struct maillon * queueu;
};

void afficheListChaine(struct file *f)
{

    while (f->tete != NULL)
    {
        printf("%d; ", f->tete->val);
        f->tete = f->tete->suivant;
    }
}


void enfile (struct file *f, int e){

    struct maillon * ptr;
    ptr =(struct maillon *) malloc ( sizeof(struct maillon));

    if(f->queueu != NULL){
        f->queueu->suivant = ptr;
        f->queueu = ptr;
    }else{
        f->tete=ptr;
        f->queueu =ptr;
    }
    ptr->val = e;
    ptr->suivant = NULL;

}



int defile(struct file * f){

    struct maillon *ptr;
    int tmp;

    if(f->tete == f->queueu){
        tmp = f->tete->val;
        ptr = f->tete;
        free(ptr);
        f->tete = NULL;
        f->queueu = NULL;
        return tmp;
    }

    if(f->tete !=NULL){
        tmp = f->tete->val; // étape 1
        ptr = f->tete;      // étape 2 
        f->tete = ptr->suivant;     // étape 3 
        free(ptr);
        return tmp;
    }else{

        printf("la liste est vide aled oskour");
    }

}





int main(){
    struct file *f =(struct file *) malloc ( sizeof(struct file));
    f->tete = NULL;
    f->queueu = NULL;

    for(int i = 0; i < 10; i++ ){
        enfile(f,i);
    }

    afficheListChaine(f);

    printf("%d voici la liste vide : "); 
    while(f->tete = NULL){
    defile(f);
    }

    afficheListChaine(f);
    
}