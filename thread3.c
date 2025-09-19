#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int counter = 0;

void* func1(void* arg){
    for (int i = 0; i <= 1000000; i++)
        counter++;
    return NULL;
}

void* func2(void* arg){
    for (int i = 0; i <= 1000000; i++)
        counter++;
    return NULL;
}

int main(){
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, &func1, NULL);
    pthread_create(&thread2, NULL, &func2, NULL);
    sleep(5);
    printf("значение после увелечения двумя потоками: %d", counter);
    return 0;
}