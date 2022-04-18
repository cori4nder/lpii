#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/wait.h>

#define QTD_THREADS 30
#define QTD_PROCESSOS 30
#define SLEEP_TIME 2

void* funcao_thread(void* p) {
    sleep(2);
}

int main() {
    clock_t t_p1, t_p2, t_p;
    clock_t t_t1, t_t2, t_t;
    int pid_original;

    pthread_t threads[QTD_THREADS];

    pid_original = getpid();
    t_p1 = clock();

    for (int i = 0; i < QTD_PROCESSOS; i++) {
        if (pid_original == getpid()) {
            fork();
        }
    }

    if (pid_original != getpid()) {
        sleep(2);
        exit(0);
    }

    if (pid_original == getpid()) {
        
            if (pid_original == getpid()) {
            t_p2 = clock();
            t_p = t_p2 - t_p1;
            printf("Intanciando 30 processos\n");
            printf("Tempo de execucao: %lf ms\n", (((double)t_p)/(CLOCKS_PER_SEC/1000)));
        }

        t_t1 = clock();

        for (int i = 0; i < QTD_THREADS; i++) {
            pthread_create(&threads[i], NULL, funcao_thread, NULL);
        }

        t_t2 = clock();
        
        t_t = t_t2 - t_t1;

        printf("Instancia 30 threads\n");
        printf("Tempo de execucao: %2.lf ms\n", ((double)t_t/(CLOCKS_PER_SEC/100)));
    }

    return 0;    
}
