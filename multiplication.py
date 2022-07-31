#!/usr/bin/env python3
import time
import numpy as np

N = 4096 

if __name__ == "__main__":
  for i in range(10):
    A = np.random.randn(N, N).astype(np.float32) 
    B = np.random.randn(N, N).astype(np.float32)
    
    # computing the flops - N*N*2N
    flop = N*N*2*N
    print(f"{flop / 1e9:.2f} GFLOP")

    st = time.monotonic()
    C = A @ B
    et = time.monotonic()
    dt = et- st

    print(f"{flop/dt * 1e-12:2f} TFLOPS")