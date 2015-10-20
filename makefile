CC = gcc
CFLAGS = -std=c99
OBJS = gpio.o config.o controller.o keys.o
OUT = nespi
LIBS = -lwiringPi -lX11 -lXtst

all: $(OBJS)
	gcc  -o $(OUT) $(OBJS) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

install: all
	cp $(OUT) /sbin/$(OUT)

autostart: install
	echo "/sbin/$(OUT)" >> /etc/rc.local

clean:
	-rm -f $(OBJS)
	-rm -f $(OUT)