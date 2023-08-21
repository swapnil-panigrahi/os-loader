#Create lib_simpleloader.so from loader.c
all : lib_simpleloader.so

lib_simpleloader.so : loader.c loader.h
	gcc -shared -o lib_simpleloader.so -fPIC loader.c
#Provide the command for cleanup
clean:
	rm loader.o lib_simpleloader.so