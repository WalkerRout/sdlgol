OBJS = *.c include/*.c include/SDLExtensions/*.c
OBJ_NAME = bin/GameOfLife.exe
DEFAULT_SDL_MAC = -I  usr/local/Cellar/sdl2/2.0.20/include -L /usr/local/Cellar/sdl/2.0.20/lib -w -lSDL2main -lSDL2
#DEFAULT_SDL_WIN = -I C:/Development/SDL2_MinGW_64Bit/include -L C:/Development/SDL2_MinGW_64Bit/lib -w -Wl,-subsystem,windows -lmingw64 -lSDL2main -lSDL2

all: comp run

comp: $(OBJS)
	gcc $(OBJS) $(DEFAULT_SDL_MAC) -o $(OBJ_NAME)

run: $(OBJ_NAME)
	./$(OBJ_NAME)

clean:
	clear
	rm ./$(OBJ_NAME)
	@echo "Removed $(OBJ_NAME)"
