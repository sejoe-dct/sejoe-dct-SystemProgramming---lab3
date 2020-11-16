#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int show_dir(char *command)
{
    int status;
    printf("command: %s\n",command);
    switch(fork()){
       case 0:
            execl("/bin/bash","bin/bash","-c",command, NULL);
            break;
       case -1:
            perror("fork");
            exit(0);
       default:
            wait(&status);
            break;
       }
       return status;
}

int main(int argc, char **argv)
{
    int i = 0;
    int retval;
    char *command;
    char str[30];
    scanf("%[^\n]",&str);
    command=&str;
    retval = show_dir(command);

    printf("Exit Status %d\n", retval);
}
