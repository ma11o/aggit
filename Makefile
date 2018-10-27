CFLAGS=-g -O3 -Wall

CC=gcc
AR=ar

aggit: aggit.o
	$(CC) $(CFLAGS) -o aggit aggit.o