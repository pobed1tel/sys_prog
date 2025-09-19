#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* func1(void* arg){
    while(1){
       sleep(1);
        int randnum = rand() % 101;
        if (randnum % 2 == 0){
            printf("число %d является четным\n", randnum);
        }
        else {
            printf("число %d является нечетным\n", randnum);
        }
    }
    return NULL;
}

void* func2(void* arg){
    while(1)
    {
        sleep(1);
        int rnd1 = rand() % 101;
        int rnd2 = rand() % 101;
        if (rnd2 == 0){
            printf("на ноль нельзя делить\n");
            continue;
        }
        float res = (float)rnd1 / (float)rnd2;
        printf("деление числа %d на число %d равно %f\n", rnd1, rnd2, res);
    }
    return NULL;
}

void* func3(void* arg){
    while(1){
        sleep(1);
        int rnd1 = rand() % 101;
        int rnd2 = rand() % 101;
        int res = rnd1 + rnd2;
        printf("результат сложения %d и %d равно %d\n", rnd1, rnd2, res);
    }
}

int main(){
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_create(&thread3, NULL, func3, NULL);



    sleep(10);
    return 0;
}