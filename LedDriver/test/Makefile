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

all: pcunit_register $(TARGET) test

pcunit_register:
	pcunit_register.rb

.SUFFIXES: .c .o

LedDriver.o: ../src/LedDriver.c
	$(CC) $(CFLAGS) -c $<

.c.o:
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS)

test:
	./$(TARGET)


.PHONY: clean all pcunit_register test
clean:
	rm -f *.o $(TARGET)

