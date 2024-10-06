#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    printf("before fork \n");

    int var = 0;

    int id = fork();

    if(id < 0)
    {
        printf("process not created\n");
    }

    else if(id == 0)
    {
        printf("child process is created %d\n" , getpid());
        var++;
        printf("var in child process is %d\n" , var); // ans is 1 becz child and parent not share the memory

        execlp("/bin/ls" , "ls" , NULL);
    }
    else
    {
        wait(NULL); // parent wait for the child to finish 
        printf("in parents process child pid is %d and parent pid is %d\n" , id , getpid());
        var++;
        printf("var in parent process is %d\n" , var); // ans is 1 becz child and parent not share the memory
    }

    printf("var out side %d and pid is %d\n" , var , getpid()); 
    
    return 0;
}

/* ------------------ output -----------------  */

/*

before fork
in parents process child pid is 468549 and parent pid is 468548
var in parent process is 1
var out side 1 and pid is 468548
child process is created 468549
var in child process is 1
var out side 1 and pid is 468549


* Zombie process : when child terminates it become zombie process the parent collects its exit status using wait() or
                   waitpid().If the parent does not call wait(), the child remains in the zombie state.


*  the wait(NULL) call ensures the parent process waits for the child to terminate, 
    preventing the child from becoming a zombie.

*/