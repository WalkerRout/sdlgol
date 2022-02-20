OBJS = *.c include/*.c include/SDLExtensions/*.c
OBJ_NAME = bin/GameOfLife.exe
DEFAULT_SDL = -I  C:/Development/SDL2_MinGW_64Bit/include -L C:/Development/SDL2_MinGW_64Bit/lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2


all: comp run

comp: $(OBJS)
	gcc $(OBJS) $(DEFAULT_SDL) -o $(OBJ_NAME)

run: $(OBJ_NAME)
	./$(OBJ_NAME)

clean:
	clear
	rm ./$(OBJ_NAME)
	@echo "Removed $(OBJ_NAME)"
