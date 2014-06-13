
#include "StateManager.h"

StateManager::StateManager() {}

StateManager::~StateManager() {

  delete m_currentState;
  std::cout << "StateManager: Destructor" << std::endl;
}

void StateManager::addGameState(const std::string stateID, GameState *state) {
  m_gameStates[stateID] = state;
}

void StateManager::setCurrentState(GameState *state) { m_currentState = state; }

GameState *StateManager::getCurrentState() { return m_currentState; }

GameState *StateManager::getState(const std::string stateID) {
  return m_gameStates[stateID];
}