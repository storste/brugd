#pragma once
#include "StateMain.h"
#include <iostream>


#include "..\GameObjects\Player.h"
#include "..\GameObjects\Alien.h"
#include "..\GameObjects\AlienController.h"
#include "..\GameObjects\Missile.h"

StateMain::StateMain(int level) :m_level(level)
{
	std::cout << "StateMain: level: " << m_level << std::endl;

	m_world = GameEngine::getInstance();

	Animation* alien_anim = new Animation("assets/ufo2.png", 40, 30, 12, 12, 0);
	Animation* tank = new Animation("assets/tank3.png", 70, 52, 7, 7, 0);
	Animation* idle_tank = new Animation("assets/tank3.png", 70, 52, 1, 1, 58);
	Animation* alienExp = new Animation("assets/explosion3.png", 80, 80, 7, 5, 0);

	Player* player = Player::getInstance();
	player->addAnimation("run", tank);
	player->addAnimation("idle", idle_tank);
	player->setAnimation("run");
	player->setPosition(GameEngine::getInstance()->getScreenWidth() / 2, GameEngine::getInstance()->getScreenHeight() - 52);
	player->setName("Tank");

	AlienController* ac = new AlienController();
	Alien* alienArray[60];

	for (int i = 0; i < 15; i++) {
		alienArray[i] = Alien::getInstance("Alien");
		alienArray[i]->addAnimation("run", alien_anim);
		alienArray[i]->addAnimation("explosion", alienExp);
		alienArray[i]->setAnimation("run");
		alienArray[i]->setPosition(i * 40, 0);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 15] = Alien::getInstance("Alien");
		alienArray[i + 15]->addAnimation("run", alien_anim);
		alienArray[i + 15]->addAnimation("explosion", alienExp);
		alienArray[i + 15]->setAnimation("run");
		alienArray[i + 15]->setPosition(i * 40, 30);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 30] = Alien::getInstance("Alien");
		alienArray[i + 30]->addAnimation("run", alien_anim);
		alienArray[i + 30]->addAnimation("explosion", alienExp);
		alienArray[i + 30]->setAnimation("run");
		alienArray[i + 30]->setPosition(i * 40, 60);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 45] = Alien::getInstance("Alien");
		alienArray[i + 45]->addAnimation("run", alien_anim);
		alienArray[i + 45]->addAnimation("explosion", alienExp);
		alienArray[i + 45]->setAnimation("run");
		alienArray[i + 45]->setPosition(i * 40, 90);
	}

	Image OrionImage("assets/bg3.jpg", true);
	Sprite* main_background = Sprite::getInstance(&OrionImage, "Intro background");
	main_background->setPosition(0, 0);
	main_background->toggle_collidable();
	addGameObject(main_background);

	for (int i = 0; i < 60; i++) {
		addGameObject(alienArray[i]);
	}

	addGameObject(ac);
	addGameObject(player);

	getKeyMap()[SDL_SCANCODE_SPACE] = std::bind(&Player::shoot, static_cast<Player*>(player));
	getKeyMap()[SDL_SCANCODE_RIGHT] = std::bind(&Player::moveRight, static_cast<Player*>(player));
	getKeyMap()[SDL_SCANCODE_LEFT] = std::bind(&Player::moveLeft, static_cast<Player*>(player));
	getKeyMap()[SDL_SCANCODE_ESCAPE] = std::bind([](){ GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_END"));	});
	getKeyMap()[SDL_SCANCODE_P] = std::bind([](){ GameEngine::getInstance()->getStateManager()->setCurrentState(GameEngine::getInstance()->getStateManager()->getState("STATE_PAUSE"));	});
}

StateMain::~StateMain()
{
	std::cout << "Main state destructor" << std::endl;

	for (std::list<GameObject*>::iterator itr = m_objects.begin(); itr != m_objects.end();)
	{
		delete (*itr);
		itr = m_objects.erase(itr);
	}
}

void StateMain::checkTransition(){

	if (m_world->score > 1 && (m_world->score % 4) == 0){
		std::cout << "Increasing score from " << m_world->score << " to " << m_world->score + 2 << " and level from " << m_level << " to " << m_level + 1 << std::endl;
		++m_level;
		m_world->score += 2;



		GameState *newState = new StateMain(m_level);
		//delete this;

		m_world->getStateManager()->addGameState("STATE_MAIN", newState);
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_MAIN"));

	}
}
