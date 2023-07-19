#pragma once
#include "Player.hpp"
#include "ArrowManager.hpp"
class Game
{
	Player player;
	ArrowManager arrowsPlayer;
public:
	Game(){}
	~Game(){}



	void play(System::Drawing::BufferedGraphics^ buffer)
	{
		_drawAll(buffer);
		_erase();
	}

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
		case System::Windows::Forms::Keys::None:
			player.setDirection(Direction::None);
			break;
		}
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
	}

	void _erase()
	{
		arrowsPlayer.eraseByVisibility();
	}
};