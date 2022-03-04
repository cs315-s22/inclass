.global add2_s

@ r0 first number to add
@ r1 second number to add

add2_s:
    add r0, r1, r0
    bx lr
