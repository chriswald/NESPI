CC = gcc
CFLAGS = -std=c99
OBJS = gpio.o config.o controller.o keys.o
OUT = nespi
LIBS = -lwiringPi

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJS)
	gcc  -o $(OUT) $(OBJS) $(LIBS)

install: all
	cp $(OUT) /sbin/$(OUT)

autostart: install
	echo "/sbin/$(OUT)" >> /etc/rc.local

clean:
	-rm -f $(OBJS)
	-rm -f $(OUT)