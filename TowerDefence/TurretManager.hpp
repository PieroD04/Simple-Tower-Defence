#pragma once
#include <vector>
#include <memory>
#include "Turret.hpp"

class TurretManager
{
	std::vector<std::unique_ptr<Turret> > turrets;
public:
	TurretManager() {}
	~TurretManager() {}

	//Getters
	size_t getSize() { return turrets.size(); }
	int getX(int i) { return turrets.at(i)->getX(); }
	int getY(int i){ return turrets.at(i)->getY(); }
	Direction getDirection(int i) { return turrets.at(i)->getDirection(); }
	bool canTurretShoot(int i) { turrets.at(i)->setAutomaticShoot(); return turrets.at(i)->CanShoot(); }

	//Main functionality
	void insert(int x, int y, Direction direction)
	{
		switch (direction)
		{
		case Direction::None:
			throw "Invalid direction for bullet";
			break;
		case Direction::Right:
			turrets.push_back(std::make_unique<RightTurret>(x, y));
			break;
		case Direction::Left:
			turrets.push_back(std::make_unique <LeftTurret>(x, y));
			break;
		case Direction::Up:
			turrets.push_back(std::make_unique <UpTurret>(x, y));
			break;
		case Direction::Down:
			turrets.push_back(std::make_unique <DownTurret>(x, y));
			break;
		}
	}

	void eraseByVisibility()
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (turrets[i].get()->getVisibility()) continue;
			else { turrets.erase(turrets.begin() + i); i--; }
		}
	}

	void eraseByPosition(int i)
	{
		turrets.erase(turrets.begin() + i);
	}

	void draw(System::Drawing::Bitmap^ turretImage, System::Drawing::BufferedGraphics^ buffer)
	{
		for (int i = 0; i < getSize(); i++)
		{
			turrets[i].get()->draw(turretImage, buffer);
		}

	}
};