.global strlen_s

@ r0 = str
@ returns length
strlen_s:
    mov r2, #0          @ len
loop:
    ldrb r1, [r0]       @ r1 = *str
    cmp r1, #0          @ reach null terminator?
    beq done
    add r2, r2, #1      @ increment length
    add r0, r0, #1      @ walk str forward one byte
    b loop
done:
    mov r0, r2          @ set up return value in r0
    bx lr
    
