
#ifndef WIN_H
#define WIN_H

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 680

#define WORLD_WIDTH (SCREEN_WIDTH - (SCREEN_WIDTH - SCREEN_HEIGHT))
#define WORLD_HEIGHT SCREEN_HEIGHT

#define CELL_ROWS 25
#define CELL_COLS 25

#define CELL_WIDTH (WORLD_WIDTH / CELL_COLS)
#define CELL_HEIGHT (WORLD_HEIGHT / CELL_ROWS)


typedef enum {
	DEAD = 0,
	ALIVE
} status_t;



typedef enum {
	RUNNING_STATE = 0, // 0
	RESET_STATE        // 1
} state_t;


typedef struct {
	status_t grid[CELL_ROWS][CELL_COLS];
	state_t state;
} world_t;



#endif
