#pragma once
#include "WarpZone.h"

namespace PB {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
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
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		void ChangeScape(int ow)
		{
			this->input->Clear();
			this->key->Clear();
			this->output->Clear();
			switch (ow)
			{
			case 0:
				this->input->Enabled = true;
				this->key->Enabled = true;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = false;
				this->key->Visible = true;
				break;
			case 1:
				this->input->Enabled = true;
				this->key->Enabled = true;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = false;
				this->key->Visible = true;
				break;
			case 2:
				this->input->Enabled = true;
				this->key->Enabled = false;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = false;
				this->key->Visible = true;
				break;
			case 3:
				this->input->Enabled = true;
				this->key->Enabled = true;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = false;
				this->key->Visible = true;
				break;
			case 4:
				this->input->Enabled = true;
				this->key->Enabled = true;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = false;
				this->key->Visible = true;
				break;
			case 5:
				this->input->Enabled = true;
				this->key->Enabled = true;
				this->encrypt->Enabled = true;
				this->decrypt->Enabled = true;
				this->filebutton->Visible = true;
				this->key->Visible = false;
				break;
			}
		}

	private: System::Windows::Forms::ComboBox^ selector;
	private: System::Windows::Forms::Button^ encrypt;
	private: System::Windows::Forms::Button^ decrypt;
	private: System::Windows::Forms::TextBox^ input;
	private: System::Windows::Forms::TextBox^ key;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ output;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::OpenFileDialog^ openfile;
	private: System::Windows::Forms::Button^ filebutton;
	private: System::Windows::Forms::Label^ desc;





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
			this->selector = (gcnew System::Windows::Forms::ComboBox());
			this->encrypt = (gcnew System::Windows::Forms::Button());
			this->decrypt = (gcnew System::Windows::Forms::Button());
			this->input = (gcnew System::Windows::Forms::TextBox());
			this->key = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->openfile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->filebutton = (gcnew System::Windows::Forms::Button());
			this->desc = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// selector
			// 
			this->selector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->selector->FormattingEnabled = true;
			this->selector->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Caesar Cipher (Rotation Cipher)", L"Polybius Square",
					L"Morse Code", L"Vingenere Code", L"Scytale Cipher", L"Book Cipher"
			});
			this->selector->Location = System::Drawing::Point(13, 4);
			this->selector->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->selector->Name = L"selector";
			this->selector->Size = System::Drawing::Size(340, 33);
			this->selector->TabIndex = 5;
			this->selector->TabStop = false;
			this->selector->Text = L"(Select)";
			this->selector->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::selector_SelectedIndexChanged);
			// 
			// encrypt
			// 
			this->encrypt->Enabled = false;
			this->encrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->encrypt->Location = System::Drawing::Point(245, 368);
			this->encrypt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->encrypt->Name = L"encrypt";
			this->encrypt->Size = System::Drawing::Size(107, 39);
			this->encrypt->TabIndex = 3;
			this->encrypt->Text = L"Encrypt";
			this->encrypt->UseVisualStyleBackColor = true;
			this->encrypt->Click += gcnew System::EventHandler(this, &Main::encrypt_Click);
			// 
			// decrypt
			// 
			this->decrypt->Enabled = false;
			this->decrypt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->decrypt->Location = System::Drawing::Point(397, 368);
			this->decrypt->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->decrypt->Name = L"decrypt";
			this->decrypt->Size = System::Drawing::Size(107, 39);
			this->decrypt->TabIndex = 4;
			this->decrypt->Text = L"Decrypt";
			this->decrypt->UseVisualStyleBackColor = true;
			this->decrypt->Click += gcnew System::EventHandler(this, &Main::decrypt_Click);
			// 
			// input
			// 
			this->input->Enabled = false;
			this->input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->input->Location = System::Drawing::Point(13, 182);
			this->input->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(340, 30);
			this->input->TabIndex = 0;
			// 
			// key
			// 
			this->key->Enabled = false;
			this->key->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->key->Location = System::Drawing::Point(13, 249);
			this->key->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->key->Name = L"key";
			this->key->Size = System::Drawing::Size(340, 30);
			this->key->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 154);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Input";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 25);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Key";
			// 
			// output
			// 
			this->output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->output->Location = System::Drawing::Point(397, 222);
			this->output->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->output->Name = L"output";
			this->output->ReadOnly = true;
			this->output->Size = System::Drawing::Size(340, 30);
			this->output->TabIndex = 7;
			this->output->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(392, 193);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Output";
			// 
			// openfile
			// 
			this->openfile->DefaultExt = L"txt";
			this->openfile->FileName = L"book.txt";
			this->openfile->Filter = L"Text Files (*.txt)|";
			this->openfile->InitialDirectory = L"C:\\Users\\nikle\\source\\repos\\Project Babel DropBox";
			this->openfile->RestoreDirectory = true;
			this->openfile->Title = L"Select Book";
			// 
			// filebutton
			// 
			this->filebutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->filebutton->Location = System::Drawing::Point(12, 249);
			this->filebutton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->filebutton->Name = L"filebutton";
			this->filebutton->Size = System::Drawing::Size(107, 39);
			this->filebutton->TabIndex = 9;
			this->filebutton->TabStop = false;
			this->filebutton->Text = L"Open File";
			this->filebutton->UseVisualStyleBackColor = true;
			this->filebutton->Visible = false;
			this->filebutton->Click += gcnew System::EventHandler(this, &Main::filebutton_Click);
			// 
			// desc
			// 
			this->desc->AutoSize = true;
			this->desc->Location = System::Drawing::Point(9, 53);
			this->desc->Name = L"desc";
			this->desc->Size = System::Drawing::Size(170, 16);
			this->desc->TabIndex = 10;
			this->desc->Text = L"HERE LIES DESCRIPTION";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 453);
			this->Controls->Add(this->desc);
			this->Controls->Add(this->filebutton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->output);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->key);
			this->Controls->Add(this->input);
			this->Controls->Add(this->decrypt);
			this->Controls->Add(this->encrypt);
			this->Controls->Add(this->selector);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->Text = L"Project Babel";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void encrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	auto inc = selector->SelectedIndex;
	auto ins = input->Text, ink = key->Text;
	auto out = Encrypt(inc, ins, ink);
	output->Text = out;
}
private: System::Void decrypt_Click(System::Object^ sender, System::EventArgs^ e) {
	auto inc = selector->SelectedIndex;
	auto ins = input->Text, ink = key->Text;
	auto out = Decrypt(inc, ins, ink);
	output->Text = out;
}
private: System::Void selector_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ChangeScape(selector->SelectedIndex);
}
private: System::Void filebutton_Click(System::Object^ sender, System::EventArgs^ e) {
	openfile->ShowDialog();
	auto fs = openfile->FileName;
	key->Text =	System::IO::File::ReadAllText(fs);
}
};
}
