#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#include <sys/wait.h>

int main() {
    setlocale(LC_ALL, "");

    int pid, status, valor;

    wprintf(L"Processo original - %d\n", getpid());

    pid = fork();

    if (pid == 0) {
        wprintf(L"Processo clonado: %d\n", getpid());
        wprintf(L"Digite um número inteiro: ");
        wscanf(L"%d", &valor);
        exit(valor);

        // sleep(10);
        // exit(EXIT_SUCCESS);
    } else {
        
    }

    wprintf(L"Processo original aguardando ser finalizado do pid %d...\n", pid);

    waitpid(pid, &status, 0);
    
    wprintf(L"\n");

    /* if (WEXITSTATUS(status) == 0) {
        wprintf(L"Processo original: %d\n", getpid());
        wprintf(L"%d - Processo %d finalizado com sucesso!\n", pid, WEXITSTATUS(status));
    } */
    
    wprintf(L"Processo original: %d\n", getpid());
    wprintf(L"%d - Processo %d finalizado com sucesso!\n", pid, WEXITSTATUS(status));


    return 0;
}
