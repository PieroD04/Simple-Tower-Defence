#pragma once
#include "Entity.hpp"

const int playerSpeedX = 10;
const int playerSpeedY = 8;
class Player : public Entity
{
    int indexX, indexY;
    bool hasShoot;
    Direction lastKeyPressed;
    Direction direction;
public:
    Player() :Entity(550, 500, 0, 0, 67, 58, true)
    {
        this->indexX = 0;
        this->indexY = 0;
        this->hasShoot = false;
        this->lastKeyPressed = Direction::Down;
        this->direction = Direction::None;
    }
    ~Player() {}

    void setDirection(Direction direction) { this->direction = direction; }
    Direction getDirection() { return this->direction; }
    Direction getLastKey() { return this->lastKeyPressed; }
    System::Drawing::Rectangle getHitbox() { return System::Drawing::Rectangle(x, y, width, height); }

    void move(System::Drawing::Bitmap^ character, System::Drawing::BufferedGraphics^ buffer)
    {
        switch (direction)
        {
        case Direction::Right: 
            lastKeyPressed = Direction::Right;
            dx = playerSpeedX; dy = indexY = 0;
            if (indexX >= 0 && indexX < 2) indexX++;
            else indexX = 0;
            break;
        case Direction::Left:
            lastKeyPressed = Direction::Left;
            dx = -playerSpeedX; dy = 0; indexY = 1;
            if (indexX >= 0 && indexX < 2) indexX++;
            else indexX = 0;
            break;
        case Direction::Up:
            lastKeyPressed = Direction::Up;
            dx = 0; dy = -playerSpeedY; indexY = 2;
            if (indexX >= 0 && indexX < 2) indexX++;
            else indexX = 0;
            break;
        case Direction::Down:
            lastKeyPressed = Direction::Down;
            dx = 0; dy = playerSpeedY; indexY = 3;
            if (indexX >= 0 && indexX < 2) indexX++;
            else indexX = 0;
            break;
        case Direction::None:
            indexX = dx = dy = 0;
            switch (lastKeyPressed)
            {
            case Direction::Right:
                indexY = 0;
                break;
            case Direction::Left:
                indexY = 1;
                break;
            case Direction::Up:
                indexY = 2;
                break;
            case Direction::Down:
                indexY = 3;
                break;
            }
            break;
        }
        draw(character, buffer);
    }

private:
    void draw(System::Drawing::Bitmap^ character, System::Drawing::BufferedGraphics^ buffer)
    {
        System::Drawing::Rectangle usableArea = System::Drawing::Rectangle(indexX * width, indexY * height, width, height);
        System::Drawing::Rectangle definition = System::Drawing::Rectangle(x, y, width, height);
        buffer->Graphics->DrawImage(character, definition, usableArea, System::Drawing::GraphicsUnit::Pixel);
        if (x + dx >= 0 && x + dx + width < buffer->Graphics->VisibleClipBounds.Width) x += dx;
        if (y + dy >= 0 && y + dy + height < buffer->Graphics->VisibleClipBounds.Height) y += dy;
    }

};