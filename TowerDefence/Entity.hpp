#pragma once

enum class Direction { None, Down, Up, Left, Right };

class Entity
{
protected:
	int x, y, dx, dy, width, height;
	bool visibility;
public:
	Entity(int x, int y, int dx, int dy, int width, int height, bool visibility) :
		x(x), y(y), dx(dx), dy(dy), width(width), height(height), visibility(visibility) {}

	~Entity() {}

	int getX() { return	x; }
	int getY() { return	y; }
	int getWidth() { return	width; }
	int getHeight() { return height; }
	bool getVisibility() { return visibility; }
};
