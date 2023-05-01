#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

void handle_signail(int sig)
{
    printf("\n");
}

// Print exit message to the user and exit.
void exitmsg()
{
    printf("Returning to the original shell...\n");
    exit(0);
}

// Print error message to the user and exit.
void errormsg()
{
    printf("An error has occurred, returning to the original shell...\n");
    exit(1);
}

int main()
{
    int i;
    char *argv[10];
    char command[1024];
    char *token;

    // For Ctrl+C
    signal(SIGINT, handle_signail);

    while (1)
    {

        printf("stshell> ");

        fgets(command, 1024, stdin);
        command[strlen(command) - 1] = '\0'; // replace \n with \0

        i = 0;
        token = strtok(command, " ");
        while (token != NULL)
        {
            argv[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        argv[i] = NULL;

        if (argv[0] == NULL)
        {
            continue;
        }

        if (strcmp(command, "exit") == 0)
        {
            exitmsg();
        }

        pid_t pid = fork();

        if (pid == -1)
        {
            errormsg();
        }
        if (pid == 0) // child
        {
            // For Ctrl+C
            signal(SIGINT, SIG_DFL);

            int j = 0;
            while (argv[j] != NULL)
            {

                // Redirection with ">"
                if (strcmp(argv[j], ">") == 0)
                {

                    char *file = argv[j + 1];

                    // This line of code creates a file with the name file (which is a string variable)
                    // or opens it if it already exists, with write-only access for the user.
                    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    argv[j] = NULL;
                    break;
                }

                // Redirection with ">>"
                if (strcmp(argv[j], ">>") == 0)
                {

                    char *file = argv[j + 1];

                    // This line of code is creating a file named file, or if it already exists,
                    // opening it in write-only mode with the options O_WRONLY (open for writing only)
                    // and O_CREAT (create the file if it does not exist).
                    int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    argv[j] = NULL;
                    break;
                }

                // Piping
                if (strcmp(argv[j], "|") == 0)
                {
                    int pipes[2]; // 0 - read, 1 - write

                    int pipecheck = pipe(pipes);
                    if (pipecheck < 0)
                    {
                        errormsg();
                    }

                    pid_t pid2 = fork();
                    if (pid2 == -1)
                    {
                        errormsg();
                    }

                    // Child process
                    if (pid2 == 0)
                    {

                        close(pipes[0]);
                        int pipesCount = 0;
                        char *input[10];

                        // Execute the first command
                        while (strcmp(argv[pipesCount], "|"))
                        {
                            input[pipesCount++] = argv[pipesCount++];
                        }

                        input[pipesCount] = NULL;

                        int duplicate = dup2(pipes[1], 1);
                        if (duplicate < 0)
                        {
                            errormsg();
                        }

                        close(pipes[1]);

                        // Execute
                        execvp(input[0], input);
                    }

                    // Parent process
                    else
                    {
                        int i = 0;

                        // Put the second command in array that eventually will be execute.
                        for (int t = j + 1; argv[t] != NULL; t++)
                        {
                            argv[i] = argv[t];
                            i++;
                        }

                        j = -1;

                        argv[i] = NULL;
                        close(pipes[1]);

                        int duplicate = dup2(pipes[0], 0);
                        if (duplicate < 0)
                        {
                            errormsg();
                        }

                        close(pipes[0]);

                        // Wait for the child         ls -l | grep aaa | wc
                        wait(NULL);
                    }
                }
                j++;
            }
            execvp(argv[0], argv); // execute the command
        }
        wait(NULL);
    }
    return 0;
}