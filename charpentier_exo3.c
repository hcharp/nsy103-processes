#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t p = fork(); // ici on crée le fils et on prend son pid
    if (p == 0) { // doc de fork() : 0 est retourné au fils quand on est dans le fils
        printf("fils de %d - pid : %d \n", getppid(), getpid());
    }
    else {
        printf("père de %d - pid : %d\n", p, getpid());
        //sleep(2);
    }
}

// Il ne se passe rien quand j'enlève le sleep(2) ou sleep(3) : ça fonctionne quand même
// Ce qu'il devrait se passer, j'imagine : c'est que le printf va dans le buffer vers l'écran, mais là
// le fils est créé AVANT que le printf n'ait eu le temps d'afficher les infos du père
// et alors il se pourrait que les printf s'emmêlent et fassent n'importe quoi