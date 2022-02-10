.global index1_s

@ r0 contains the address of an array of 4-byte integers
@ r1 contains len
index1_s:
    mov ip, #0      @ length = 0
loop:
    cmp ip, r1      @ reached the end of the array?
    bge loop_done
    ldr r2, [r0]    @ r2 = *arr
    add ip, ip, #1  @ increment count
    add r0, r0, #4  @ walk arr forward to the next 4-byte integer
    b loop
        
loop_done:
    mov r0, ip      @ set up return value in r0
    bx lr
