CC = gcc
CFLAGS = -Wall -Werror -Os
LIBS = -lncurses

OBJS = \
	tetris.o \
	game.o \
	screen.o \
	brick.o

OUTPUT = tetris

all:
	make build
	
build: $(OUTPUT)

$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJS) $(LIBS)


%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean:
	$(RM) $(OBJS) $(OUTPUT)
