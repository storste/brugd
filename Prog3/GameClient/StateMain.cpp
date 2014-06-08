#pragma once
#include "StateMain.h"
#include <iostream>
#include "..\GameEngine\GameEngine.h"
#include "Alien.h"

StateMain::StateMain()
{	
	//std::cout << "Main state Constructor" << std::endl;
	m_world = GameEngine::getInstance();
}

StateMain::~StateMain()
{
	//std::cout << "Main state destructor" << std::endl;
}

void StateMain::checkTransition(){

	if (m_world->getInputHandler()->isKeyDown(SDL_SCANCODE_P))
	{
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_PAUSE"));
	}

	if (m_world->getInputHandler()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_END"));
	}
}


	//for (std::list<GameObject*>::iterator itr = m_objects.begin(); itr != m_objects.end();)
	//{
	//	if ((*itr)->is_visible() == false){
//		//std::cout << (*itr)->getName() << " is not visible" << std::endl;
	//		delete (*itr);
	//		itr = m_objects.erase(itr);
	//	}
	//	else{
	//		++itr;
	//	}
	//}

	//if ((_world->score > 0 && _world->score % 5 == 0) || m_objects.size() < 4){
	//	Image* alien_image = new Image("assets/alien.jpg", true);
	//	Sprite* alien = new Alien(alien_image, "Alien");
	//	alien->setPosition(3, 5);
	//	addGameObject(alien);
	//}

	//for (auto& o : m_objects){
	//	o->update(dt);
	//}
//}
