# simple Makefile
# Nooreldean Koteb G01085380
# CS262, lab section 209
# Lab7

CC= gcc
CFLAGS=-g -Wall -pedantic-errors
TARGET= ShuffleArray

all:$(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)
