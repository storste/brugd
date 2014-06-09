#include "..\..\GameEngine\GameEngine.h"

#include "GameStates\StateIntro.h"
#include "GameStates\StateMain.h"
#include "GameStates\StatePause.h"
#include "GameStates\StateEnd.h"

int main(int argc, char *argv[])
{

	GameEngine* engine = GameEngine::getInstance(800,600, 60);

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