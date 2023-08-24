#Compile the launch.c by linking it with the lib_simpleloader.so
# Makefile for compiling launch.c using lib_simpleloader.so
all: launch

launch: launch.c
	gcc -I../loader -L../loader -Wl,-rpath=../loader -m32 -o $@ $< ../bin/lib_simpleloader.so

#Provide the command for cleanup

clean:
	rm -f launch