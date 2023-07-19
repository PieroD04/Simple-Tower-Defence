#pragma once
#include <vector>
#include <memory>
#include "Arrow.hpp"

class ArrowManager
{
	std::vector<std::unique_ptr<Arrow> > arrows;
public:
	ArrowManager() {}
	~ArrowManager() {}

	size_t getSize() { return arrows.size(); }

	void insert(int x, int y, Direction direction)
	{
		switch (direction)
		{
		case Direction::None:
			throw "Invalid direction for bullet";
			break;
		case Direction::Right:
			arrows.push_back(std::make_unique<RightArrow>(x, y));
			break;
		case Direction::Left:
			arrows.push_back(std::make_unique <LeftArrow>(x, y));
			break;
		case Direction::Up:
			arrows.push_back(std::make_unique <UpArrow>(x, y));
			break;
		case Direction::Down:
			arrows.push_back(std::make_unique <DownArrow>(x, y));
			break;
		}
	}

	void eraseByVisibility()
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (arrows[i].get()->getVisibility() ) continue;
			else { arrows.erase(arrows.begin() + i); i--; }
		}
	}

	void eraseByPosition(int i)
	{
		arrows.erase(arrows.begin() + i);
	}

	void draw(System::Drawing::Bitmap^ arrowImage,System::Drawing::BufferedGraphics^ buffer)
	{
		for (int i = 0; i < getSize(); i++)
		{
			arrows[i].get()->draw(arrowImage, buffer);
		}

	}
};