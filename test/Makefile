CC = gcc
RM = rm -f    
LDFLAGS = -L../lib/ -lplatform_driver -Wl,-rpath,/root/ashu/
#LDFLAGS = -L/home/user/workspace/arrcus_onlp/bin/ -larrcus_onlp -Wl,-rpath,/root/ashu/
CFLAGS = -O0 -g -I/usr/include/arrcus_onlp/onlp/ -I../include/ -I.

TARGET_BIN = fan sys psu thermal led sfp sfp_decoding
    
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

sfp: sfp.o
	$(CC) -o sfp sfp.o $(LDFLAGS)

sfp.o: sfp.c
	$(CC) $(CFLAGS) -c -o sfp.o sfp.c

sfp_decoding: sfp_decoding.o
	$(CC) -o sfp_decoding sfp_decoding.o $(LDFLAGS)

sfp_decoding.o: sfp_decoding.c
	$(CC) $(CFLAGS) -c -o sfp_decoding.o sfp_decoding.c

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

led: led.o
	$(CC) -o led led.o $(LDFLAGS)

led.o: led.c
	$(CC) $(CFLAGS) -c -o led.o led.c

.PHONY: clean
clean:
	-${RM} ${TARGET_BIN} *.o
