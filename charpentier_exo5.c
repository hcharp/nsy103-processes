#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int glob = 420;

int main(void)
{
    int loc = 69;

    pid_t p = fork(); // ici on crée le fils et on prend son pid
    if (p == 0) {
        sleep(2);
        printf("fils de %d - pid : %d - var. globale : %d - var. locale : %d\n", getppid(), getpid(), glob, loc);
        sleep(1);
    }
    else {
        waitpid(p, 0, 0);
        glob = 119;
        loc = 1312;
        printf("père de %d - pid : %d - var. globale : %d - var. locale : %d\n", p, getpid(), glob, loc);
    }
}
// Les variables ne changent pas pour le fils, parce que, comme M Garcia l'a dit en cours,
// il y a clonage mais ensuite chacun fait ce qu'il veut, ils sont indépedants les uns des autres