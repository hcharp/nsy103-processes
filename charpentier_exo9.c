/*
Écrivez un programme qui crée deux fils. Chaque fils doit attendre un nombre de secondes aléatoire
entre 1 et 4. Le programme attend que les fils se terminent et affiche la valeur du nombre de
secondes du processus le plus long et du plus court. Assurez vous que le temps d'attente des
processus est vraiment aléatoire par processus.
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int statut1, statut2;
    pid_t f1 = fork();
    int temps_f1;
    int temps_f2;
    
    if (f1!=0) // si c'est le père
    {
        pid_t f2 = fork();

        if (f2==0)
        {
            srand(getpid());
            temps_f2 = rand() % 5 + 1;
            printf("fils 2\ntemps : %d\npid : %d\n\n",temps_f2, getpid());
            sleep(temps_f2);
            exit(temps_f2);
        }

        int p1 = wait(&statut1); // premier fils arrivé
        int p2 = wait(&statut2); // le wait attend le premier processus qui fait un exit
        printf("premier fils arrivé : \ntemps : %d\npid : %d\n\ndeuxième : \ntemps : %d\npid : %d",
            WEXITSTATUS(statut1),
            p1,
            WEXITSTATUS(statut2),
            p2);
    }

    if (f1==0)
    {
        srand(getpid());
        temps_f1 = rand() % 5 + 1;
        printf("fils 1\ntemps : %d\npid : %d\n\n",temps_f1, getpid());
        sleep(temps_f1);
        exit(temps_f1);
    }

}