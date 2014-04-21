#pragma once

#include "FollowMeReferee.h"

namespace FollowMeReferee {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			m_srv = nullptr;
			m_connected = false;

			// 接続を試みる
			m_srv = gcnew Referee("FollowMeReferee");
			cli::array<System::String^>^ args = System::Environment::GetCommandLineArgs();

			//if(m_srv->connect("socio4.iir.nii.ac.jp", 9333)){
			if(m_srv->connect(args[1], System::Convert::ToInt32(args[2]))){
				m_connected = true;
				this->connect->Enabled = false;
					 
				m_srv->connectToViewer();
				m_srv->setAutoExitProc(true);
			}
		}
		void setText(System::String^ text)
		{
			this->label1->Text = text;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			m_srv = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  connect;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
			 
			 
			 //sigverse::SIGService ^srv = gcnew sigverse::SIGService("RobocupReferee");
			 Referee ^m_srv;
	private: System::Windows::Forms::Label^  label3;
			 bool m_connected;
			 //srv->connect("socio4.iir.nii.ac.jp", 9333);
			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->connect = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"HGSGothicE", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(170, 255);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Total";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// connect
			// 
			this->connect->Enabled = false;
			this->connect->Font = (gcnew System::Drawing::Font(L"HGPGothicE", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->connect->Location = System::Drawing::Point(12, 293);
			this->connect->Name = L"connect";
			this->connect->Size = System::Drawing::Size(110, 38);
			this->connect->TabIndex = 1;
			this->connect->Text = L"Connect";
			this->connect->UseVisualStyleBackColor = true;
			this->connect->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"HGPGothicE", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->button1->Location = System::Drawing::Point(128, 293);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Disconnect";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_2);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"HGPGothicE", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->button2->Location = System::Drawing::Point(280, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 38);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Initialize";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->listBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->ItemHeight = 21;
			this->listBox1->Location = System::Drawing::Point(16, 45);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(261, 193);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"HGSGothicE", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(271, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Score";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->textBox1->Location = System::Drawing::Point(262, 249);
			this->textBox1->Name = L"textBox1";
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBox1->Size = System::Drawing::Size(103, 31);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// listBox2
			// 
			this->listBox2->BackColor = System::Drawing::SystemColors::InfoText;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->listBox2->ForeColor = System::Drawing::SystemColors::Menu;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 21;
			this->listBox2->Location = System::Drawing::Point(274, 45);
			this->listBox2->Name = L"listBox2";
			this->listBox2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox2->Size = System::Drawing::Size(91, 193);
			this->listBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"HGSGothicE", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(13, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Comment";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(390, 352);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->connect);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"Robocup@home 2014";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


				 //
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
				 if(m_srv == nullptr){
					 m_srv = gcnew Referee("FollowMeReferee");
					 if(m_srv->connect("socio4.iir.nii.ac.jp", 9333)){
						 m_connected = true;
						 m_srv->connectToViewer();
						 m_srv->setAutoExitProc(true);
					 }
				 }
			 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 if(m_srv != nullptr){
				 m_srv->checkRecvData(100);
				 int ssize = m_srv->getScoreSize();
				 // メッセージが来た
				 for(int i = 0; i < ssize; i++){
					 int score = m_srv->getScore();
					 System::String^ msg = m_srv->getMessage();
					 System::String^ listitem_msg = msg;// + "                    " + score.ToString();
					 System::String^ listitem_score = score.ToString();
					 this->listBox1->Items->Add(listitem_msg);
					 this->listBox2->Items->Add(listitem_score);
					 int total = m_srv->getTotal();
					 this->textBox1->Text = total.ToString();
				 }
			 }
		 }
private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
			 m_srv->disconnect();
			 this->connect->Enabled = true;
			 m_connected = false;
			 m_srv = nullptr;
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 m_srv->setTotal(0);
			 this->textBox1->Text = L"0";
			 this->listBox1->Items->Clear();
			 this->listBox2->Items->Clear();
		 }
};
}

