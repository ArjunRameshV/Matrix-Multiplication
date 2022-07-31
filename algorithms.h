#include<stdint.h>
#include<assert.h>

// Note: 1D array A[i*columns + j] represents 2D array A[i][j]

void iterative(int rows, int columns, float* A, float* B, float* C){
  for (int i=0; i<rows; i++){ // iterate through vectors of matrix A (the rows)
    for(int j=0; j<rows; j++){ // iterate through vectors of matrix B (the columns)
      // sum of dot product of each a row with each column
      for(int k=0; k<columns; k++){
        C[i*columns + j] += A[i*columns + k] * B[k*columns + j];
      }
    }
  }
}

void block_method_one(int block_size ,int rows, int columns, float* A, float* B, float* C){
 for (int i=0; i<rows; i+=block_size){
    for(int j=0; j<rows; j+=block_size){
      for(int k=0; k<columns; k+=block_size){
        for(int bi=i; bi<i+block_size; bi++){
          for(int bj=j; bj<j+block_size; bj++){
            for(int bk=k; bk<k+block_size; bk++){
              C[bi*columns + bj] += A[bi*columns + bk] * B[bk*columns + bj];
            }
          }
        }
      }
    }
  } 
}

void block_method_two(int block_size ,int rows, int columns, float* A, float* B, float* C){
 for (int i=0; i<rows; i+=block_size){
    for(int j=0; j<rows; j+=block_size){
      for(int bi=i; bi<i+block_size; bi++){
        for(int bj=j; bj<j+block_size; bj++){
          for(int k=0; k<rows; k++){
            C[bi*columns + bj] += A[bi*columns + k] * B[k*columns + bj];
          }
        }
      }
    }
  } 
}