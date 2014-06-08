#pragma once
#include <string>
#include <iostream>

class GameObject {
public:

	virtual ~GameObject() = default;

	virtual void render() = 0;
	virtual void update(int dt) = 0;
	virtual void doCollission() = 0;

	int getY() const { return _y; }
	int getX() const { return _x; }
	int getW() const { return _w; }
	int getH() const { return _h; }

	void setPosition(int x, int y) {
		_x = x; _y = y;
	}

	std::string getName() const { return m_name; }
	void setName(std::string name) { m_name = name; }

	bool is_visible() const { return m_visible; }
	void set_visible() { m_visible = false; }

	bool is_collidable() const { return m_collidable; }
	void toggle_collidable() { m_collidable = !m_collidable; }

protected:
	GameObject() = default;
	std::string m_name;
	int _x, _y, _w, _h;
	bool m_visible = true;
	bool m_collidable = false;

};
