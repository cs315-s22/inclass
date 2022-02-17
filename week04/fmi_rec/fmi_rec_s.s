.global fmi_rec_s

@ r0 is arr
@ r1 is arr length
@ r2 is index to start at
@ r3 is index of current max in arr

fmi_rec_s:
    sub sp, sp, #16
    str lr, [sp]        @ preserve LR
    str r4, [sp, #4]    @ preserve r4. *(sp+4) = r4
    str r5, [sp, #8]    @ preserve r5. *(sp+8) = r5
    
    cmp r2, r1          @ base case?
    bge return_max

    ldr r4, [r0, r2, lsl #2]    @ r4 = *(r0+(r2<<2)) arr[idx]
    ldr r5, [r0, r3, lsl #2]    @ r5 = *(r0+(r3<<2)) arr[max_idx]
    cmp r4, r5          @ new max?
    ble recurse
    mov r3, r2          @ set up idx as max_new for recursion
recurse:
    add r2, r2, #1      @ set up idx + 1 in r2
    bl fmi_rec_s
    b done
return_max:
    mov r0, r3          @ set up max_idx in r0
done:
    ldr r5, [sp, #8]    @ restore r5
    ldr r4, [sp, #4]    @ restore r4
    ldr lr, [sp]        @ restore LR from SP
    add sp, sp, #16     @ dealloc stack space
	bx lr
