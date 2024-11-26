#include <stdio.h>
#include <unistd.h> // Pour getpid()

// Fonction exécutée par les threads
void* th(void* arg) {
    // Affiche l'identifiant du thread et le PID du processus
    printf("Thread %lu exécuté, processus %d\n", pthread_self(), getpid());
    pthread_exit(NULL); // Terminaison propre du thread
}

int main(int argc, char* argv[]) {
    pthread_t id1, id2; // Identifiants des threads

    // Création des threads
    pthread_create(&id1, NULL, th, NULL); 
    pthread_create(&id2, NULL, th, NULL);

    // Attente de la fin des threads
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    // Affiche l'identifiant du thread principal et le PID
    printf("Fin du thread principal %lu; processus %d\n", pthread_self(), getpid());

    pthread_exit(NULL); // Terminaison propre du programme
}
