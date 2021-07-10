#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t p = fork(); // ici on crée le fils et on prend son pid
    if (p == 0) {
        sleep(3);
        printf("fils de %d - pid : %d \n", getppid(), getpid());
        sleep(3);
    }
    else {
        waitpid(p, 0, 0);
        printf("père de %d - pid : %d\n", p, getpid());
    }
}
