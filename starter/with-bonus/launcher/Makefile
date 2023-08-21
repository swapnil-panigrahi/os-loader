#Compile the launch.c by linking it with the lib_simpleloader.so
vpath %.h starter/with-bonus/loader/loader.h

all : launch.out

launch.out : launch.c lib_simpleloader.so loader.h
	gcc -o launch.out launch.c lib_simpleloader.so -Wl, -rpath = ../loader



#Provide the command for cleanup
