#include<stdint.h>
#include<stdio.h>
#include<assert.h>

#include "algorithms.h"
#include "utility.h"

#define N 32
#define BLOCK 16

float A[N][N];
float B[N][N];
float C[N][N] = {0};

int main(){
  assert(N%BLOCK==0);
  int iterations = 1;
  float avg_gflops;

  for(int i=0; i<iterations; i++){
    uint64_t start = nanos();

    // choose the algorithm to benchmark here 
    block_method_two(BLOCK, N, N, A[0], B[0], C[0]);

    uint64_t end = nanos();
    double gflop = (N*N*2.0*N)*1e-9;
    double s = (end-start)*1e-9;
    
    float gflops = gflop/s;
    printf("%f GFLOPS\n", gflops);
    avg_gflops += gflops;
  }

  printf("\n%.3f is the average GFLOPS\n", avg_gflops/iterations);
  return 0;
}