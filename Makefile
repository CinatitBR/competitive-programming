TARGET = main
SRC_FILES = $(wildcard *.c)
FLAGS = -Wall -I./include

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	gcc $(FLAGS) $(SRC_FILES) -o $(TARGET).out

clean:
	rm -f *.out

