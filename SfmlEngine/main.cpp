#include "Engine\Game.hpp"

#include "States\MainMenuState.h"
#include "States\IngameState.h"
#include "States\IngameMenuState.h"

int main()
{
	Game game("SFMLEngine Test Window", 1024, 768);
	game.enableAutoHandleClose(true);

	MainMenuState mainMenu;
	IngameState ingame;
	IngameMenuState ingameMenu;

	game.getStateManager().add(mainMenu, true);
	game.getStateManager().add(ingame);
	game.getStateManager().add(ingameMenu);

	game.start();

	return EXIT_SUCCESS;
}