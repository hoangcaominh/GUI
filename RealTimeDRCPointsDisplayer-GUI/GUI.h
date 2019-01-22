#pragma once

#include "ProcessJSON.h"
#include "ProcessMemory.h"

DWORD procStatus;
bool foundGame = false;
static int i;

namespace RealTimeDRCPointsDisplayerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:

		GUI(void)
		{
			InitializeComponent();
			Update();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  update;
	private: System::Windows::Forms::ListBox^  infoBox;

	protected:

	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::Button^  detectGame;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  bombsLabel;
	private: System::Windows::Forms::Label^  missesLabel;
	private: System::Windows::Forms::Label^  shottypeLabel;
	private: System::Windows::Forms::Label^  diffLabel;
	private: System::Windows::Forms::Label^  gameLabel;
	private: System::Windows::Forms::Label^  scoringLabel;
	private: System::Windows::Forms::Label^  survivalLabel;
	private: System::Windows::Forms::Button^  settings;
	private: System::Windows::Forms::Button^  about;
	private: System::ComponentModel::BackgroundWorker^  bkgProc;
	private: System::Windows::Forms::Label^  scoreLabel;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->update = (gcnew System::Windows::Forms::Button());
			this->infoBox = (gcnew System::Windows::Forms::ListBox());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->detectGame = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->scoringLabel = (gcnew System::Windows::Forms::Label());
			this->survivalLabel = (gcnew System::Windows::Forms::Label());
			this->bombsLabel = (gcnew System::Windows::Forms::Label());
			this->missesLabel = (gcnew System::Windows::Forms::Label());
			this->shottypeLabel = (gcnew System::Windows::Forms::Label());
			this->diffLabel = (gcnew System::Windows::Forms::Label());
			this->gameLabel = (gcnew System::Windows::Forms::Label());
			this->settings = (gcnew System::Windows::Forms::Button());
			this->about = (gcnew System::Windows::Forms::Button());
			this->bkgProc = (gcnew System::ComponentModel::BackgroundWorker());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// update
			// 
			this->update->Location = System::Drawing::Point(12, 256);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(130, 23);
			this->update->TabIndex = 1;
			this->update->Text = L"Update Files";
			this->update->UseVisualStyleBackColor = true;
			this->update->Click += gcnew System::EventHandler(this, &GUI::update_Click);
			// 
			// infoBox
			// 
			this->infoBox->FormattingEnabled = true;
			this->infoBox->Location = System::Drawing::Point(12, 12);
			this->infoBox->Name = L"infoBox";
			this->infoBox->Size = System::Drawing::Size(266, 238);
			this->infoBox->TabIndex = 0;
			this->infoBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::listBox1_SelectedIndexChanged);
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(12, 285);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(130, 23);
			this->clear->TabIndex = 2;
			this->clear->Text = L"Clear History";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &GUI::clearHistory_Click);
			// 
			// detectGame
			// 
			this->detectGame->Location = System::Drawing::Point(12, 314);
			this->detectGame->Name = L"detectGame";
			this->detectGame->Size = System::Drawing::Size(266, 23);
			this->detectGame->TabIndex = 3;
			this->detectGame->Text = L"Find Game";
			this->detectGame->UseVisualStyleBackColor = true;
			this->detectGame->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->scoreLabel);
			this->panel1->Controls->Add(this->scoringLabel);
			this->panel1->Controls->Add(this->survivalLabel);
			this->panel1->Controls->Add(this->bombsLabel);
			this->panel1->Controls->Add(this->missesLabel);
			this->panel1->Controls->Add(this->shottypeLabel);
			this->panel1->Controls->Add(this->diffLabel);
			this->panel1->Controls->Add(this->gameLabel);
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel1->Location = System::Drawing::Point(284, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(362, 325);
			this->panel1->TabIndex = 5;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GUI::panel1_Paint);
			// 
			// scoringLabel
			// 
			this->scoringLabel->BackColor = System::Drawing::Color::Transparent;
			this->scoringLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->scoringLabel->ForeColor = System::Drawing::Color::White;
			this->scoringLabel->Location = System::Drawing::Point(0, 216);
			this->scoringLabel->Name = L"scoringLabel";
			this->scoringLabel->Size = System::Drawing::Size(340, 54);
			this->scoringLabel->TabIndex = 6;
			this->scoringLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// survivalLabel
			// 
			this->survivalLabel->BackColor = System::Drawing::Color::Transparent;
			this->survivalLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->survivalLabel->ForeColor = System::Drawing::Color::White;
			this->survivalLabel->Location = System::Drawing::Point(0, 162);
			this->survivalLabel->Name = L"survivalLabel";
			this->survivalLabel->Size = System::Drawing::Size(340, 54);
			this->survivalLabel->TabIndex = 5;
			this->survivalLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bombsLabel
			// 
			this->bombsLabel->BackColor = System::Drawing::Color::Transparent;
			this->bombsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->bombsLabel->ForeColor = System::Drawing::Color::Lime;
			this->bombsLabel->Location = System::Drawing::Point(193, 54);
			this->bombsLabel->Name = L"bombsLabel";
			this->bombsLabel->Size = System::Drawing::Size(169, 54);
			this->bombsLabel->TabIndex = 3;
			this->bombsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// missesLabel
			// 
			this->missesLabel->BackColor = System::Drawing::Color::Transparent;
			this->missesLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->missesLabel->ForeColor = System::Drawing::Color::Red;
			this->missesLabel->Location = System::Drawing::Point(193, 0);
			this->missesLabel->Name = L"missesLabel";
			this->missesLabel->Size = System::Drawing::Size(169, 54);
			this->missesLabel->TabIndex = 2;
			this->missesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// shottypeLabel
			// 
			this->shottypeLabel->BackColor = System::Drawing::Color::Transparent;
			this->shottypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->shottypeLabel->ForeColor = System::Drawing::Color::White;
			this->shottypeLabel->Location = System::Drawing::Point(0, 108);
			this->shottypeLabel->Name = L"shottypeLabel";
			this->shottypeLabel->Size = System::Drawing::Size(340, 54);
			this->shottypeLabel->TabIndex = 4;
			this->shottypeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// diffLabel
			// 
			this->diffLabel->BackColor = System::Drawing::Color::Transparent;
			this->diffLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->diffLabel->ForeColor = System::Drawing::Color::White;
			this->diffLabel->Location = System::Drawing::Point(0, 54);
			this->diffLabel->Name = L"diffLabel";
			this->diffLabel->Size = System::Drawing::Size(196, 54);
			this->diffLabel->TabIndex = 1;
			this->diffLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// gameLabel
			// 
			this->gameLabel->BackColor = System::Drawing::Color::Transparent;
			this->gameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->gameLabel->ForeColor = System::Drawing::Color::Red;
			this->gameLabel->Location = System::Drawing::Point(0, 0);
			this->gameLabel->Name = L"gameLabel";
			this->gameLabel->Size = System::Drawing::Size(196, 54);
			this->gameLabel->TabIndex = 0;
			this->gameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// settings
			// 
			this->settings->Location = System::Drawing::Point(148, 256);
			this->settings->Name = L"settings";
			this->settings->Size = System::Drawing::Size(130, 23);
			this->settings->TabIndex = 4;
			this->settings->Text = L"Settings";
			this->settings->UseVisualStyleBackColor = true;
			// 
			// about
			// 
			this->about->Location = System::Drawing::Point(148, 285);
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(130, 23);
			this->about->TabIndex = 5;
			this->about->Text = L"About";
			this->about->UseVisualStyleBackColor = true;
			// 
			// bkgProc
			// 
			this->bkgProc->WorkerReportsProgress = true;
			this->bkgProc->WorkerSupportsCancellation = true;
			this->bkgProc->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &GUI::bkgProc_DoWork);
			this->bkgProc->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &GUI::bkgProc_RunWorkerCompleted);
			// 
			// scoreLabel
			// 
			this->scoreLabel->BackColor = System::Drawing::Color::Transparent;
			this->scoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->scoreLabel->ForeColor = System::Drawing::Color::White;
			this->scoreLabel->Location = System::Drawing::Point(3, 251);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(340, 54);
			this->scoreLabel->TabIndex = 7;
			this->scoreLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(649, 349);
			this->Controls->Add(this->about);
			this->Controls->Add(this->settings);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->detectGame);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->infoBox);
			this->Controls->Add(this->update);
			this->Name = L"GUI";
			this->Text = L"RealTimeDRCPointsDisplayer";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		void Update()
		{
			SYSTEMTIME sysTime;
			GetLocalTime(&sysTime);

			this->infoBox->Items->Add("[" + sysTime.wHour + ":" + sysTime.wMinute + ":" + sysTime.wSecond + "]");

			this->infoBox->Items->Add("Downloading rubric file...");
			BOOL fail = Download_rubrics();
			if (!fail)
			{
				this->infoBox->Items->Add("Successfully downloaded rubric file.");
			}
			else
			{
				this->infoBox->Items->Add("Failed to download rubric file. ID returned: " + fail);
			}

			this->infoBox->Items->Add("Downloading world record file...");
			fail = Download_wrs();
			if (!fail)
			{
				this->infoBox->Items->Add("Successfully downloaded world record file.");
			}
			else
			{
				this->infoBox->Items->Add("Failed to download world record file. ID returned: " + fail);
			}

			this->infoBox->Items->Add("Parsing rubric file...");
			fail = Load_rubrics();
			if (!fail)
			{
				this->infoBox->Items->Add("Successfully parsed rubric file.");
			}
			else
			{
				this->infoBox->Items->Add("Failed to parse rubric file.");
			}

			this->infoBox->Items->Add("Parsing world record file...");
			fail = Load_wrs();
			if (!fail)
			{
				this->infoBox->Items->Add("Successfully parsed world record file.");
			}
			else
			{
				this->infoBox->Items->Add("Failed to parse world record file.");
			}

			infoBox->SelectedIndex = infoBox->Items->Count - 1;
		}

		// convert to String from const char*
		String^ convertToStringClass(const char* &str)
		{
			String^ newString = gcnew String(str);
			return newString;
		}

		// convert to String from std::string
		String^ convertToStringClass(std::string &str)
		{
			String^ newString = gcnew String(str.c_str());
			return newString;
		}

#pragma endregion
	private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void update_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Update();
	}

	private: System::Void clearHistory_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->infoBox->Items->Clear();
	}

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{

	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SYSTEMTIME sysTime;
		GetLocalTime(&sysTime);

		this->infoBox->Items->Add("[" + sysTime.wHour + ":" + sysTime.wMinute + ":" + sysTime.wSecond + "]");

		BOOL fail = GetProcess();
		if (!fail)
		{
			this->infoBox->Items->Add("Found " + convertToStringClass(idx_game[game]));
			this->gameLabel->Text = (L"Game: " + convertToStringClass(idx_game[game]));

			this->panel1->BackColor = System::Drawing::Color::Black;
			this->gameLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->diffLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shottypeLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->missesLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bombsLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scoreLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->survivalLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scoringLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

			if (GetExitCodeProcess(gameProc, &procStatus))
			{
				if (procStatus == STILL_ACTIVE)
				{
					//   && 
					while (!bkgProc->CancellationPending)
					{

						ReadMemory();
						this->diffLabel->Text = (L"Difficulty: " + convertToStringClass(idx_difficulty[difficulty]));
						this->shottypeLabel->Text = (L"Shottype: " + convertToStringClass(shottype));
						this->missesLabel->Text = (L"Misses: " + misses);
						this->bombsLabel->Text = (L"Bombs: " + bombs);
						this->scoreLabel->Text = (L"Score: " + score);
						this->survivalLabel->Text = (L"Survival Points: " + roundf(drcpoints_survival));
						this->scoringLabel->Text = (L"Scoring Points: " + roundf(drcpoints_scoring));
					}
				}
			}
			else
			{
				infoBox->Items->Add("Get Exit Code failed. Returned ID: " + GetLastError());
			}
		}
		else
		{
			this->infoBox->Items->Add("Game not found. ID Returned: " + fail);
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->gameLabel->Text = L"";
			this->gameLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->diffLabel->Text = L"";
			this->diffLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->shottypeLabel->Text = L"";
			this->shottypeLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->missesLabel->Text = L"";
			this->missesLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bombsLabel->Text = L"";
			this->bombsLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->scoreLabel->Text = L"";
			this->scoreLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->survivalLabel->Text = L"";
			this->survivalLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->scoringLabel->Text = L"";
			this->scoringLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
		}		
	}

	private: System::Void bkgProc_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
	{
		BackgroundWorker^ worker = (BackgroundWorker^)sender;
		
	}

	private: System::Void bkgProc_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e)
	{

		// GetExitCodeProcess(gameProc, &procStatus);
	}

	};
}
