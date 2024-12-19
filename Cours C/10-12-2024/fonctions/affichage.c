#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "affichage.h"

// Fonction pour calculer la hauteur de l'arbre
int hauteur(struct noeud *arbre) {
    if (arbre == NULL) return 0;
    int hauteur_gauche = hauteur(arbre->fg), hauteur_droite = hauteur(arbre->fd);
    return (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite) + 1;
}



void afficherArbreNiveaux(struct noeud *racine, int niveau, int largeur_espaces) {
    if (racine == NULL) {
        for (int i = 0; i < pow(2, niveau - 1); i++) {
            for (int j = 0; j < largeur_espaces; j++) printf(" ");
        }
        return;
    }
    if (niveau == 1) {
        printf("%*s%d%*s", largeur_espaces / 2, "", racine->val, largeur_espaces / 2, "");
    } else if (niveau > 1) {
        afficherArbreNiveaux(racine->fg, niveau - 1, largeur_espaces);
        afficherArbreNiveaux(racine->fd, niveau - 1, largeur_espaces);
    }
}

void afficherConnexions(struct noeud *racine, int niveau, int largeur_espaces) {
    if (racine == NULL || (racine->fg == NULL && racine->fd == NULL)) {
        for (int i = 0; i < pow(2, niveau - 1); i++) {
            for (int j = 0; j < largeur_espaces; j++) printf(" ");
        }
        return;
    }
    if (niveau == 1) {
        printf("%*s", largeur_espaces / 2 - 1, "");
        if (racine->fg) printf("/");
        else printf(" ");
        printf("%*s", 2, "");
        if (racine->fd) printf("\\");
        else printf(" ");
        printf("%*s", largeur_espaces / 2 - 1, "");
    } else if (niveau > 1) {
        afficherConnexions(racine->fg, niveau - 1, largeur_espaces);
        afficherConnexions(racine->fd, niveau - 1, largeur_espaces);
    }
}

void afficherArbre(struct noeud *racine) {
    int h = hauteur(racine);
    int largeur_espaces = pow(2, h) * 2;

    for (int i = 1; i <= h; i++) {
        afficherArbreNiveaux(racine, i, largeur_espaces);
        printf("\n");
        if (i < h) {
            afficherConnexions(racine, i, largeur_espaces);
            printf("\n");
        }
        largeur_espaces /= 2;
    }
}