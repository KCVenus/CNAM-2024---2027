#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, i, j;
    i = 5;
    j = 2;
    k = fork();
    if (k == -1)
    {
        printf("Erreur fork()");
        exit(1);
    }
    if (k == 0)
    {
        printf("Je suis le fil");
        j--;
        exit(0);
    }
    else
    {
        printf("pere %d\n", getpid());
        i++;
    }
}

// Ex syncro
int main2()
{
    int r, s, w;
    if ((r = fork()) == 0)
    {
        printf("Fils %d\n", getpid());
        exit(14);
    }
    else
    {
        w = wait(&s);
        printf("w:%d s:%d\n", w, s);
    }
}

// Ex interraction C shell

int main3(){
    FILE *fichier;
    fichier=fopen("zob.txt", "w");
    fprintf(fichier, "Yo le rap");
    fclose(fichier);

}

// Ex Pipe
int main4(){
    int p[2]; char ch[50]; // Est dupliqué à cause du fork
    pipe(p);
    if(fork()==0){
        close(p[0]);
        printf("fils ecrit\n");
        sprintf(ch,"ca va papa?\n");
        write(p[1],ch,sizeof(ch));
    }else{
        close(p[1]);
        read(p[0],ch,sizeof(ch));
        printf("Je suis le père");
        printf("le fils dit %s",ch);
    }
}

// Ex interblocage

int main5(){
    int p1[2],p2[2];
    char ch;
    pipe(p1);
    pipe(p2);
    if(fork()==0){
        read(p1[0],ch,sizeof(ch));
        write(p2[1],ch,sizeof(ch));
    }else{
        read(p2[0],ch,sizeof(ch));
        write(p1[1],ch,sizeof(ch));
    }
}