@ tell the assembler and the linker that add2_s is a public function
.global add2_s

@ add2_s
@ r0 is a
@ r1 is b
@ C paramters go left-to-right into r0-r3
add2_s:
    add r0, r0, r1  @ r0 = r0 + r1

    @ mul r0, r1, r2
    @ sub r0, r1, r2
    
    bx lr
