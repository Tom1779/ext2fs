SOURCES=main.c commands.c tree.c
TARGET=main

all: $(TARGET)

$(TARGET): $(SOURCES)
	gcc -o $@ $^ -m32

clean:
	rm -f $(TARGET)
