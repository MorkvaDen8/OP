#pragma once
#include <msclr/marshal_cppstd.h>
#include "PhoneNumber.h"

namespace Laba7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ NumberText1;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ NumberText2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ NumberText3;
	private: System::Windows::Forms::Button^ button2;


	protected:

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
			this->NumberText1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->NumberText2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NumberText3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// NumberText1
			// 
			this->NumberText1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->NumberText1->Location = System::Drawing::Point(105, 33);
			this->NumberText1->Name = L"NumberText1";
			this->NumberText1->Size = System::Drawing::Size(213, 20);
			this->NumberText1->TabIndex = 0;
			this->NumberText1->TabStop = false;
			this->NumberText1->Text = L"+38(0XX)XXX-XX-XX";
			this->NumberText1->Enter += gcnew System::EventHandler(this, &MyForm::NumberText_Enter);
			this->NumberText1->Leave += gcnew System::EventHandler(this, &MyForm::NumberText_Leave);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Number 1:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 138);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Number 2:";
			// 
			// NumberText2
			// 
			this->NumberText2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->NumberText2->Location = System::Drawing::Point(105, 65);
			this->NumberText2->Name = L"NumberText2";
			this->NumberText2->Size = System::Drawing::Size(213, 20);
			this->NumberText2->TabIndex = 4;
			this->NumberText2->TabStop = false;
			this->NumberText2->Text = L"+38(0XX)XXX-XX-XX";
			this->NumberText2->Enter += gcnew System::EventHandler(this, &MyForm::NumberText2_Enter);
			this->NumberText2->Leave += gcnew System::EventHandler(this, &MyForm::NumberText2_Leave);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Search Number:";
			// 
			// NumberText3
			// 
			this->NumberText3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->NumberText3->Location = System::Drawing::Point(105, 96);
			this->NumberText3->Name = L"NumberText3";
			this->NumberText3->Size = System::Drawing::Size(213, 20);
			this->NumberText3->TabIndex = 6;
			this->NumberText3->TabStop = false;
			this->NumberText3->Text = L"+38(0XX)XXX-XX-XX";
			this->NumberText3->Enter += gcnew System::EventHandler(this, &MyForm::NumberText3_Enter);
			this->NumberText3->Leave += gcnew System::EventHandler(this, &MyForm::NumberText3_Leave);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(210, 138);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 33);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::ButtonClear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 220);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->NumberText3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->NumberText2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->NumberText1);
			this->Name = L"MyForm";
			this->Text = L"Number Search";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void NumberText_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText1->Text == "+38(0XX)XXX-XX-XX") {
			NumberText1->Text = "";
			NumberText1->ForeColor = Color::Black;
		}
	}
	private: System::Void NumberText_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText1->Text == "") {
			NumberText1->Text = "+38(0XX)XXX-XX-XX";
			NumberText1->ForeColor = SystemColors::WindowFrame;
		}
	}

	private: System::Void NumberText2_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText2->Text == "+38(0XX)XXX-XX-XX") {
			NumberText2->Text = "";
			NumberText2->ForeColor = Color::Black;
		}
	}
	private: System::Void NumberText2_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText2->Text == "") {
			NumberText2->Text = "+38(0XX)XXX-XX-XX";
			NumberText2->ForeColor = SystemColors::WindowFrame;
		}
	}
	private: System::Void NumberText3_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText3->Text == "+38(0XX)XXX-XX-XX") {
			NumberText3->Text = "";
			NumberText3->ForeColor = Color::Black;
		}
	}
	private: System::Void NumberText3_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (NumberText3->Text == "") {
			NumberText3->Text = "+38(0XX)XXX-XX-XX";
			NumberText3->ForeColor = SystemColors::WindowFrame;
		}
	}
	private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string text1 = msclr::interop::marshal_as<std::string>(NumberText1->Text);
		std::string text2 = msclr::interop::marshal_as<std::string>(NumberText2->Text);
		std::string text3 = msclr::interop::marshal_as<std::string>(NumberText3->Text);

		try {
			PhoneNumber number1(text1);
			PhoneNumber number2(text2);
			std::string numb1 = number1.GetNumber(); 
			std::string numb2 = number2.GetNumber();
			std::string numb3 = text3;

			if ((numb3.length() > 17 || numb3[0] != '+' || !isdigit(numb3[1]) || !isdigit(numb3[2]) ||
				numb3[3] != '(' || !isdigit(numb3[4]) || !isdigit(numb3[5]) || !isdigit(numb3[6]) ||
				numb3[7] != ')' || !isdigit(numb3[8]) || !isdigit(numb3[9]) || !isdigit(numb3[10]) || 
				numb3[11] != '-' || !isdigit(numb3[12]) || !isdigit(numb3[13]) || 
				numb3[14] != '-' || !isdigit(numb3[15]) || !isdigit(numb3[16])) ||

				(numb2.length() > 17 || numb2[0] != '+' || !isdigit(numb2[1]) || !isdigit(numb2[2]) ||
				numb2[3] != '(' || !isdigit(numb2[4]) || !isdigit(numb2[5]) || !isdigit(numb2[6]) ||
				numb2[7] != ')' || !isdigit(numb2[8]) || !isdigit(numb2[9]) || !isdigit(numb2[10]) ||
				numb2[11] != '-' || !isdigit(numb2[12]) || !isdigit(numb2[13]) ||
				numb2[14] != '-' || !isdigit(numb2[15]) || !isdigit(numb2[16])) 

				||(numb1.length() > 17 || numb1[0] != '+' || !isdigit(numb1[1]) || !isdigit(numb1[2]) ||
				numb1[3] != '(' || !isdigit(numb1[4]) || !isdigit(numb1[5]) || !isdigit(numb1[6]) ||
				numb1[7] != ')' || !isdigit(numb1[8]) || !isdigit(numb1[9]) || !isdigit(numb1[10]) ||
				numb1[11] != '-' || !isdigit(numb1[12]) || !isdigit(numb1[13]) ||
				numb1[14] != '-' || !isdigit(numb1[15]) || !isdigit(numb1[16])))
			{
				throw "Wrong format";
			}

			if (numb3[1] != '3' || numb3[2] != '8' || numb2[1] != '3' || numb2[2] != '8' || numb1[1] != '3' || numb1[2] != '8') {
				throw 380;
			}

			if ((numb3 != number2.GetNumber()) && (numb3 != number1.GetNumber())) {
				MessageBox::Show("The specified number was not found!");
			}
			else {
				MessageBox::Show("The specified number has been found.");
			}
		}

		catch (const char* ex) {
			MessageBox::Show("Invalid number format!(+38(0XX)XXX-XX-XX)", "Error");
		}
		catch (int ex) {
			MessageBox::Show("This is a number from another country!(Not Ukraine +380)" , "Error");
		}
	}

private: System::Void ButtonClear_Click(System::Object^ sender, System::EventArgs^ e) {
	NumberText1->Text = "";
	NumberText2->Text = "";
	NumberText3->Text = "";
	NumberText1->Text = "+38(0XX)XXX-XX-XX";
	NumberText1->ForeColor = SystemColors::WindowFrame;
	NumberText2->Text = "+38(0XX)XXX-XX-XX";
	NumberText2->ForeColor = SystemColors::WindowFrame;
	NumberText3->Text = "+38(0XX)XXX-XX-XX";
	NumberText3->ForeColor = SystemColors::WindowFrame;
}
};
}
