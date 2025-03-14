#include <stdio.h>
#include <stdlib.h> 

struct maillon
{
    int val;
    struct maillon * voisin;
};

struct file{
    struct maillon * tete;
    struct maillon * queueu;
};

void enfile (struct file *f, int e){

    struct maillon * ptr;
    ptr =(struct maillon *) malloc ( sizeof(struct maillon));

    if(f->queueu != NULL){
        f->queueu->voisin = ptr;
        f->queueu = ptr;
    }else{
        f->tete=ptr;
        f->queueu =ptr;
    }
    ptr->val = e;
    ptr->voisin = NULL;

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
        f->tete = ptr->voisin;     // étape 3 
        free(ptr);
        return tmp;
    }else{

        printf("la liste est vide aled oskour");
    }

}

void parcours_largeur_cc(int G[], int n, int s, int M[]){   // composant connexe
    struct file *f = (struct file *) malloc(sizeof(struct file));
    M[s] = 1;
    f->tete = NULL;      
    f->queueu = NULL; 
    enfile(f,s);


    while(f->tete != NULL){
        int u = defile(f);
        printf(" %d, \n",u);
        for(int v = 0; v < n ; v++){
            if(G[n*u+v] && !M[v]){
                M[v]=1;
                enfile(f,v);
            }
        }
    }
    free(f);
}

void parcours_largeur(int G[], int n){
    int *M,v,s;

    M=(int *)malloc(sizeof(int)*n);
    for(v=0; v < n; v++)
        M[v] = 0;
    for(s=0; s < n; s++){
        if(M[s] == 0){
            parcours_largeur_cc(G,n,s, M);
        }
    }
    free(M);
}


int parcours_exist(int G[], int a, int b){
       
}

int main(){
    int G[4*4] ={0,0,0,1,
                 0,0,1,0,
                 0,1,0,0,
                 1,0,0,0};
    
    parcours_largeur(G,4);

}  