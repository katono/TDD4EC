CC = gcc
CFLAGS = -Wall -g
CFLAGS += -I/usr/local/include
CFLAGS += -I../src
# CFLAGS += -DPCU_NO_LIBC
LFLAGS = -L/usr/local/lib -lpcunit
TARGET = alltests
OBJS = AllTests.o
OBJS += LedDriverTest.o
OBJS += LedDriver.o

VPATH = ../src

all: $(TARGET)

.SUFFIXES: .c .o

.c .o:
	$(CC) $(CFLAGS) -c $<



$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS)
	./$(TARGET)


.PHONY: clean
clean:
	rm -f *.o $(TARGET)

