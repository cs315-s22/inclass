.global index3_s

index3_s:
	mov ip, #0					@ initialize count
loop:
	cmp ip, r1					@ end of array?
	bge loop_done
	ldr r2, [r0, ip, lsl #2]	@ r2 = *(r0 + (ip << 2))
	add ip, ip, #1
	b loop
loop_done:
	mov r0, ip					@ set up length in r0
	bx lr
