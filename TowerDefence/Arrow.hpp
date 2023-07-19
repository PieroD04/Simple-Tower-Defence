#pragma once
#include "Entity.hpp"

class Arrow : public Entity
{
public:
	Arrow(int x, int y, int dx, int dy, int width, int height, bool visibility) :
		Entity(x, y, dx, dy, width, height, visibility) {}
	~Arrow() {}
	virtual void draw(System::Drawing::Bitmap^ img, System::Drawing::BufferedGraphics^ buffer) = 0;
	virtual System::Drawing::Rectangle getHitbox() = 0;
};

class RightArrow : public Arrow
{
public:
	RightArrow(int x, int y) : Arrow(x, y, 20, 0, 68, 60, true) {}
	~RightArrow() {}

	void draw(System::Drawing::Bitmap^ arrowImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 0;
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(arrowImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);

		if (x + dx >= 0 && x + dx + width < buffer->Graphics->VisibleClipBounds.Width) x += dx;
		else this->visibility = false;
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}
};

class LeftArrow : public Arrow
{
public:
	LeftArrow(int x, int y) : Arrow(x, y, -20, 0, 68, 60, true) {}
	~LeftArrow() {}

	void draw(System::Drawing::Bitmap^ arrowImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 1;
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(arrowImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);

		if (x + dx >= 0 && x + dx + width < buffer->Graphics->VisibleClipBounds.Width) x += dx;
		else this->visibility = false;
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}
};

class UpArrow : public Arrow
{
public:
	UpArrow(int x, int y) : Arrow(x, y, 0, -20, 68, 60, true) {}
	~UpArrow() {}

	void draw(System::Drawing::Bitmap^ arrowImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 2;
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);

		buffer->Graphics->DrawImage(arrowImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);

		if (y + dy >= 0 && y + dy + height < buffer->Graphics->VisibleClipBounds.Height) y += dy;
		else this->visibility = false;
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}
};

class DownArrow : public Arrow
{
public:
	DownArrow(int x, int y) : Arrow(x, y, 0, 20, 68, 60, true) {}
	~DownArrow() {}

	void draw(System::Drawing::Bitmap^ arrowImage, System::Drawing::BufferedGraphics^ buffer)
	{
		int indexX = 3;
		System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, 0, width, height);
		System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);
		buffer->Graphics->DrawImage(arrowImage, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);

		if (y + dy >= 0 && y + dy + height < buffer->Graphics->VisibleClipBounds.Height) y += dy;
		else this->visibility = false;
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, width, height);
	}
};