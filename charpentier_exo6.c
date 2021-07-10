/*
Écrivez un programme qui permet de récupérer le code de sortie d'un fils. Vous utiliserez wait, exit
ainsi que la macro WEXITSTATUS.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
    int code ;
    pid_t pepere = getpid(); // ici on fixe le pid du père
    pid_t p = fork() ; // on prend le pid du fils
  
  
    if (p==0) { //fils
        printf ("vous êtes ici dans le fils\n") ;
        exit (2) ;
     } else { // pas de PID, on est dans le pere
        printf (
            "pid du pere = %d\npid du fils = %d, code de sortie du fils = %d\n",
             pepere,
             p,
             WEXITSTATUS (code)) ;
    }

}