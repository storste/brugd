#pragma once
#include <string>
#include <iostream>

class GameObject {
public:

	virtual ~GameObject() = default;

	virtual void render() = 0;
	virtual void update(int dt) = 0;
	virtual void doCollission() = 0;

	int getY() const { return m_yPos; }
	int getX() const { return m_xPos; }
	int getW() const { return m_width; }
	int getH() const { return m_height; }

	void setY(const int y) { m_yPos = y; }
	void setX(const int x) { m_xPos = x; }
	void setW(const int w) { m_width = w; }
	void setH(const int h) { m_height = h; }

	void setPosition(int x, int y) {
		m_xPos = x; m_yPos = y;
	}

	std::string getName() const { return m_name; }
	void setName(const std::string name) { m_name = name; }

	bool is_visible() const { return m_visible; }
	void toggle_visible() { m_visible = !m_visible; }

	bool is_collidable() const { return m_collidable; }
	void toggle_collidable() { m_collidable = !m_collidable; }

protected:
	GameObject() = default;

private:
	std::string m_name;
	int m_xPos, m_yPos, m_width, m_height;
	bool m_visible = true;
	bool m_collidable = false;
};
