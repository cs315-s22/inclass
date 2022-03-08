.global b3

b3:
    add r0, r1, r2
    sub r0, r1, r2
    b b3
    bx lr
