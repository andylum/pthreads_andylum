#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int count = 0;

// function that takes the y value, and the ngoes through a loop that adds to the count
void *counts(void *y){
  long l = (long)y;
  for (int i = 0; i < l; i++){
    count++;
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){
  int status;
  int x;
  long y;
  long j;
  x = 4;
  y = 10000;
  pthread_t threads[x];
  
  for(j = 0; j < x; j++){
    status = pthread_create(&threads[j], NULL, counts,(void *)y);
    if (status != 0){
      printf("Oops. pthread_create returned error code %d\n", status);
      exit(-1);
    }
  }
  printf("%u", count);
  pthread_exit(NULL);
}
