OBJS = add2.o add2_c.o add2_s.o

%.o: %.c
	gcc -g -c -o $@ $<

%.o: %.s
	as -g -o $@ $<

add2: $(OBJS)
	gcc -g -o add2 $^

clean:
	rm -rf $(OBJS) add2
