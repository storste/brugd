#pragma once
#include <string>
#include <iostream>

class GameObject {
public:

	virtual ~GameObject(){}

	virtual void render() = 0;
	virtual void update(int dt) = 0;
	virtual void doCollission() = 0;

	int getY() const;
	int getX() const;
	int getW() const;
	int getH() const;

	void setY(const int y);
	void setX(const int x);
	void setW(const int w);
	void setH(const int h);

	void setPosition(int x, int y);

	std::string getName() const;
	void setName(const std::string name);

	bool is_visible() const;
	void toggle_visible();

	bool is_collidable() const;
	void toggle_collidable();

protected:
	GameObject() = default;

private:
	std::string m_name;
	int m_xPos, m_yPos, m_width, m_height;
	bool m_visible = true;
	bool m_collidable = false;
};
