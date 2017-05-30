CC = gcc
RM = rm -f    
LDFLAGS = -L../lib/ -lplatform_driver -Wl,-rpath,/root/
CFLAGS = -O0 -g -I../include/ -I.

TARGET_BIN = fan sys psu thermal
    
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

sys: sys.o
	$(CC) -o sys sys.o $(LDFLAGS)

sys.o: sys.c
	$(CC) $(CFLAGS) -c -o sys.o sys.c

psu: psu.o
	$(CC) -o psu psu.o $(LDFLAGS)

psu.o: psu.c
	$(CC) $(CFLAGS) -c -o psu.o psu.c

thermal: thermal.o
	$(CC) -o thermal thermal.o $(LDFLAGS)

thermal.o: thermal.c
	$(CC) $(CFLAGS) -c -o thermal.o thermal.c

.PHONY: clean
clean:
	-${RM} ${TARGET_BIN} *.o
