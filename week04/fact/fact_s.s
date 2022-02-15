.global fact_s

fact_s:
	sub sp, sp, #8
	str lr, [sp]

	cmp r0, #1 			@ base case?
	beq done

	str r0, [sp, #4]	@ preserve n
	sub r0, r0, #1		@ set up n-1
	bl fact_s
	ldr r1, [sp, #4]	@ restore n into r1
	mul r0, r0, r1		@ n * fact_s(n-1)
done:
	ldr lr, [sp]		@ epilogue
	add sp, sp, #8
	
	bx lr
