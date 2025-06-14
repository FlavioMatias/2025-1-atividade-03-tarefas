// Exemplo de uso de threads Posix em C no Linux
// Compilar com gcc exemplo.c -o exemplo -lpthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

// cada thread vai executar esta função
void *print_hello(void *threadid) 
{
    long tid = (long)threadid;
    printf("%ld: Hello World!\n", tid);
    sleep(5);
    printf("%ld: Bye bye World!\n", tid);
    pthread_exit(NULL); // encerra esta thread
}

int main(int argc, char *argv[]) 
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Main: criando thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
        
        if(rc) {
            printf("Erro ao criar thread %ld; codigo: %d\n", t, rc);
            exit(-1);
        }
    }
    
    // Espera todas as threads terminarem
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    printf("Main: todas as threads terminaram\n");
    pthread_exit(NULL); // encerra a thread principal
    
    return 0;
}