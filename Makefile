all : 
	gcc `pkg-config --cflags gtk+-3.0` -g *.c ./utils/*.c -o gpp -w `pkg-config --libs gtk+-3.0`