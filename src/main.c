#include "../inc/game.h"

int main(int argc, char *argv[])
{

	game_t game;

	game_init(&game);
	game_run(&game);
	game_deinit(&game);

	return 0;
}

