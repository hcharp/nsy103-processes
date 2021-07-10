#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork(); printf("fork(1)\n");
    fork(); printf("fork(2)\n");
    fork(); printf("fork(3)\n");
    return(0);
}

// Avant exécution : 
// On a besoin de la bibliothèque stdio pour l'affichage à l'écran, de unistd pour les appels de fonctions POSIX (fork), et de sys/types pour rien
// On entre dans le main, et, successivement :
// un processus fils est créé avec fork();
// le message "fork(1)" s'affiche et passe à la ligne
// un processus fils est créé avec fork();
// le message "fork(2)" s'affiche et passe à la ligne
// un processus fils est créé avec fork();
// le message "fork(3)" s'affiche et passe à la ligne
// le programme renvoie la valeur 0

// Après exécution et explication par M Garcia :
// finalement il s'affiche : 
// fork(1)
// fork(2)
// fork(1)
// fork(3)
// fork(2)
// fork(2)
// fork(3)
// fork(3)
// fork(2)
// fork(3)
// fork(3)
// fork(3)
// fork(3)
// fork(3)
// C'est parce que le programme ne contrôle pas quand le message sera affiché, il reste un certain temps dans le buffer
// et les processus ne sont pas exécutés jusqu'à leur fin mais à tour de rôle