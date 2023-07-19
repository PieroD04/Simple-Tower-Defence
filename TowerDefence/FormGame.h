#pragma once
#include "Game.hpp"
namespace TowerDefence {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormGame
	/// </summary>
	public ref class FormGame : public System::Windows::Forms::Form
	{
	private:
		Game* game = new Game();
	public:
		FormGame(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormGame()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormGame::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormGame::timer1_Tick);
			// 
			// FormGame
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1902, 1033);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormGame";
			this->Text = L"Tower Defence";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormGame::FormGame_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormGame::FormGame_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
		{
			//Graphics setup
			Graphics^ g = this->CreateGraphics();
			BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
			BufferedGraphics^ buffer = space->Allocate(g, this->ClientRectangle);

			//Game
			game->play(buffer);

			//Graphics render
			buffer->Render(g);

			//Deletion
			delete buffer;
			delete space;
			delete g;
		}

	private: System::Void FormGame_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		game->detectKeys(e->KeyCode);
	}

	private: System::Void FormGame_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		game->detectKeys(Keys::None);
	}
	};
}
