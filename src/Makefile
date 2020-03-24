CC = gcc
RM = rm -f
MKDIR = mkdir -p
RMDIR = rm -rf
LDFLAGS = -shared -Wl,--no-as-needed -ldl -Wl,--unresolved-symbols=ignore-in-shared-libs
CFLAGS = -O0 -g -fPIC -I/usr/include/arrcus_onlp/onlp/ -I../include/

TARGET_LIB = ../lib/libplatform_driver.so
    
SRCS = platform_driver.c platform_fan.c platform_sys.c platform_psu.c \
	platform_thermal.c platform_led.c platform_sfp.c
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(MKDIR) ../lib
	$(CC) ${LDFLAGS} -o $@ $^

$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@

include $(SRCS:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
	-${RMDIR} ../lib

