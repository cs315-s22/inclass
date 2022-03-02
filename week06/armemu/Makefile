OBJS = armemu.o add2_s.o
PROG = armemu

%.o: %.c armemu.h
	gcc -c -g -o $@ $<

%.o: %.s armemu.h
	as -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
