.global index2_s

index2_s:
	mov ip, #0			@ initialize length to 0
	mov r3, #0			@ r3 is the byte offset into r0 array
loop:
	cmp ip, r1			@ reached end of array?
	bge loop_done
	ldr r2, [r0, r3]	@ r0 is base addr, r3 is offset
	add ip, ip, #1		@ increment count by 1
	add r3, r3, #4		@ increment offset by 4
	b loop
loop_done:
	mov r0, ip			@ set up length in r0
	bx lr
