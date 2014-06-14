#include "StateMain.h"
#include <iostream>
#include "../../GameEngine/GameEngine.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/ScoreSprite.h"
#include "../GameObjects/Alien.h"
#include "../GameObjects/AlienController.h"
#include "../GameObjects/Missile.h"

StateMain::StateMain(int level)
{
	setLevel(level);
	std::cout << "StateMain: level: " << getLevel() << std::endl;

	m_world = GameEngine::getInstance();

	Animation* alien_animation = new Animation("assets/ufo2.png", 40, 30, 12, 12, 0);
	Animation* tank = new Animation("assets/tank3.png", 70, 52, 7, 7, 0);
	Animation* idle_tank = new Animation("assets/tank3.png", 70, 52, 1, 1, 58);
	Animation* alien_explosion = new Animation("assets/explosion3.png", 80, 80, 7, 5, 0);

	Image OrionImage("assets/bg3.jpg", true);
	Sprite* main_background = Sprite::getInstance(&OrionImage, "Main background");
	main_background->setPosition(0, 0);
	main_background->toggle_collidable();
	addGameObject(main_background);

	Player* player = Player::getInstance();
	player->addAnimation("run", tank);
	player->addAnimation("idle", idle_tank);
	player->setAnimation("run");
	player->setPosition(GameEngine::getInstance()->getScreenWidth() / 2, GameEngine::getInstance()->getScreenHeight() - 52);
	player->setName("Tank");

	AlienController* alienController = new AlienController();
	Alien* alienArray[60];

	for (int i = 0; i < 15; i++) {
		alienArray[i] = Alien::getInstance("Alien");
		alienArray[i]->setPosition(i * 40, 0);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 15] = Alien::getInstance("Alien");
		alienArray[i + 15]->setPosition(i * 40, 30);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 30] = Alien::getInstance("Alien");
		alienArray[i + 30]->setPosition(i * 40, 60);
	}
	for (int i = 0; i < 15; i++) {
		alienArray[i + 45] = Alien::getInstance("Alien");
		alienArray[i + 45]->setPosition(i * 40, 90);
	}

	for (auto& obj : alienArray) {
		obj->addAnimation("run", alien_animation);
		obj->addAnimation("explosion", alien_explosion);
		obj->setAnimation("run");
		addGameObject(obj);
	}

	addGameObject(alienController);
	addGameObject(player);

	ScoreSprite* scoreSprite = new ScoreSprite();
	addGameObject(scoreSprite);

	m_keymap[SDL_SCANCODE_SPACE] = std::bind(&Player::shoot, player);
	m_keymap[SDL_SCANCODE_RIGHT] = std::bind(&Player::moveRight, player);
	m_keymap[SDL_SCANCODE_LEFT] = std::bind(&Player::moveLeft, player);

	// här läcker det minne eftersom det nuvarande tillståndet inte tas bort...
	m_keymap[SDL_SCANCODE_ESCAPE] = std::bind([this](){
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_END"));
	});

	m_keymap[SDL_SCANCODE_P] = std::bind([this](){
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_PAUSE"));
	});
}

void StateMain::checkTransition(){

	if (m_world->getScore() == 100){
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_END"));
		deleteState = true;
	}
	else if (m_world->getScore() > 1 && (m_world->getScore() % 60) == 0){
		increaseLevel();
		m_world->addToScore(2);

		GameState *newState = new StateMain(getLevel());
		deleteState = true;

		m_world->getStateManager()->addGameState("STATE_MAIN", newState);
	}

	if (deleteState == true){
		std::cout << "Deleting current state" << std::endl;
		m_world->getStateManager()->setCurrentState(m_world->getStateManager()->getState("STATE_MAIN"));
		delete this;
	}

}
