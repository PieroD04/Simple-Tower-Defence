#pragma once
#include "Entity.hpp"

const int enemySpeedX = 10;
const int enemySpeedY = 8;

class Enemy : public Entity
{
protected:
	int indexX, indexY;
	Direction direction;
	int health;
public:
	Enemy(int x, int y, int dx, int dy, int width, int height, bool visibility):
		Entity(x, y, dx, dy, width, height, visibility){}
	~Enemy(){}

	void setDirection(Direction direction) { this->direction = direction; }
	Direction getDirection() { return this->direction; }

	virtual void move(System::Drawing::Bitmap^ img, System::Drawing::BufferedGraphics^ buffer) = 0;
	virtual void draw(System::Drawing::Bitmap^ img, System::Drawing::BufferedGraphics^ buffer) = 0;
	virtual System::Drawing::Rectangle getHitbox() = 0;
};

class Archer : public Enemy
{
	bool triggered;
public:
	Archer() : Enemy(10, 10, 10, 0, 67, 58, true)
	{
		health = 1;
		direction = Direction::Right;
		indexX = indexY = 0;
		triggered = false;
	}
	~Archer(){}
	void setTriggered(bool triggered) { this->triggered = triggered; }
	void move(System::Drawing::Bitmap^ archerImage, System::Drawing::BufferedGraphics^ buffer)
	{
		switch (direction)
		{
		case Direction::Right:
			indexY = 0;
			dx = enemySpeedX;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		case Direction::Left:
			indexY = 1;
			dx = -enemySpeedX;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		case Direction::Down:
			indexY = 3;
			dx = 0;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		default:
			throw "Invalid direction";
		}
		draw(archerImage, buffer);
	}
	void draw(System::Drawing::Bitmap^ archerImage, System::Drawing::BufferedGraphics^ buffer)
	{
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, indexY * height, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);
		buffer->Graphics->DrawImage(archerImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
		x += dx;
		if (x + dx + width >= buffer->Graphics->VisibleClipBounds.Width - 200) direction = Direction::Left;
		if (x + dx < 0) direction = Direction::Right;
	}
	System::Drawing::Rectangle getHitbox() { return System::Drawing::Rectangle(x, y, width, height); }
};

class Warrior : public Enemy
{
public:
	Warrior() : Enemy(80, 300, 10, 0, 77, 58, true)
	{
		health = 3;
		direction = Direction::Right;
		indexX = indexY = 0;
	}
	~Warrior() {}

	void setDirection(Direction direction) { this->direction = direction; }
	void move(System::Drawing::Bitmap^ warriorImage, System::Drawing::BufferedGraphics^ buffer)
	{
		switch (direction)
		{
		case Direction::Right:
			indexY = 0;
			dx = enemySpeedX;
			dy = 0;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		case Direction::Left:
			indexY = 1;
			dx = -enemySpeedX;
			dy = 0;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		case Direction::Up:
			indexY = 2;
			dx = 0;
			dy = -enemySpeedY;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		case Direction::Down:
			indexY = 3;
			dx = 0;
			dy = -enemySpeedY;
			if (indexX >= 0 && indexX < 2) indexX++;
			else indexX = 0;
			break;
		default:
			throw "Invalid direction";
		}
		draw(warriorImage, buffer);
	}
	void draw(System::Drawing::Bitmap^ warriorImage, System::Drawing::BufferedGraphics^ buffer)
	{
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, indexY * height, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);
		buffer->Graphics->DrawImage(warriorImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
		x += dx; y += dy;
	}

	System::Drawing::Rectangle getHitbox() { return System::Drawing::Rectangle(x, y, width, height); }
};