#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

int N;
int global = 10;
int entering[100];
int number[100];

int max(int number[100]) {
    int i = 0;
    int maximum = number[0];
    for (i = 0; i < N; i++) {
        if (maximum < number[i])
            maximum = number[i];
        }
    return maximum;
    }

void lock(int i) {
    int j = 0;
    entering[i] = TRUE;
    number[i] = 1 + max(number);
    entering[i] = FALSE;
    for (j = 0; j < N; j++) {
        while (entering[j]);
        while (number[j] != 0 && (number[j] < number[i] || (number[i] == number[j]) && j < i)) {}
    }
}

void unlock(int i) {
    number[i] = 0;
}

void *fn(void *integer) {
    int i = (int) integer;
    lock(i);
    printf("\n\n-----------Process %d---------",i);
    printf("\nProcess %d is Entering Critical Section\n",i);
    global++;
    printf("%d is the value of global \n",global);
    printf("Process %d is leaving Critical Section\n",i);
    printf("----------------------------------\n\n");
    unlock(i);
}    


int main()
{
    printf("Enter Number of Process\n");
    scanf("%d",&N);
    int th[N];
    void *fn(void *);
    pthread_t thread[N];
    int i = 0; 
    for (i = 0; i < N; i++) {
        th[i] = pthread_create(&thread[i], NULL, fn, (void *)i); 
        pthread_join(thread[i], NULL);
    }
    return EXIT_SUCCESS;
}