#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#include <sys/wait.h>

int main() {
    setlocale(LC_ALL, "");

    int pid_1, pid_2, status_1, status_2, valor;

    wprintf(L"Processo original - %d\n", getpid());

    pid_1 = fork();

    if (pid_1 == 0) {
        wprintf(L"Processo clonado: %d\n", getpid());
        wprintf(L"Digite um número inteiro: ");
        wscanf(L"%d", &valor);
        exit(valor);

        // sleep(10);
        // exit(EXIT_SUCCESS);
    } else {
        pid_2  = fork();
        if (pid_2 == 0) {
            wprintf(L"Segundo clone: %d\n", getpid());
            wprintf(L"Digite um número inteiro: ");
            wscanf(L"%d", &valor);
            wprintf(L"Segundo clone finalizado... (%d)\n", valor);
            exit(111);
        }
    }

    waitpid(pid_1, &status_1, 0);

    wprintf(L"Processo original aguardando ser finalizado do pid %d...\n", pid_1);

    wprintf(L"\n");

    waitpid(pid_2, &status_2, 0);

    wprintf(L"Processo original aguardando ser finalizado do pid %d...\n", pid_2);
    
    wprintf(L"\n");
    
    wprintf(L"Processo original: %d\n", getpid());
    wprintf(L"%d - Processo finalizado com sucesso - status: %d\n", pid_1, WEXITSTATUS(status_1));
    wprintf(L"%d - Processo finalizado com sucesso - status: %d\n", pid_2, WEXITSTATUS(status_2));


    return 0;
}
