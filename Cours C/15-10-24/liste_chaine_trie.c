#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int val;
    struct maillon *suivant;
};

void afficheListChaine(struct maillon *l)
{

    while (l != NULL)
    {
        printf("%d; ", l->val);
        l = l->suivant;
    }
}

struct maillon *ajoute(int val, struct maillon *l)
{
    struct maillon *ptr;
    ptr = (struct maillon *)malloc(sizeof(struct maillon));
    ptr->val = val;
    ptr->suivant = l;
    l = ptr;
    return l;
}


struct maillon *ajouteQueue(int val, struct maillon *l)
{
    // Allouer un nouveau maillon
    struct maillon *temp = (struct maillon *)malloc(sizeof(struct maillon));
    temp->val = val;
    temp->suivant = NULL;

    if (l == NULL)
    {
        return temp;
    }

    struct maillon *ptr = l;
    while (ptr->suivant != NULL)
    {
        ptr = ptr->suivant;
    }

    ptr->suivant = temp;
    return l;
}


struct maillon *ajout_dans_liste_chaine_tri(struct maillon *l, int val)
{

    struct maillon *temp = l;
    struct maillon *avant = l;

    if (temp->val > val)
    {
        temp= ajoute(val, l);
        return temp;
    }

    while (temp != NULL  && temp->val <= val)
    {
        avant = temp;
        temp = temp->suivant;
    }

    if (temp != NULL)
    {
        temp = ajoute(val, temp);
        avant->suivant = temp;
    }
    else
    {   
        temp = ajouteQueue(val, l);
    }
    return l;
}


// facon recursive : 

struct maillon *rec_ajout_dans_liste_chaine_tri(struct maillon *l, int val) {
    if (l == NULL || l->val > val) {
        struct maillon *nouveau = ajoute(val, l);
        return nouveau;
    }
    else {
        l->suivant = rec_ajout_dans_liste_chaine_tri(l->suivant, val);
        return l;
    }
}



int main(){

    struct maillon *l = NULL;
    l = ajoute(6, l);
    l = ajoute(4, l);
    l = ajoute(3, l);
    l = ajoute(2, l);


    l = rec_ajout_dans_liste_chaine_tri(l,5);
    afficheListChaine(l);

}