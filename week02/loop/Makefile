OBJS = loop.o loop_c.o loop_s.o 
PROG = loop

%.o: %.c
	gcc -c -g -o $@ $<
	# gcc -c -g -o loop.o loop.c

%.o: %.s
	as -g -o $@ $<
	# as -g -o loop_s.o loop_s.s

$(PROG): $(OBJS)
	gcc -g -o $(PROG) $^

clean:
	rm -rf $(PROG) $(OBJS)
