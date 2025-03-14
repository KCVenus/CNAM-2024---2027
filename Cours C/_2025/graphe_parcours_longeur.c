#include <stdio.h>
#include <stdlib.h> 



void parcours_prof_cc(int G[], int n, int s, int M[] ){ // composant connexe
    M[s] = 1;

    printf("noeud %d\n", s);
    for(int v =0; v < n; v++){
        if(G[n*s+v] && !M[v]){
            M[v]=1;
            parcours_prof_cc(G,n,v,M);
        }
    }

}

void parcours_prof(int G[], int n){
    int *M,v,s;

    M=(int *)malloc(sizeof(int)*n);
    for(v=0; v < n; v++)
        M[v] = 0;
    for(s=0; s < n; s++){
        if(M[s] == 0){
            parcours_prof_cc(G,n,s, M);
        }
    } 
}


int main(){
    int G[4*4] ={0,1,0,1,
                 1,0,1,0,
                 0,1,0,0,
                 1,0,0,0};
    
    parcours_prof(G,4);

}  