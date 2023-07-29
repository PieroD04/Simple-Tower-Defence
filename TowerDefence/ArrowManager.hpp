#pragma once
#include <vector>
#include <memory>
#include "Arrow.hpp"

class ArrowManager
{
	std::vector<std::unique_ptr<Arrow> > turrets;
public:
	ArrowManager() {}
	~ArrowManager() {}

	size_t getSize() { return turrets.size(); }

	void insert(int x, int y, Direction direction)
	{
		switch (direction)
		{
		case Direction::None:
			throw "Invalid direction for bullet";
			break;
		case Direction::Right:
			turrets.push_back(std::make_unique<RightArrow>(x, y));
			break;
		case Direction::Left:
			turrets.push_back(std::make_unique <LeftArrow>(x, y));
			break;
		case Direction::Up:
			turrets.push_back(std::make_unique <UpArrow>(x, y));
			break;
		case Direction::Down:
			turrets.push_back(std::make_unique <DownArrow>(x, y));
			break;
		}
	}

	void eraseByVisibility()
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (turrets[i].get()->getVisibility() ) continue;
			else { turrets.erase(turrets.begin() + i); i--; }
		}
	}

	void eraseByPosition(int i)
	{
		turrets.erase(turrets.begin() + i);
	}

	void draw(System::Drawing::Bitmap^ arrowImage,System::Drawing::BufferedGraphics^ buffer)
	{
		for (int i = 0; i < getSize(); i++)
		{
			turrets[i].get()->draw(arrowImage, buffer);
		}

	}
};