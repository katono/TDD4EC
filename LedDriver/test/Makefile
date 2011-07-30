CC = gcc
CFLAGS = -Wall -Wextra -Wno-missing-field-initializers -std=c99 -pedantic-errors -g
CFLAGS += -I/usr/local/include
# CFLAGS += -DPCU_NO_LIBC
LFLAGS = -L/usr/local/lib -lpcunit
TARGET = alltests
OBJS = AllTests.o
OBJS += LedDriverTest.o

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

