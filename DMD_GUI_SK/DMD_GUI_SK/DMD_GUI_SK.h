//24.08.21 Modified - Sein Kim
#pragma once
// C++ header files
#include <iostream>
#include <cmath>

// Windows header files
#include <Windows.h>
#include <WinUser.h>

// OpenCV header files
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

// Arduino header files
#include <stdio.h>
#include <tchar.h>
#include <string>

//OpenFileDialog string header files
#include <msclr\marshal_cppstd.h>

//To use push_back
#include <vector>

//To sort filenames naturally
#include "natural_sort.hpp"

//To write time in the txt file
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>


namespace DMDGUISK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	///Add namespace
	using namespace std;
	using namespace cv;
	//using namespace std::chrono; //For timer
	

	///Window position
	// Main monitor (left) -> TV monitor (middle) -> DMD monitor (right)
	// 1920*1080 -> 3840*2160 -> 1280*720
	double monitorx = 1920 + 3840 + 1280;
	
	double dmdx = 1280;
	double tvx = 3840;
		
	double dmdy = 720;
	double tvy = 2160;
	
	double dmdx_start = monitorx - dmdx;
	double dmdy_start = 0;

	double tvx_start = monitorx - dmdx - tvx;
	double tvy_start = 0;
	

	///Window background image
	int bgc = 0;
	Mat bg(dmdy, dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));

	//TV window electrodes image
	Mat mea = imread("MEA_ElectrodesforDMD.png", IMREAD_COLOR);

	/// <summary>
	/// DMD_GUI_SK에 대한 요약입니다.
	/// </summary>
	public ref class DMD_GUI_SK : public System::Windows::Forms::Form
	{
	public:
		DMD_GUI_SK(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			///Make Window for DMD
			namedWindow("DMD_PATTERN", WINDOW_NORMAL);
			moveWindow("DMD_PATTERN", dmdx_start, dmdy_start);
			setWindowProperty("DMD_PATTERN", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);

			imshow("DMD_PATTERN", bg);
			waitKey(1);

			///To show how the stimulation looks on the MEA
			//Make window for TV
			namedWindow("TV_PATTERN", WINDOW_NORMAL);
			//moveWindow("TV_PATTERN", 0, 0);
			moveWindow("TV_PATTERN", tvx_start, tvy_start);
			resizeWindow("TV_PATTERN", 1280, 720);

			imshow("TV_PATTERN", mea);
			waitKey(1);

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~DMD_GUI_SK()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::GroupBox^ groupBox4;



	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label11;
	private: System::IO::Ports::SerialPort^ serialPort1;




	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Label^ label15;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;

	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox11;

	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::GroupBox^ groupBox10;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::TextBox^ textBox12;



	private: System::ComponentModel::IContainer^ components;

	protected:


	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DMD_GUI_SK::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox11->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(23, 245);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(379, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"RGB Code (0-255)";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(302, 45);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(63, 34);
			this->textBox3->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Blue;
			this->label4->Location = System::Drawing::Point(251, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 21);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Blue";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(182, 45);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(63, 34);
			this->textBox2->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Green;
			this->label3->Location = System::Drawing::Point(118, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 21);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Green";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(51, 45);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 34);
			this->textBox1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(6, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Red";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(282, 25);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label2->Size = System::Drawing::Size(470, 54);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Visual stimulation";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(409, 245);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox2->Size = System::Drawing::Size(141, 100);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Size";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(56, 45);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(74, 34);
			this->textBox4->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(6, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 21);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Size";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(555, 245);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox3->Size = System::Drawing::Size(251, 100);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Position";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(181, 45);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(63, 34);
			this->textBox6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(125, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 21);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Y Pos";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(59, 45);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(63, 34);
			this->textBox5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(5, 50);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 21);
			this->label6->TabIndex = 7;
			this->label6->Text = L"X Pos";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBox9);
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Controls->Add(this->textBox8);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->textBox7);
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(23, 351);
			this->groupBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox5->Size = System::Drawing::Size(799, 100);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Stimulation Parameters";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(705, 45);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(83, 34);
			this->textBox9->TabIndex = 14;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(591, 50);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(115, 21);
			this->label10->TabIndex = 14;
			this->label10->Text = L"Repeat times";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(505, 45);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(83, 34);
			this->textBox8->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(301, 50);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(205, 21);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Refractory period [msec]";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(217, 45);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(83, 34);
			this->textBox7->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(6, 50);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(210, 21);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Stimulation period [msec]";
			// 
			// groupBox6
			// 
			this->groupBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(17)), static_cast<System::Int32>(static_cast<System::Byte>(86)),
				static_cast<System::Int32>(static_cast<System::Byte>(149)));
			this->groupBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->groupBox6->Controls->Add(this->button12);
			this->groupBox6->Controls->Add(this->button5);
			this->groupBox6->Controls->Add(this->button4);
			this->groupBox6->Controls->Add(this->button2);
			this->groupBox6->Controls->Add(this->button1);
			this->groupBox6->Controls->Add(this->button3);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"Georgia", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox6->ForeColor = System::Drawing::Color::White;
			this->groupBox6->Location = System::Drawing::Point(23, 572);
			this->groupBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox6->Size = System::Drawing::Size(683, 106);
			this->groupBox6->TabIndex = 5;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Stimulate";
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Black;
			this->button12->Location = System::Drawing::Point(443, 45);
			this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button12->Name = L"button12";
			this->button12->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button12->Size = System::Drawing::Size(83, 38);
			this->button12->TabIndex = 24;
			this->button12->Text = L"Images";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button12_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(533, 45);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(139, 38);
			this->button5->TabIndex = 23;
			this->button5->Text = L"Play Video";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(354, 45);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button4->Size = System::Drawing::Size(83, 38);
			this->button4->TabIndex = 22;
			this->button4->Text = L"Image";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button4_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(101, 45);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button2->Size = System::Drawing::Size(101, 38);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Square";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(10, 45);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 38);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Spot";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(207, 45);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button3->Size = System::Drawing::Size(139, 38);
			this->button3->TabIndex = 21;
			this->button3->Text = L"Moving Bar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button3_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox13);
			this->groupBox4->Controls->Add(this->textBox11);
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label14);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->textBox10);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(23, 459);
			this->groupBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox4->Size = System::Drawing::Size(489, 80);
			this->groupBox4->TabIndex = 12;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Moving Bar";
			// 
			// textBox13
			// 
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(390, 34);
			this->textBox13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(79, 34);
			this->textBox13->TabIndex = 17;
			// 
			// textBox11
			// 
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(222, 34);
			this->textBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(79, 34);
			this->textBox11->TabIndex = 16;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(315, 50);
			this->label13->Name = L"label13";
			this->label13->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label13->Size = System::Drawing::Size(68, 21);
			this->label13->TabIndex = 16;
			this->label13->Text = L"(0-100)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(319, 28);
			this->label14->Name = L"label14";
			this->label14->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label14->Size = System::Drawing::Size(62, 21);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Speed";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(152, 38);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(62, 21);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Height";
			// 
			// textBox10
			// 
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(67, 34);
			this->textBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(79, 34);
			this->textBox10->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(6, 38);
			this->label11->Name = L"label11";
			this->label11->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->label11->Size = System::Drawing::Size(56, 21);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Width";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Salmon;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(15, 36);
			this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button6->Name = L"button6";
			this->button6->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button6->Size = System::Drawing::Size(105, 38);
			this->button6->TabIndex = 24;
			this->button6->Text = L"Exit";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button6_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM5";
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(14, 46);
			this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(168, 34);
			this->button7->TabIndex = 1;
			this->button7->Text = L"Spot-input";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button7_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button11);
			this->groupBox7->Controls->Add(this->button10);
			this->groupBox7->Controls->Add(this->button9);
			this->groupBox7->Controls->Add(this->button8);
			this->groupBox7->Controls->Add(this->button7);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox7->Location = System::Drawing::Point(23, 118);
			this->groupBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox7->Size = System::Drawing::Size(943, 100);
			this->groupBox7->TabIndex = 18;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Input List Check";
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(759, 46);
			this->button11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(168, 34);
			this->button11->TabIndex = 5;
			this->button11->Text = L"Video-input";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button11_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(573, 46);
			this->button10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(168, 34);
			this->button10->TabIndex = 4;
			this->button10->Text = L"Images-input";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button10_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(385, 46);
			this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(168, 34);
			this->button9->TabIndex = 3;
			this->button9->Text = L"Moving bar-input";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button9_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(199, 46);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(168, 34);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Square-input";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button8_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->textBox14);
			this->groupBox8->Controls->Add(this->label15);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox8->Location = System::Drawing::Point(529, 459);
			this->groupBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox8->Size = System::Drawing::Size(169, 80);
			this->groupBox8->TabIndex = 8;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Angle";
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(78, 36);
			this->textBox14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(77, 34);
			this->textBox14->TabIndex = 18;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(6, 41);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(69, 21);
			this->label15->TabIndex = 7;
			this->label15->Text = L"Degree";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->button13);
			this->groupBox9->Controls->Add(this->button6);
			this->groupBox9->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox9->Location = System::Drawing::Point(713, 458);
			this->groupBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox9->Size = System::Drawing::Size(253, 82);
			this->groupBox9->TabIndex = 8;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Exit,Re-Start";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::PaleGreen;
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(126, 36);
			this->button13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button13->Name = L"button13";
			this->button13->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button13->Size = System::Drawing::Size(121, 38);
			this->button13->TabIndex = 25;
			this->button13->Text = L"Re-start";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &DMD_GUI_SK::button13_Click);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->comboBox1);
			this->groupBox10->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox10->Location = System::Drawing::Point(811, 245);
			this->groupBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox10->Size = System::Drawing::Size(154, 100);
			this->groupBox10->TabIndex = 10;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Brightness";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"100", L"75", L"50", L"25", L"0", L"-25", L"-50",
					L"-75", L"-100"
			});
			this->comboBox1->Location = System::Drawing::Point(16, 45);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 34);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"0";
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->textBox12);
			this->groupBox11->Font = (gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox11->Location = System::Drawing::Point(832, 351);
			this->groupBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox11->Size = System::Drawing::Size(154, 100);
			this->groupBox11->TabIndex = 11;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Contrast";
			// 
			// textBox12
			// 
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(21, 50);
			this->textBox12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(114, 34);
			this->textBox12->TabIndex = 19;
			this->textBox12->Text = L"1";
			// 
			// DMD_GUI_SK
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(997, 698);
			this->Controls->Add(this->groupBox11);
			this->Controls->Add(this->groupBox10);
			this->Controls->Add(this->groupBox9);
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"DMD_GUI_SK";
			this->Text = L"DMD_GUI_SK";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox10->ResumeLayout(false);
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		///button1 - spot stimulation
		
		//Set spot
		Mat spot, spot1;
		bg.copyTo(spot);
		mea.copyTo(spot1);

		//Set spot's color
		int red = Convert::ToInt32(textBox1->Text);
		int green = Convert::ToInt32(textBox2->Text);
		int blue = Convert::ToInt32(textBox3->Text);

		//Set spot's size
		int size = Convert::ToInt32(textBox4->Text); 

		//Set spot's position
		int xpos = Convert::ToInt32(textBox5->Text);
		int ypos = Convert::ToInt32(textBox6->Text);

		//Calibrate size and position
		size = size * 2;
		xpos = xpos * 2;
		ypos = ypos * 2;

		//Set spot's brightness
		int bright = Convert::ToInt32(comboBox1->Text);

		//Set spot's contrast
		float contrast = Convert::ToDouble(textBox12->Text);

		//Set stimulation parameters
		int stim_time = Convert::ToInt32(textBox7->Text);
		int ref_time = Convert::ToInt32(textBox8->Text);
		int repeat_time = Convert::ToInt32(textBox9->Text);

		//Send trigger to Arduino
		serialPort1 -> Open();
		//serialPort1 -> Write("<" + textBox7->Text + "," + textBox8->Text + "," + textBox9->Text + ">");	//Trigger_2023Ver
		//serialPort1 -> Close();																			//Trigger_2023Ver

		//Create spot
		//Scalar(blue,green,red)
		circle(spot, cv::Point(xpos, ypos), size, Scalar(blue, green, red), -1, 16, 1);
		spot.convertTo(spot, -1, contrast, bright);
		circle(spot1, cv::Point(xpos, ypos), size, Scalar(blue, green, red),-1, 16, 1);
		spot1.convertTo(spot1, -1, contrast, bright);

		
		//Create spots according to stimulation parameters
		for (repeat_time; repeat_time > 0; repeat_time--)
		{
			if (ref_time == 0)
			{
				serialPort1->Write("<1,0,1>");	//Trigger_2024Ver
				imshow("DMD_PATTERN", spot);
				imshow("TV_PATTERN", spot1);
				waitKey(stim_time);
			}
			else
			{
				serialPort1->Write("<1,0,1>");	//Trigger_2024Ver
				imshow("DMD_PATTERN", spot);
				imshow("TV_PATTERN", spot1);
				waitKey(stim_time);
				serialPort1->Write("<1,0,1>");	//Trigger_2024Ver
				imshow("DMD_PATTERN", bg);
				imshow("TV_PATTERN", mea);
				waitKey(ref_time);
			}

		}
		serialPort1->Close();		//Trigger_2024Ver

		//After stimulation
		imshow("DMD_PATTERN", bg);
		imshow("TV_PATTERN", mea);
		waitKey(0);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		///button2 - Square stimulation (Mostly for calibration)

		//Set square
		Mat squ,squ1;
		bg.copyTo(squ);
		mea.copyTo(squ1);

		//Set square's color
		int red = Convert::ToInt32(textBox1->Text);
		int green = Convert::ToInt32(textBox2->Text);
		int blue = Convert::ToInt32(textBox3->Text);

		//Set square's size
		int size = Convert::ToInt32(textBox4->Text);

		//Set square's position
		int xpos = Convert::ToInt32(textBox5->Text);
		int ypos = Convert::ToInt32(textBox6->Text);

		//Set square's brightness
		int bright = Convert::ToInt32(comboBox1->Text);

		//Set square's contrast
		float contrast = Convert::ToDouble(textBox12->Text);

		//Set stimulation parameters
		int stim_time = Convert::ToInt32(textBox7->Text);
		int ref_time = Convert::ToInt32(textBox8->Text);
		int repeat_time = Convert::ToInt32(textBox9->Text);

		//Send trigger to Arduino
		serialPort1->Open();
		serialPort1->Write("<" + textBox7->Text + "," + textBox8->Text + "," + textBox9->Text + ">");	//Trigger_2023Ver
		serialPort1->Close();																			

		//Create square
		//Scalar(blue,green,red)
		rectangle(squ, Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size)), Scalar(blue, green, red), 5, 16, 0);
		squ.convertTo(squ, -1, contrast, bright);
		rectangle(squ1, Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size)), Scalar(blue, green, red), 5, 16, 0);
		squ1.convertTo(squ1, -1, contrast, bright);

		//Create squares according to stimulation parameters
		for (repeat_time; repeat_time > 0; repeat_time--)
		{
			imshow("DMD_PATTERN", squ);
			imshow("TV_PATTERN", squ1);
			waitKey(stim_time);
			imshow("DMD_PATTERN", bg);
			imshow("TV_PATTERN", mea);
			waitKey(ref_time);
		}

		//After stimulation
		imshow("DMD_PATTERN", bg);
		waitKey(0);
	
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		///button3 - Moving bar stimulation

		//Set moving bar in the for loop
	
		//Set moving bar's color
		int red = Convert::ToInt32(textBox1->Text);
		int green = Convert::ToInt32(textBox2->Text);
		int blue = Convert::ToInt32(textBox3->Text);

		//Set moving bar's width & height
		int mb_w = Convert::ToInt32(textBox10->Text);
		int mb_h = Convert::ToInt32(textBox11->Text);

		//Set moving bar's position
		int xpos = Convert::ToInt32(textBox5->Text);
		int ypos = Convert::ToInt32(textBox6->Text);

		//Set moving bar's angle + Always rotate 90 degree
		int ang = Convert::ToInt32(textBox14->Text);
		//ang = ang - 90;

		//Set moving bar's speed
		int speed = Convert::ToInt32(textBox13->Text);

		//Set moving bar's brightness
		int bright = Convert::ToInt32(comboBox1->Text);

		//Set moving bar's contrast
		float contrast = Convert::ToDouble(textBox12->Text);


		//Send trigger to Arduino
		serialPort1->Open();

		///Create moving bar
		//Scalar(blue,green,red)
		double rad_ang = (ang + 90) * 3.1416 / 180;
		cv::Point mb_point[1][4];

		//serialPort1->Write("<1,0,1>");

		for (int i = 0; i < dmdx/4; i++)
		{
			//Set moving bar
			Mat mb(dmdy,dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));
			Mat mb1(dmdy, dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));
			bg.copyTo(mb);
			mea.copyTo(mb1);

			//Using Rotation Matrix
			mb_point[0][0] = cv::Point(i * sin(rad_ang) + xpos + cos(rad_ang) * (-mb_w / 2) + sin(rad_ang) * (-mb_h / 2), i * cos(rad_ang) + ypos - sin(rad_ang) * (-mb_w / 2) + cos(rad_ang) * (-mb_h / 2));
			mb_point[0][1] = cv::Point(i * sin(rad_ang) + xpos + cos(rad_ang) * (mb_w / 2) + sin(rad_ang) * (-mb_h / 2), i * cos(rad_ang) + ypos - sin(rad_ang) * (mb_w / 2) + cos(rad_ang) * (-mb_h / 2));
			mb_point[0][2] = cv::Point(i * sin(rad_ang) + xpos + cos(rad_ang) * (mb_w / 2) + sin(rad_ang) * (mb_h / 2), i * cos(rad_ang) + ypos - sin(rad_ang) * (mb_w / 2) + cos(rad_ang) * (mb_h / 2));
			mb_point[0][3] = cv::Point(i * sin(rad_ang) + xpos + cos(rad_ang) * (-mb_w / 2) + sin(rad_ang) * (mb_h / 2), i * cos(rad_ang) + ypos - sin(rad_ang) * (-mb_w / 2) + cos(rad_ang) * (mb_h / 2));

			const cv::Point* mppt[1] = { mb_point[0] };
			int npt[] = { 4 };

			fillPoly(mb, mppt, npt, 1, Scalar(blue, green, red), 16, 0);
			fillPoly(mb1, mppt, npt, 1, Scalar(blue, green, red), 16, 0);

			mb.convertTo(mb, -1, contrast, bright);
			mb1.convertTo(mb1, -1, contrast, bright);
			
			if (i % 32 == 0)
			{
				serialPort1->Write("<1,0,1>");
			}

			imshow("DMD_PATTERN", mb);
			imshow("TV_PATTERN", mb1);
			waitKey(100 / speed);
		}
		serialPort1->Write("<1,0,1>");		//Trigger_2024Ver
		serialPort1->Close();


		//After stimulation
		//serialPort1->Write("<1,0,1>");
		imshow("DMD_PATTERN", bg);
		imshow("TV_PATTERN", mea);
		waitKey(0);
		//serialPort1->Close();

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		///button4 - One image stimulation by opening a one file
		
		//Set image
		Mat img;
		Mat resize_img;
		Mat resize_img1;
		Mat bg1(dmdy,dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));
		//Mat bg2(720,1280,CV_8UC3, Scalar)
		Mat mea1 = imread("MEA_ElectrodesforDMD.png", IMREAD_COLOR);


		//A image read by opening file dialog
		openFileDialog1->Filter = "All files (*.*) |*.*| .JPG,.PNG Files | *.JPG;*.PNG";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			std::string img_file = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			img = imread(img_file, IMREAD_COLOR);
		}

		//Set image's size
		int size = Convert::ToInt32(textBox4->Text);

		//Set image's position
		int xpos = Convert::ToInt32(textBox5->Text);
		int ypos = Convert::ToInt32(textBox6->Text);

		//Set image's brightness
		int bright = Convert::ToInt32(comboBox1->Text);

		//Set image's contrast
		float contrast = Convert::ToDouble(textBox12->Text);

		//Set image's angle
		int img_ang = Convert::ToInt32(textBox14->Text);

		//Set stimulation parameters
		int stim_time = Convert::ToInt32(textBox7->Text);
		int ref_time = Convert::ToInt32(textBox8->Text);
		int repeat_time = Convert::ToInt32(textBox9->Text);

		//Send trigger to Arduino
		serialPort1->Open();
		serialPort1->Write("<" + textBox7->Text + "," + textBox8->Text + "," + textBox9->Text + ">");		//Trigger_2023Ver
		serialPort1->Close();
		
		//Create resized & rotated image
		int rot_img_ang = img_ang + 90;
		cv::Point center = cv::Point((img.cols - 1) / 2, (img.rows - 1) / 2);
		
		Mat rot_img = getRotationMatrix2D(center, rot_img_ang,1);
		Rect2f bbox = cv::RotatedRect(cv::Point(), img.size(), rot_img_ang).boundingRect2f();
		rot_img.at<double>(0, 2) += bbox.width / 2.0 - img.cols / 2.0;
		rot_img.at<double>(1, 2) += bbox.height / 2.0 - img.rows / 2.0;
		
		warpAffine(img, resize_img, rot_img, bbox.size());

		resize(resize_img, resize_img, cv::Size(size*2, size*2));
		resize_img.convertTo(resize_img, -1, contrast, bright);
		
		//Image shown on MEA
		rotate(resize_img,resize_img1, ROTATE_90_CLOCKWISE);
		resize_img1.convertTo(resize_img1, -1, contrast, bright);
		
		//Copy the modified image to mat
		resize_img.copyTo(bg1(cv::Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size))));
		resize_img1.copyTo(mea1(cv::Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size))));


		//Show an image according to stimulation parameters
		for (repeat_time; repeat_time > 0; repeat_time--)
		{
			imshow("DMD_PATTERN", bg1);
			imshow("TV_PATTERN",mea1);
			waitKey(stim_time);
			imshow("DMD_PATTERN", bg);
			imshow("TV_PATTERN", mea);
			waitKey(ref_time);
		}

		//After stimulation
		imshow("DMD_PATTERN", bg);
		imshow("TV_PATTERN", mea);
		waitKey(0);

	}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) 
{
	///button12 - Images stimulation by opening a folder

	//Set images' size
	int size = Convert::ToInt32(textBox4->Text);

	//Set images' position
	int xpos = Convert::ToInt32(textBox5->Text);
	int ypos = Convert::ToInt32(textBox6->Text);

	//Set images' brightness
	int bright = Convert::ToInt32(comboBox1->Text);

	//Set images' contrast
	float contrast = Convert::ToDouble(textBox12->Text);

	//Set images' angle
	int img_ang = Convert::ToInt32(textBox14->Text);

	//Set stimulation parameters
	int stim_time = Convert::ToInt32(textBox7->Text);
	int ref_time = Convert::ToInt32(textBox8->Text);
	//int repeat_time = Convert::ToInt32(textBox9->Text);
	int repeat_time = 1;


	//Images read by opening folder dialog
	if (folderBrowserDialog1-> ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		System::String^ foldername = folderBrowserDialog1->SelectedPath;
		std::string imgs_path_temp = msclr::interop::marshal_as<std::string>(foldername);
		
		//To use imread, \\ is required instead of \
		//So we first find the position(index) of \ and add one more \ to apply imread
		int index = 0;
		vector<int> index_arr;
		while ((index = imgs_path_temp.find("\\", index)) != std::string::npos)
		{
			index_arr.push_back(index);
			index += 1;
		}
		//Add one more \ to the position where there was only one \. Then, since the position is pushed in the process of adding one \, +index is required. 
		for (int index = 0; index < index_arr.size(); index++)
		{
			imgs_path_temp = imgs_path_temp.insert(index_arr[index]+index, "\\");
		}
		//Set the image file name to contain only numbers, and currently only .png files can be loaded. 
		string imgs_path = imgs_path_temp + "\\\\*.png";

		vector<string> filenames;				//Import the names of the images in the folder and put them in filenames
		cv::glob(imgs_path, filenames, false);	//Sort the names of the imported images
		SI::natural::sort(filenames);			//To prevent loading files in the order 1, 10, 2, 3,..., use natural sort

		int count = filenames.size();			//The number of images in the folder
		System::String^ file_count = count.ToString();
	
		//Set images
		Mat* imgs = new Mat[count]; 
		Mat resize_img;
		Mat resize_img1;

		Mat mea1 = imread("MEA_ElectrodesforDMD.png", IMREAD_COLOR);
		
		Mat bg1(dmdy, dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));

		//Send trigger to Arduino
		serialPort1->Open();
		//serialPort1->Write("<" + textBox7->Text + "," + textBox8->Text + "," + file_count + ">");		//Trigger_2023Ver
		//serialPort1->Close();																			//Trigger_2023Ver


		for (int i = 0; i < count; i++)
		{
			imgs[i] = imread(filenames[i], IMREAD_COLOR);
			
			//Create resized & rotated image
			int rot_img_ang = img_ang + 90;
			cv::Point center = cv::Point((imgs[i].cols - 1) / 2, (imgs[i].rows - 1) / 2);

			Mat rot_img = getRotationMatrix2D(center, rot_img_ang, 1);
			Rect2f bbox = cv::RotatedRect(cv::Point(), imgs[i].size(), rot_img_ang).boundingRect2f();
			rot_img.at<double>(0, 2) += bbox.width / 2.0 - imgs[i].cols / 2.0;
			rot_img.at<double>(1, 2) += bbox.height / 2.0 - imgs[i].rows / 2.0;

			warpAffine(imgs[i], resize_img, rot_img, bbox.size());

			resize(resize_img, resize_img, cv::Size(size*2, size*2));
			resize_img.convertTo(resize_img, -1, contrast, bright);
			
			//Image shown on MEA
			rotate(resize_img, resize_img1, ROTATE_90_CLOCKWISE);
			resize_img1.convertTo(resize_img1, -1, contrast, bright);

			//Copy the modified image to mat
			resize_img.copyTo(bg1(cv::Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size))));
			resize_img1.copyTo(mea1(cv::Rect(cv::Point(xpos - size, ypos - size), cv::Point(xpos + size, ypos + size))));

			if (ref_time == 0)
			{
				serialPort1->Write("<1,0,1>");			//Trigger_2024Ver
				imshow("DMD_PATTERN", bg1);
				imshow("TV_PATTERN", mea1);
				waitKey(stim_time);

			}
			else
			{
				serialPort1->Write("<1,0,1>");			//Trigger_2024Ver
				imshow("DMD_PATTERN", bg1);
				imshow("TV_PATTERN", mea1);
				waitKey(stim_time);
				
				serialPort1->Write("<1,0,1>");			//Trigger_2024Ver
				imshow("DMD_PATTERN", bg);
				imshow("TV_PATTERN", mea);
				waitKey(ref_time);
				
			}
			
		}
		serialPort1->Close();							//Trigger_2024Ver
	}

	//After stimulation
	imshow("DMD_PATTERN", bg);
	imshow("TV_PATTERN", mea);
	waitKey(0);
	

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//button5 - video stimulus
	
	//Set video
	Mat vid;
	Mat resize_vid;
	Mat bg1(dmdy, dmdx, CV_8UC3, Scalar(bgc, bgc, bgc));

	//Set video's size
	int size = Convert::ToInt32(textBox4->Text);

	//Set video's position
	int xpos = Convert::ToInt32(textBox5->Text);
	int ypos = Convert::ToInt32(textBox6->Text);

	//Set video's angle
	int vid_ang = Convert::ToInt32(textBox14->Text);

	//Opening video by using file dialog
	openFileDialog2->Filter = "All files (*.*) |*.*| .avi,.mp4 Files | *.avi;*.mp4";
	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		const cv::String video_file = msclr::interop::marshal_as<std::string>(openFileDialog2->FileName);
		VideoCapture video_stim;
		video_stim.open(video_file);

		if (!video_stim.isOpened())
		{
			MessageBox::Show("Can't open this video!");
		}

		float videoFPS = video_stim.get(cv::CAP_PROP_FPS);
		int delay = cvRound(1000 / videoFPS);		//Time interval between each frame in the video

		auto video_start = std::chrono::system_clock::now();
		while (1)
		{
			auto start = std::chrono::system_clock::now();
			video_stim >> vid;
			
			if (vid.empty())
			{
				//MessageBox::Show("Video frame end\n");
				break;
			}
			
			cv::Point center = cv::Point((vid.cols - 1) / 2, (vid.rows - 1) / 2);

			Mat rot_vid = getRotationMatrix2D(center, vid_ang, 1);
			Rect2f bbox = cv::RotatedRect(cv::Point(), vid.size(), vid_ang).boundingRect2f();
			rot_vid.at<double>(0, 2) += bbox.width / 2.0 - vid.cols / 2.0;
			rot_vid.at<double>(1, 2) += bbox.height / 2.0 - vid.rows / 2.0;

			warpAffine(vid, resize_vid, rot_vid, bbox.size());

			resize(resize_vid, resize_vid, cv::Size(size, size));
			resize_vid.copyTo(bg1(cv::Rect(cv::Point(xpos - size / 2, ypos - size / 2), cv::Point(xpos + size / 2, ypos + size / 2))));


			imshow("DMD_PATTERN", bg1);
			waitKey(delay);

			auto end = std::chrono::system_clock::now();
			
			std::chrono::duration<double> diff = end - start;		//Acutual interval between frames [sec]
			double diff1 = diff.count() * 1000;						//Acutual interval between frames [msec]
		}
		auto video_end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff_video = video_end - video_start; //Total video playback time [sec]
		double diff_video_msec = diff_video.count() * 1000;					//Total video playback time [msec]
		int diff_video_msec_around = cvRound(diff_video_msec);

		//Send trigger to Arduino
		serialPort1->Open();
		serialPort1->Write("<" + diff_video_msec_around.ToString() + ",0,1>");		//Trigger_2023Ver
		serialPort1->Close();
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	destroyAllWindows();
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) 
{	
	///Make Window for DMD
	namedWindow("DMD_PATTERN", WINDOW_NORMAL);
	moveWindow("DMD_PATTERN", dmdx_start, dmdy_start);
	setWindowProperty("DMD_PATTERN", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);

	///To show how the stimulation looks on the MEA
	//Make window for TV
	namedWindow("TV_PATTERN", WINDOW_NORMAL);
	moveWindow("TV_PATTERN", tvx_start, tvy_start);
	resizeWindow("TV_PATTERN", 1280, 720);

	imshow("DMD_PATTERN", bg);
	imshow("TV_PATTERN", mea);
	waitKey(1);
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//To check inputs of spot stimulus
	this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox4->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox8->BackColor = System::Drawing::SystemColors::Control;
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//To check inputs of square stimulus
	this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox4->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox8->BackColor = System::Drawing::SystemColors::Control;
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//To check inputs of moving bar stimulus
	this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox2->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox5->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//To check inputs of images stimulus
	this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox4->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));


}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e)
{
	//To check inputs of video stimulus
	this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
	this->groupBox5->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox4->BackColor = System::Drawing::SystemColors::Control;
	this->groupBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
		static_cast<System::Int32>(static_cast<System::Byte>(93)));
}

};
}
