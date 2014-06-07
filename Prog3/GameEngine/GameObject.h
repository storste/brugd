#pragma once
#include <string>
#include <iostream>

class GameObject {
public:

	GameObject() = default;
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

	std::string getName() const { return _name; }
	void setName(const char *name) { _name = name; }

	bool is_visible() const { return _visible; }
	void set_visible() { _visible = false; }

	bool is_collidable() const { return _collidable; }
	void toggle_collidable() { _collidable = !_collidable; }

protected:
	std::string _name;
	int _x, _y, _w, _h;
	bool _visible = true;
	bool _collidable = false;

private:

};
