
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *PrintHello(void *thread_id){
  long tid;
  tid = (long)thread_id;
  printf("Hello World. Greetings from thread #%ld!\n", tid);
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  int status;
  long i;
  for(i=0; i< NUM_THREADS; i++){
    printf("Main here. Creating thread %ld\n", i);
    status = pthread_create(&threads[i], NULL, PrintHello,(void *)i);
    if (status != 0){
      printf("Oops. pthread_create returned error code %d\n", status);
      exit(-1);
    }
  }
  pthread_exit(NULL);
}
