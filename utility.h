#include<time.h>

uint64_t nanos(){
  struct timespec start;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  return (uint64_t)start.tv_sec*1000000000 + (uint64_t)start.tv_nsec;
}

int print_matrix(int rows, int columns, float* C){
  for(int i=0; i<rows; i++) {
    for(int j=0;j<columns;j++) {
      printf("%.2f ", C[i*columns + j]);
      if(j==columns-1){
        putchar('\n');
      }
    }
  }
  return 0;
}