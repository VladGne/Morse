#include <iostream>
#include <string>
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <algorithm>

#pragma once

namespace Morse {	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	std::string EngAlphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',' };
	std::string MorseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };

	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^  TxtToMorseButton;
	private: System::Windows::Forms::Button^  MorseToTxtButton;
	private: System::Windows::Forms::Label^  TxtToMorseLabel;
	private: System::Windows::Forms::Label^  MorseToTxtLabel;
	private: System::Windows::Forms::TextBox^  TxtBox;
	private: System::Windows::Forms::TextBox^  MorseBox;



	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->TxtToMorseButton = (gcnew System::Windows::Forms::Button());
			this->MorseToTxtButton = (gcnew System::Windows::Forms::Button());
			this->TxtToMorseLabel = (gcnew System::Windows::Forms::Label());
			this->MorseToTxtLabel = (gcnew System::Windows::Forms::Label());
			this->TxtBox = (gcnew System::Windows::Forms::TextBox());
			this->MorseBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->TxtToMorseButton, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->MorseToTxtButton, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->TxtToMorseLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->MorseToTxtLabel, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->TxtBox, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->MorseBox, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.192575F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 92.80743F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(557, 482);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// TxtToMorseButton
			// 
			this->TxtToMorseButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TxtToMorseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->TxtToMorseButton->Location = System::Drawing::Point(3, 434);
			this->TxtToMorseButton->Name = L"TxtToMorseButton";
			this->TxtToMorseButton->Size = System::Drawing::Size(272, 45);
			this->TxtToMorseButton->TabIndex = 0;
			this->TxtToMorseButton->Text = L"Translate eng text to morse code";
			this->TxtToMorseButton->UseVisualStyleBackColor = true;
			this->TxtToMorseButton->Click += gcnew System::EventHandler(this, &MainForm::TxtToMorseButton_Click);
			// 
			// MorseToTxtButton
			// 
			this->MorseToTxtButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MorseToTxtButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->MorseToTxtButton->Location = System::Drawing::Point(281, 434);
			this->MorseToTxtButton->Name = L"MorseToTxtButton";
			this->MorseToTxtButton->Size = System::Drawing::Size(273, 45);
			this->MorseToTxtButton->TabIndex = 1;
			this->MorseToTxtButton->Text = L"Stranslate Morse code to eng text";
			this->MorseToTxtButton->UseVisualStyleBackColor = true;
			this->MorseToTxtButton->Click += gcnew System::EventHandler(this, &MainForm::MorseToTxtButton_Click);
			// 
			// TxtToMorseLabel
			// 
			this->TxtToMorseLabel->AutoSize = true;
			this->TxtToMorseLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TxtToMorseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.3F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TxtToMorseLabel->Location = System::Drawing::Point(3, 0);
			this->TxtToMorseLabel->Name = L"TxtToMorseLabel";
			this->TxtToMorseLabel->Size = System::Drawing::Size(272, 31);
			this->TxtToMorseLabel->TabIndex = 2;
			this->TxtToMorseLabel->Text = L"ENG TEXT";
			this->TxtToMorseLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MorseToTxtLabel
			// 
			this->MorseToTxtLabel->AutoSize = true;
			this->MorseToTxtLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MorseToTxtLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.3F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MorseToTxtLabel->Location = System::Drawing::Point(281, 0);
			this->MorseToTxtLabel->Name = L"MorseToTxtLabel";
			this->MorseToTxtLabel->Size = System::Drawing::Size(273, 31);
			this->MorseToTxtLabel->TabIndex = 3;
			this->MorseToTxtLabel->Text = L"MORSE CODE";
			this->MorseToTxtLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtBox
			// 
			this->TxtBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TxtBox->Location = System::Drawing::Point(3, 34);
			this->TxtBox->Multiline = true;
			this->TxtBox->Name = L"TxtBox";
			this->TxtBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TxtBox->Size = System::Drawing::Size(272, 394);
			this->TxtBox->TabIndex = 4;
			// 
			// MorseBox
			// 
			this->MorseBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MorseBox->Location = System::Drawing::Point(281, 34);
			this->MorseBox->Multiline = true;
			this->MorseBox->Name = L"MorseBox";
			this->MorseBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MorseBox->Size = System::Drawing::Size(273, 394);
			this->MorseBox->TabIndex = 5;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(557, 482);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	
	private: System::Void TxtToMorseButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		msclr::interop::marshal_context context;

		std::string InputText = context.marshal_as<std::string>(TxtBox->Text);
		std::string MorseCode = TranslateToMorse(InputText);
		MorseBox->Text = gcnew String(MorseCode.c_str());				
	}

	private: System::Void MorseToTxtButton_Click(System::Object^  sender, System::EventArgs^  e) {
	
		msclr::interop::marshal_context context;
		
		std::string MorseCode = context.marshal_as<std::string>(MorseBox->Text);
		std::string Text = TranslateToText(MorseCode);
		TxtBox->Text = gcnew String(Text.c_str());
	}

	private: std::string TranslateToMorse(std::string Text)
	{
		std::string Morse;		

		std::transform(Text.begin(), Text.end(), Text.begin(), ::toupper);
		for (unsigned i = 0; i < Text.length(); ++i)
		{
			for (int counter = 0; counter < 30; counter++)
			{
				if (Text.at(i) == EngAlphabet[counter])
				{
					Morse += MorseAlphabet[counter] + ' ';
					break;
				}
			}
		}
		return Morse;
	}

	private: std::string TranslateToText(std::string Morse)
	{
		std::string Text;	

		for (unsigned i = 0; i < Morse.length(); ++i)
		{
			std::string token = Morse.substr(i, Morse.find(' '));
			token = token.substr(0, token.find(' '));
			for (int counter = 0; counter < 30; counter++)
			{
				if (token == MorseAlphabet[counter])
				{
					Text += EngAlphabet[counter];
					i += token.length();
					break;
				}
			}
		}
		return Text;
	}
};
}
