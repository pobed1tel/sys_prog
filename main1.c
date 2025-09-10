#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();
    if (pid != 0){
        printf("Я - родитель, мой PID: %d\n", getpid());
    }
    else{
        printf("Я - ребенок, мой PID: %d\n", getpid());
    }

    return 0;
}