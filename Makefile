CFLAGS=-std=c11 -g -Wall -Wextra -pedantic

all: demo libqueue.so

demo: main.o priority-queue.o
	$(CC) $^ -o$@

libqueue.so: priority-queue.o
	$(CC) $< -o$@ -shared -fPIC

clean:
	$(RM) *.o