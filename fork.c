#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h> 


int main() {
    setlocale(LC_ALL, "");

    int n, fork_return, pid_original;

    wprintf(L"Antes do fork\n");

    pid_original = getpid(); // recolhe o pid original 

    wprintf(L"Digite N: ");
    wscanf(L"%d", &n);

    n--; // decrementa o valor de N para ter equivalência de processos

    // fork_return = fork();

    for (int i = 0; i < n; i++) {
        if (pid_original == getpid()) { // verifica se o pid id é o mesmo
            fork();
        } else {
            wprintf(L"Meu pid: %d, meu ppid: %d\n");
        }
    }

    wprintf(L"Depois do fork\n");    
    
    while(1);
}
