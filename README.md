# Matrix Multiplication

This repository is a contains algorithms to compute matrix multiplications and 
also benchmark comparision of performance between these algorithms and standard libraries like Numpy.

## Matrix Multiplication using Divide and Conquer

### Block Wise Matrix Multiplication

Consider Matrix of size $N=4$ and lets seperate them as blocks of dimension 2.

$$
\begin{aligned}
\underline{Matrix A} \\
\def\arraystretch{1.5}
   \begin{array}{cc:c}
  a_{00} & a_{01} & a_{02} & a_{03}\\ 
  a_{10} & a_{11} & a_{12} & a_{13}\\ \hdashline
  a_{20} & a_{21} & a_{22} & a_{23}\\ 
  a_{30} & a_{31} & a_{32} & a_{33}\\
\end{array}
\end{aligned}
\kern{3em}
\begin{aligned}
\underline{Matrix B} \\
\def\arraystretch{1.5}
   \begin{array}{cc:c}
  b_{00} & b_{01} & b_{02} & b_{03}\\ 
  b_{10} & b_{11} & b_{12} & b_{13}\\ \hdashline
  b_{20} & b_{21} & b_{22} & b_{23}\\ 
  b_{30} & b_{31} & b_{32} & b_{33}\\
\end{array}
\end{aligned}
$$

Matrix A and B can be rearanged as blocks:
$$
\begin{aligned}
\underline{Matrix A} \\
\begin{matrix}
A_{00} & A_{01}\\
A_{10} & A_{11}\\
\end{matrix}
\end{aligned}
\kern{3em}
\begin{aligned}
\underline{Matrix B} \\
\begin{matrix}
B_{00} & B_{01}\\
B_{10} & B_{11}\\
\end{matrix}
\end{aligned}
$$ 
where 
$$
\begin{aligned}
A_{00} = \kern{0.5em}
\begin{matrix}
a_{00} & a_{01}\\
a_{10} & a_{11}\\
\end{matrix}
\end{aligned}
$$
$$
\begin{aligned}
A_{11} = \kern{0.5em}
\begin{matrix}
a_{22} & a_{23}\\
a_{32} & a_{33}\\
\end{matrix}
\end{aligned}
$$

The objective is to get the dot product of $ C = A \odot B $ 

The main idea here is understanding addition is commutative, </br> meaning the order in which addition is done does not effect the final result.

We can formulate C as, 
$$
\begin{aligned}
C = \kern{0.5em}
\begin{bmatrix}
C_{00} & C_{01}\\
C_{10} & C_{11}\\
\end{bmatrix}
\kern{0.5em} = \kern{0.5em}
\begin{bmatrix}
A_{00} & A_{01}\\
A_{10} & A_{11}\\
\end{bmatrix}
\odot
\begin{bmatrix}
B_{00} & B_{01}\\
B_{10} & B_{11}\\
\end{bmatrix}\\ \\
= 
\begin{bmatrix}
A_{00} \cdotp B_{00} + A_{01} \cdotp B_{10} & A_{00} \cdotp B_{10} + A_{01} \cdotp B_{11}\\ \\
A_{10} \cdotp B_{00} + A_{11} \cdotp B_{10} & A_{10} \cdotp B_{10} + A_{11} \cdotp B_{11}\\ 
\end{bmatrix}
\end{aligned} 
$$

```python
# Consider two matrices where N -> matrix size and BLOCK -> block size, here N=4 and BLOCK=2
A = [N][N]
B = [N][N]

for i in range (0, N, BLOCK): # iterate through all the rows of matrix A
  for j in range(0, N, BLOCK): # iterate through all the columns of matrix B
    for k in range(0, N, BLOCK): # iterate through the vector (a row of A and column of B)
      # Now we do perform conventional dot product over the block of matrix
      # The followong will result in computing A00 * 
      for bi in range(i, BLOCK):
        for bj in range(j, BLOCK):
          for bk in range(k, BLOCK):
            c[bi][bj] += A[bi][bk] * B[bk][bj]
```
