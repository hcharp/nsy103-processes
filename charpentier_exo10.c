/*
Écrivez un programme qui réalise le traitement suivant :
- un processus père crée successivement 2 processus fils puis se met en sommeil 7 secondes avant
de se terminer proprement.
- le premier fils affiche sur la sortie standard les valeurs de 1 à 25, temporisé par usleep(15), puis se
termine normalement par l’instruction exit en retournant un statut égal à 1.
- le second fils affiche sur la sortie standard les valeurs de 26 à 50, temporisé par usleep(15), puis se
termine normalement par l’instruction exit en retournant un statut égal à 2.
Exécutez plusieurs fois ce programme et comparez ses différentes exécutions. Qu'en déduisezvous ?
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    pid_t p1 = fork();

    if (p1!=0) // dans le père
    {
        pid_t p2 = fork(); // création du fils
        sleep(7);

        if(p2==0)
        {
            for (int i = 26; i < 51; i++)
            {
                printf("%d - ", i);
            }  
            exit(2);
        }

    }

    if (p1==0) // premier fils
    {
        for (int i = 1; i < 26; i++)
        {
            printf("%d - ", i);
        }        
        
        exit(1);
    }
    

}


/*
Je n'ai pas fait de /n donc pas de mélange
*/

/*
Normal qu'on ait une exécution chaotique parce que l'affichage à l'écran est indépendant.
Si 12000 processus veulent écrire à l'écran, il y a un système d'attente
Il faudrait un comportement non déterministe.
*/