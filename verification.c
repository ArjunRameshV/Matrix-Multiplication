#include<stdint.h>
#include<stdio.h>
#include<assert.h>

#include "algorithms.h"
#include "utility.h"

#define N 4
#define BLOCK 2

float A[N][N] = {
            {0.0,1.0,2.0,3.0},
            {4.0,5.0,6.0,7.0},
            {8.0,9.0,10.0,11.0},
            {12.0,13.0,14.0,15.0},
};
float B[N][N] = {
            {0.0,1.0,2.0,3.0},
            {4.0,5.0,6.0,7.0},
            {8.0,9.0,10.0,11.0},
            {12.0,13.0,14.0,15.0},
};
float C[N][N] = {0};

int main(){
  assert(N%BLOCK==0);

  uint64_t start = nanos();
  
  iterative(N, N, A[0], B[0], C[0]);

  uint64_t end = nanos();
  double gflop = (N*N*2.0*N)*1e-9;
  double s = (end-start)*1e-9;

  printf("%f GFLOPS\n\n", gflop/s);
  print_matrix(N, N, C[0]);

  return 0;
}