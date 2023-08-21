#Compile the launch.c by linking it with the lib_simpleloader.so
IDIR =starter/with-bonus/loader/
_DEPS = loader.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all : launch

launch : launch.o lib_simpleloader
	gcc -o launch launch.o -L/starter/with-bonus/loader -llib_simpleloader

launch.o: launch.c $(_DEPS)
	gcc -o launch.o launch.c

#Provide the command for cleanup
