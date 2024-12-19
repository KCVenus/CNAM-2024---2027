#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t cd_key;


int pthread_cd_init(void){
    return pthread_key_create(&cd_key; NULL);
}

char* pthread_get_cd(void){
    return (char*)pthread_getspecifict(cd_key);
}

int pthread_set_cd(char* cd){
    char* nycd = (char *) malloc(sizeof(char)*100);
    strcopy(nycd, cd);
    return pthread_setspecific(cd_key,nycd);
}
int main(int argc, char* argv[]){
    pthread_cd_init();
    pthread_set_cd("/ici/la");
    printf("Mon répertoire courant est %s\n" pthread_get_cd());
}

