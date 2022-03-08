.global shift

shift:
    lsl r0, r1, #2
    mov r0, r1, lsl #2
    bx lr
