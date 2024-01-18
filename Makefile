TARGET = main
SRC_FILES = $(wildcard *.c)
FLAGS = -Wall -I./include

all: $(TARGET)
	./main.out

self: main.c
	gcc -Wall main.c -o main.out
	./main.out

$(TARGET): $(SRC_FILES)
	gcc $(FLAGS) $(SRC_FILES) -o $(TARGET).out

clean:
	rm -f *.out

