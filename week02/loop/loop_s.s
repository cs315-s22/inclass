.global s_loop

@ params from C are in r0-r3, left to right
@ r0 = iters

s_loop:
    mov r1, #0      @ init loop index variable
loop:
    add r1, r1, #1  @ increment loop index variable
    cmp r1, r0      @ done?
    beq done        @ if r1 == r0, we're done
                    @ we also have BLT (branch if less than)
                    @ BGT (branch if greater than)

    
    b loop          @ loop again
done:
    bx lr           /* return to caller */
