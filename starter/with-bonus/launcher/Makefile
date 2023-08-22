#Compile the launch.c by linking it with the lib_simpleloader.so
# Makefile for compiling launch.c using lib_simpleloader.so

# Compiler settings
CC := gcc
CFLAGS := -Wall -Wextra -I../loader
LDFLAGS := -L../loader -Wl,-rpath=../loader
LDLIBS := ../loader/lib_simpleloader.so

# Source and output files
SRC := launch.c
OUT := launch

# Build rule
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -m32 -o $@ $< $(LDLIBS)

clean:
	rm -f $(OUT)

.PHONY: all clean

#Provide the command for cleanup
