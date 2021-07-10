/*
Écrivez un programme qui crée un processus fils. Le fils génère un nombre aléatoire entre 0 et 5 et
l'affiche. Le père récupère ce nombre avec wait et l'affiche. Rappel : pour utiliser des nombre
aléatoires, vous devez définir une graine avec srand puis générer le nombre avec rand.
Traditionnellement la graine est le pid du processus qui cherche à produire le nombre aléatoire.
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    int statut;
    int random_max5;
    pid_t p = fork();
    if (p==0) {
        int pidfils = getpid(); // CORRECTION
        srand(pidfils); // CORRECTION
        /*
        il faut faire un srand avec l'heure qui défile car l'ordinateur ne sait pas faire d'aléatoire tout seul
        Dans ce cas, la graine c'est le temps mais nous ici on utilise le pid du fils comme graine
        */
        random_max5 = rand() % 5;
        exit(random_max5);
    } else {
        wait(&statut); // récupère le message de sortie
        printf("%d\n", WEXITSTATUS(statut)); // récupère la valeur du message de sortie
    }

}
