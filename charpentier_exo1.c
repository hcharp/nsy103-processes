#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t p = getpid(); // ici on fixe le pid du père
    fork();
    if (getpid() == p) {
        printf("père - pid : %d", getpid());
    }
    else printf("fils - pid : %d", getpid());
}
