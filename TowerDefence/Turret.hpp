#pragma once
#include "Entity.hpp"

const int invertedShootSpeed = 10;

class Turret : public Entity
{
protected:
	int count;
	bool canShoot;
public:
	Turret(int x, int y, int dx, int dy, int width, int height, bool visibility) :
		Entity(x, y, dx, dy, width, height, visibility) {
		count = 0; canShoot = false;
	}
	~Turret() {}
	//Virtual functions
	virtual void draw(System::Drawing::Bitmap^ img, System::Drawing::BufferedGraphics^ buffer) = 0;
	virtual System::Drawing::Rectangle getHitbox() = 0;
	virtual Direction getDirection() = 0;
	//Getters
	int getX() { return this->x; }
	int getY() { return this->y; }
	bool getVisibility() { return this->visibility; }
	bool CanShoot() { return this->canShoot; }
	//Setters
	void setVisibility(bool visibility) { this->visibility = visibility; }
	void setAutomaticShoot()
	{
		if (count % invertedShootSpeed == 0) this->canShoot = true;
		else this->canShoot = false;

		this->count++;
	}
};

class RightTurret : public Turret
{
public:
	RightTurret(int x, int y) : Turret(x, y, 0, 0, 78, 100, true){}
	~RightTurret(){}

	void draw(System::Drawing::Bitmap^ turretImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 0;
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(turretImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}

	Direction getDirection() { return Direction::Right; }
};
class LeftTurret : public Turret
{
public:
	LeftTurret(int x, int y) : Turret(x, y, 0, 0, 78, 100, true) {}
	~LeftTurret() {}

	void draw(System::Drawing::Bitmap^ turretImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 1;

		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(turretImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}

	Direction getDirection() { return Direction::Left; }
};
class UpTurret: public Turret
{
public:
	UpTurret(int x, int y) : Turret(x, y, 0, 0, 78, 100, true) {}
	~UpTurret() {}

	void draw(System::Drawing::Bitmap^ turretImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 2;

		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(turretImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}

	Direction getDirection() { return Direction::Up; }
};
class DownTurret : public Turret
{
public:
	DownTurret(int x, int y) : Turret(x, y, 0, 0, 78, 100, true) {}
	~DownTurret() {}

	void draw(System::Drawing::Bitmap^ turretImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 3;

		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(turretImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}

	Direction getDirection() { return Direction::Down; }
};


