# Array Iteration

Consider the following C code, which iterates through an array `int arr[n]` and does operations on each of it's element. We have two choices for the assembly code.

```c
int arr[n];
for (int i = 0; i < n; i++) {
    // SOME OPERATIONS ON arr[i]
}
```

Iterate through the index, which costs $3+(k+4)n$ **cycles** and $r+4$ **registers**.

```
    li      t0, 0         # cnter on arr idx ----- 1 cycle
    lw      t1, n         # ---------------------- 1 cycle
    lw      t2, arr       # ---------------------- 1 cycle
loop:                     # ---------------------- n iters
    slli    t3, t0, 2     # ---------------------- 1 cycle
    add     t2, t2, t3    # ---------------------- 1 cycle

    # SOME OPERTIONS ON t3 = &arr[i] ------------- r regs, k cycle
    
    addi    t0, t0, 1     # ---------------------- 1 cycle
    blt     t0, t1, loop  # ---------------------- 1 cycle
loop_end:
```

and iterate through the address, which costs $3+(k+2)n$ **cycles** and $r+2$ **registers**.

```
    lw      t0, arr       # cnter on arr addr --- 1 cycle
    lw      t1, n         # --------------------- 1 cycle
    slli    t1, t1, 2     # t1 = &arr[n] -------- 1 cycle
loop:                     # --------------------- n iters
    # SOME OPERATIONS ON t0 = &arr[i] ----------- r regs, k cycle
    
    addi    t0, t0, 4     # --------------------- 1 cycle
    blt     t0, t1, loop  # --------------------- 1 cycle
loop_end:
```

It's obvious that iteration through address is optimal.