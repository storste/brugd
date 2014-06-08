#pragma once
#include "StateMain.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"

StateMain::StateMain(int level)
{
	std::cout << "StateMain: level: " << getLevel() << std::endl;
	m_world = GameEngine::getInstance();
}

StateMain::~StateMain()
{
	//std::cout << "Main state destructor" << std::endl;
}

void StateMain::checkTransition(){

	if (m_world->score == 40){
		++m_level;
		++m_world->score;

		GameState *mainState = new StateMain(m_level);

		mainState->getKeyMap() = this->m_keymap;

		for (auto& o : getObjects()){
			mainState->addGameObject(o);
		}

		m_world->getStateManager()->addGameState("STATE_MAIN_" + m_level, mainState);
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_MAIN_" + m_level));
	}

	if (m_world->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_PAUSE"));
	}

	if (m_world->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_END"));
	}
}
