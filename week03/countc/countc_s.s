.global find_char_index_s

@ r0 is the char c
@ r1 is the string
@ r2 is the start index
@ r3 is the end index

find_char_index_s:
	sub sp, sp, #8		@ prologue
	str r4, [sp]		@ preserve r4
	str r5, [sp, #4]	@ preserve r5
	
	mov ip, r2			@ loop index = start
	mov r4, #-1			@ init rv
loop:
	cmp ip, r3			@ reached end?
	bge done_loop
	ldrb r5, [r1, ip]	@ r5 is str[i]
	cmp r5, r0			@ str[i] == c
	bne not_equal
	mov r4, ip			@ rv = i
	b done_loop
not_equal:
	add ip, ip, #1
	b loop
done_loop:
	mov r0, r4		@ set up rv
	ldr r5, [sp]	@ restore r5
	ldr r4, [sp]	@ restore r4
	add sp, sp, #8	@ dealloc stack
	bx lr

.global count_char_s

count_char_s:
	mov r0, #0
	bx lr
