#ifndef NOEUD_H
#define NOEUD_H

struct noeud {
    int val, hauteur, difference;
    struct noeud *fg, *fd, *p;
};

#endif