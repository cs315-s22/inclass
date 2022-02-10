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

@ r0 is char we want to count
@ r1 is the string
@ r2 is the length

count_char_s:
	sub sp, sp, #16		@ prologue
	str r0, [sp]		@ preserves c across calls to find_char_index_s
	str lr, [sp, #4]	@ preserve lr
	str r4, [sp, #8]	@ preserve r4

	mov r3, r2			@ r3 is length
	mov r2, #0			@ r2 is start
	mov r4, #0			@ r4 is count
	
count_loop:
	bl find_char_index_s
	cmp r0, #-1
	beq count_done
	add r4, r4, #1 		@ count += 1
	add r2, r0, #1 		@ start = r + 1
	ldr r0, [sp]		@ restore c into r0
	b count_loop
count_done:
	mov r0, r4			@ set up count rv
	ldr r4, [sp, #8]	@ restore r4
	ldr lr, [sp, #4]	@ restore lr
	add sp, sp, #16		@ deallocate stack space
	bx lr
