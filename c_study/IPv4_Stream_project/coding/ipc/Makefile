CFLAGS	+=-Wall -g -lstdc++ -lpthread -D_FILE_OFFSET_BITS=64 -D_DEFAULT_SOURCE -O2
LDFLAGS += -lcrypt
bin = ./
src = $(wildcard *.c)
obj = $(patsubst %.c,%,$(src))

ALL:$(obj)

%:%.c
	gcc $< -o $(bin)$@ $(CFLAGS) $(LDFLAGS)

clean:
	-rm -i $(bin)*

.PHONY:clean ALL