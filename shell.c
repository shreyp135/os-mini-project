#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char input[100];     // Store user input
    char *args[10];      // Argument list for execvp()

    while (1) {
        // Display shell prompt
        printf("myshell> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline at end
        input[strcspn(input, "\n")] = 0;

        // Exit command
        if (strcmp(input, "exit") == 0)
            break;

        // Parse input into arguments
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL)
            args[++i] = strtok(NULL, " ");

        // Create child process
        int pid = fork();

        if (pid == 0) {
            // Child executes command
            if (execvp(args[0], args) == -1) {
                printf("Command not found.\n");
            }
            return 0;
        } 
        else if (pid > 0) {
            // Parent waits
            wait(NULL);
        } 
        else {
            printf("Fork failed!\n");
        }
    }

    return 0;
}
