#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int pid; // identificador de processo
    int status;

    pid = fork(); // replicação do processo

    if (pid < 0) // fork funcionou?
    {
        perror("Erro: "); // não, encerra este processo
        exit(-1);
    }
    else if (pid > 0) // sou o processo pai?
    {
        wait(&status); // sim, vou esperar meu filho concluir
        printf("Tchau !\n");
    }
    else // não, sou o processo filho
    {
        // carrega outro código binário para executar
        execve("/bin/date", argv, envp);
        perror("Erro: "); // execve não funcionou
        exit(-1);
    }
    
    return 0;
}