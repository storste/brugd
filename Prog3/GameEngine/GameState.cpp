#include "GameState.h"

GameState::GameState()  {
	//std::cout << "GameState: Constructor" << std::endl;
}

GameState::~GameState()
{
	for (std::list<GameObject*>::iterator itr = m_objects.begin(); itr != m_objects.end();)
	{
		std::cout << "Deleting " << (*itr)->getName() << std::endl;
		delete (*itr);
		itr = m_objects.erase(itr);
	}
}

void GameState::update(int ticks)
{
	// ta bort objekt som är flaggade för bortstädning
	for (std::list<GameObject*>::iterator itr = m_objects.begin(); itr != m_objects.end();)
	{
		if ((*itr)->is_visible() == false){
			delete (*itr);
			itr = m_objects.erase(itr);
		}
		else{
			++itr;
		}
	}

	for (const auto& o : m_objects){
		o->update(ticks);
	}
}

void GameState::checkTransition(){}

void GameState::addGameObject(GameObject* d){
	m_objects.push_back(d);
}

void GameState::removeGameObject(GameObject* d){
	d->toggle_visible();
}

std::list<GameObject*> GameState::getObjects(){
	return m_objects;
};

// hur ska funktionen se ut egentligen?????
//void addKeyFunction(SDL_Scancode key, std::function<void()> func, GameObject* obj){
//	//std::pair<SDL_Scancode, void (GameObject::*)()> pair = std::make_pair(SDL_SCANCODE_SPACE, func);
//	m_keymap[key] = std::bind(&func, &obj);
//	//m_keymap.insert(pair);
//}

void GameState::invokeFuncForKey(SDL_Scancode key){
	m_keymap[key]();
}

std::map<SDL_Scancode, std::function<void()>>& GameState::getKeyMap(){
	return m_keymap;
}

int GameState::getLevel(){
	return m_level;
}

void GameState::increaseLevel(){
	++m_level;
}

void GameState::setLevel(int newLevel){
	m_level = newLevel;
}