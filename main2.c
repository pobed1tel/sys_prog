#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();
    
    if (pid != 0){
        printf("Я - родитель, мой PID: %d\n", getpid());
    }
    else{
        printf("Я - потомок, мой PID: %d\n", getpid());
        pid_t pid2 = fork();
        if (pid2 == 0){
            printf("Я - внук, мой PID: %d\n", getpid());
        }
    }

    return 0;
}