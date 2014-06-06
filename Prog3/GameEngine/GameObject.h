#pragma once
#include <string>

class GameObject {
public:
	//GameObject(){};
	virtual ~GameObject(){}
	virtual void render() = 0;
	virtual void update(int dt) = 0;

	int getY() const { return _y; }
	int getX() const { return _x; }
	int getW() const { return _w; }
	int getH() const { return _h; }


	void setPosition(int x, int y){ _x = x; _y = y; }

	std::string getName() const { return _name; }
	void setName(const char *name) { _name = name; }

	bool is_visible() const { return _visible; }
	void set_visible() { _visible = false; }

protected:
	std::string _name;
	int _x, _y, _w, _h;
	bool _visible;
};

