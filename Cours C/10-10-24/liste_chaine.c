#include <stdio.h>
#include <stdlib.h>

struct maillon
{
    int val;
    struct maillon *suivant;
};

int liste_vide(struct maillon *l)
{

    if (l != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void afficheListChaine(struct maillon *l)
{

    while (l != NULL)
    {
        printf("\n%d", l->val);
        l = l->suivant;
    }
    printf("\n");
}

// fonction qui renvoie un pointeur sur struct maillon
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

void efface(struct maillon *l)
{

    while (l->suivant != NULL)
    {
        struct maillon *temp = l->suivant;
        free(l);
        l = temp;
    }
}

// facon recursive

void effaceREc(struct maillon *l)
{

    while (l != NULL)
    {
        effaceREc(l->suivant);
        free(l);
    }
}

// a la fin de la boucle a on ajoute maillon par maillon la liste b
void concat(struct maillon *a, struct maillon *b)
{

    while (b != NULL)
    {                           // on vérifie que le maillon existe
        ajouteQueue(b->val, a); // on ajoute à la fin de la liste a le premiere maillon de b ext..
        b = b->suivant;         // on passe au maillon suivant
    }
}

// comme quand on ajoute ou ajoute par le début si j'ajoute maillon par maillon de ma chaine 1
// sur ma chaine 2 la chaine 2 sera la chaine 1 mais dans l'autre sens ie : 1 2 3 4 -> 4 3 2 1
struct maillon *inverse(struct maillon *l)
{
    struct maillon *inv = NULL;
    while (l != NULL)
    {
        inv = ajoute(l->val, inv);
        l = l->suivant;
    }
    return inv;
}

struct maillon *effacer(struct maillon *l, int val)
{

    struct maillon *temp = l;
    struct maillon *avant = l;

    if (l->val == val)
    {
        temp = l->suivant;
        free(l);
        return temp;
    }

    while (temp != NULL  && temp->val != val)
    {
        avant = temp;
        temp = temp->suivant;
    }

    if (temp == NULL)
    {
        printf("\n ya r \n");
    }
    else
    {
        avant->suivant = temp->suivant;
        free(temp);
    }
    return l;
}

int main()
{

    struct maillon *l = NULL;
    l = ajoute(17, l);
    l = ajoute(3, l);
    l = ajoute(2, l);
    l = ajoute(9, l);
    // afficheListChaine(l);
    // efface(l);
    // l = NULL;
    // afficheListChaine(l);
    l = ajouteQueue(6, l);
    // afficheListChaine(l);
    struct maillon *a = NULL;
    a = ajoute(17, a);
    a = ajoute(3, a);
    a = ajoute(2, a);
    a = ajoute(9, a);
    // afficheListChaine(a);
    // struct maillon *b = NULL;
    // b = ajoute(15, b);
    // b = ajoute(10, b);
    // b = ajoute(7, b);
    // b = ajoute(8, b);
    // afficheListChaine(b);
    // concat(a, b);
    // struct maillon *inversea = NULL;
    afficheListChaine(a);
    // inversea = inverse(a);
    // afficheListChaine(inversea);
    a = effacer(a, 17);

    afficheListChaine(a);
}
