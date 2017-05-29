CC = gcc
RM = rm -f    
LDFLAGS = -L../lib/ -lplatform_driver -Wl,-rpath,/root/
CFLAGS = -O0 -g -I../include/ -I.

TARGET_BIN = fan
    
#SRCS = test1.c
#OBJS = $(SRCS:.c=.o)
    
.PHONY: all
all: ${TARGET_BIN}
 
#$(TARGET_BIN): $(OBJS)
#	$(CC) -o $@ $^ $(LDFLAGS)

fan: fan.o
	$(CC) -o fan fan.o $(LDFLAGS)

fan.o: fan.c
	$(CC) $(CFLAGS) -c -o fan.o fan.c

.PHONY: clean
clean:
	-${RM} ${TARGET_BIN} *.o
