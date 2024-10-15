#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int val;
    struct maillon *suivant;
    struct maillon *avant;
};


void afficheListChaine(struct maillon *l)
{

    while (l != NULL)
    {
        printf("%d; ", l->val);
        l = l->suivant;
    }
}


struct maillon *ajoute2(int val, struct maillon *l) {
    struct maillon *ptr;
    ptr = (struct maillon *)malloc(sizeof(struct maillon));
    ptr->val = val;
    ptr->suivant = l;  
    ptr->avant = NULL; 
    if (l != NULL) {
        l->avant = ptr;
    }
    return ptr; 
}


struct maillon *ajout_dans_liste_2chaine_tri(struct maillon *l, int e) {
    struct maillon *temp = (struct maillon *)malloc(sizeof(struct maillon));
    temp->val = e;
    temp->suivant = NULL;
    temp->avant = NULL;
    if (l == NULL) {
        return temp; 
    }
    if (e <= l->val) {
        temp->suivant = l;
        l->avant = temp;
        return temp; 
    }

    struct maillon *tmp = l;
    while (tmp->suivant != NULL && tmp->suivant->val < e) {
        tmp = tmp->suivant;
    }
    temp->suivant = tmp->suivant;
    temp->avant = tmp;
    if (tmp->suivant != NULL) {
        tmp->suivant->avant = temp;
    }
    tmp->suivant = temp;
    return l;
}


struct maillon *trouve_element_par_valeur(struct maillon *l, int val) {
    while (l != NULL) {
        if (l->val == val) {
            return l; 
        }
        l = l->suivant;
    }
    return NULL;
}

struct maillon *supprime_dans_liste_2chaine_tri(struct maillon *l, struct maillon *element) {

    if(element->avant == NULL){
         l = element->suivant;
         if(l != NULL){
         l->avant = NULL;
         }
         free(element);
         return l;
    }
    if(element->suivant == NULL){
        element->avant->suivant = NULL;
        free(element);
        return l;
    }
    element->avant->suivant = element->suivant;
    element->suivant->avant = element->avant;
    free(element);

    return l;
}

int main(){

    struct maillon *l = NULL;
    l = ajoute2(6, l);
    l = ajoute2(4, l);
    l = ajoute2(3, l);
    l = ajoute2(2, l);
    afficheListChaine(l);
    printf("\n");
    l = ajout_dans_liste_2chaine_tri(l, 5);
    afficheListChaine(l);
    printf("\n");
    int valeur_a_supprimer = 5;
    struct maillon *element_a_supprimer = trouve_element_par_valeur(l, valeur_a_supprimer);
    l = supprime_dans_liste_2chaine_tri(l, element_a_supprimer);
    printf("\n");
    afficheListChaine(l);

}