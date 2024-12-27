CC = gcc
CFLAGS = -Wall -g -O0 -I .  # Add -I to specify the include directory

OBJ = stack.o test_stack.o
TARGET = test_stack

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

test_stack.o: test_stack.c stack.h
	$(CC) $(CFLAGS) -c test_stack.c

clean:
	rm -f $(OBJ) $(TARGET)

