#pragma once
#include <string>
#include "GameObject.h"

int GameObject::getY() const {
	return m_yPos;
}
int GameObject::getX() const {
	return m_xPos;
}

int GameObject::getW() const {
	return m_width;
}

int GameObject::getH() const {
	return m_height;
}

void GameObject::setY(const int y) {
	m_yPos = y;
}

void GameObject::setX(const int x) {
	m_xPos = x;
}

void GameObject::setW(const int w) {
	m_width = w;
}

void GameObject::setH(const int h) {
	m_height = h;
}

void GameObject::setPosition(int x, int y) {
	m_xPos = x; m_yPos = y;
}

std::string GameObject::getName() const {
	return m_name;
}

void GameObject::setName(const std::string name) {
	m_name = name;
}

bool GameObject::is_visible() const {
	return m_visible;
}

void GameObject::toggle_visible() {
	m_visible = !m_visible;
}

bool GameObject::is_collidable() const {
	return m_collidable;
}

void GameObject::toggle_collidable() {
	m_collidable = !m_collidable;
}

