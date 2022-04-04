#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h> 
#include <sys/wait.h>

#define COMMAND_SIZE 16


int main() {
    setlocale(LC_ALL, "");

    int fork_result, status_exec;
    char *command, *lista[2];

    command = (char*)malloc(sizeof(char)*COMMAND_SIZE);

    do {
         wprintf(L"Comando: ");
         
         fgets(command, COMMAND_SIZE, stdin);

         wprintf(L"Executando: %s\n", command);

         lista[0] = "ls";
         lista[1] = NULL;

         fork_result = fork();
         
         if (fork_result == 0) {
             wprintf(L"Executando comando: %s\n", command);
             execvp(lista[0], lista);
    
         } else {
             // Processo original
             wait(&status_exec);
             wprintf(L"Status recebido: %d\n", status_exec);
         }

    } while(strcmp(command, "exit\n") != 0);

    if (fork_result > 0) {
        wprintf(L"Saindo...\n");
    }

    char *argv[] = {"ls", "-l", "-h", NULL};
    execvp(argv[0], argv);

    return 0;
}
