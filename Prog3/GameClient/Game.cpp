#include "..\..\GameEngine\GameEngine.h"

#include <cstdlib>
#include <ctime>
//
//#include "GameObjects\Player.h"
//#include "GameObjects\Alien.h"
//#include "GameObjects\AlienController.h"
//#include "GameObjects\Missile.h"

#include "GameStates\StateIntro.h"
#include "GameStates\StateMain.h"
#include "GameStates\StatePause.h"
#include "GameStates\StateEnd.h"

// forward declarations
class Animation;
class Image;

int main(int argc, char *argv[])
{
	int seed = static_cast<int>(time(0));
	srand(seed);

	GameEngine* engine = GameEngine::getInstance();

	// set up game states
	GameState *introState = new StateIntro();
	engine->getStateManager()->addGameState("STATE_INTRO", introState);

	GameState *pauseState = new StatePause();
	engine->getStateManager()->addGameState("STATE_PAUSE", pauseState);

	GameState* mainState = new StateMain(0);
	engine->getStateManager()->addGameState("STATE_MAIN", mainState);


	GameState *endState = new StateEnd();
	engine->getStateManager()->addGameState("STATE_END", endState);

	engine->getStateManager()->setCurrentState(introState);

	// run game
	engine->run();

	return (0);
}