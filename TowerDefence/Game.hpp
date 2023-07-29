#pragma once
#include "Player.hpp"
#include "ArrowManager.hpp"
#include "TurretManager.hpp"
#include "Enemy.hpp"

const float turretSpeed = 0.5;

class Game
{
	Player player;
	ArrowManager arrowsPlayer;
	ArrowManager arrowsTurrets;
	TurretManager turrets;
	Archer test;
	Warrior test2;
public:
	Game(){}
	~Game(){}

	void detectKeys(System::Windows::Forms::Keys keys)
	{
		switch (keys)
		{
		case System::Windows::Forms::Keys::Down:
			player.setDirection(Direction::Down);
			break;
		case System::Windows::Forms::Keys::Up:
			player.setDirection(Direction::Up);
			break;
		case System::Windows::Forms::Keys::Left:
			player.setDirection(Direction::Left);
			break;
		case System::Windows::Forms::Keys::Right:
			player.setDirection(Direction::Right);
			break;
		case System::Windows::Forms::Keys::Space:
			arrowsPlayer.insert(player.getX(), player.getY(), player.getLastKey());
			break;
		case System::Windows::Forms::Keys::T:
			turrets.insert(player.getX(), player.getY(), player.getLastKey());
			break;
		case System::Windows::Forms::Keys::None:
			player.setDirection(Direction::None);
			break;
		}
	}
	void play(System::Drawing::BufferedGraphics^ buffer)
	{
		
		
		_drawAll(buffer);

		_erase();
	}

private:
	void _drawAll(System::Drawing::BufferedGraphics^ buffer)
	{
		//Drawing background
		System::Drawing::Bitmap^ background = gcnew System::Drawing::Bitmap("../Content/background.png");
		System::Drawing::Rectangle area = System::Drawing::Rectangle(0, 0, buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);
		buffer->Graphics->DrawImage(background, area);

		//Drawing player
		System::Drawing::Bitmap^ character = gcnew System::Drawing::Bitmap("../Content/character.png");
		player.move(character, buffer);

		//Drawing arrows
		System::Drawing::Bitmap^ arrowImage = gcnew System::Drawing::Bitmap("../Content/arrows.png");
		arrowsPlayer.draw(arrowImage, buffer);
		_turretsShot();
		arrowsTurrets.draw(arrowImage, buffer);

		//Drawing turrets
		System::Drawing::Bitmap^ turretImage = gcnew System::Drawing::Bitmap("../Content/turrets.png");
		turrets.draw(turretImage, buffer);

		//Drawing enemies
		System::Drawing::Bitmap^ archerImage = gcnew System::Drawing::Bitmap("../Content/archer.png");
		test.move(archerImage, buffer);
		System::Drawing::Bitmap^ warriorImage = gcnew System::Drawing::Bitmap("../Content/warrior.png");
		test2.move(warriorImage, buffer);
	}
	void _erase()
	{
		arrowsPlayer.eraseByVisibility();
		arrowsTurrets.eraseByVisibility();
		turrets.eraseByVisibility();

	}

	void _turretsShot()
	{
		for (int i = 0; i < turrets.getSize(); i++)
		{
			if( turrets.canTurretShoot(i) ) arrowsTurrets.insert(turrets.getX(i), turrets.getY(i), turrets.getDirection(i) );
		}
	}
};