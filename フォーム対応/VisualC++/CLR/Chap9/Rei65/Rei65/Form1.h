#pragma once
#include "clrformh.h"
int man,computer,M=0,judge;
int table[3][3]={{0,0,0},    /* 戦略テーブル */
                 {0,0,0},
                 {0,0,0}},
    hist[3]={0,0,0};    /* 勝敗の度数 */
char *hand[3]={"グー","チョキ","パー"};
namespace Rei65 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"0:グー　1:チョキ  2:パー";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(28, 19);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 19);
			this->button1->TabIndex = 2;
			this->button1->Text = L"じゃんけん";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(17, 65);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(181, 87);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * -------------------------------
 *      戦略を持つじゃんけん     *
 * -------------------------------
 */

#include "clrform.h"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	tinit();cls();
	if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
        computer=2;
    else if (table[M][1]>table[M][2])
        computer=0;
    else
        computer=1;

	man=stoi(textBox1->Text);
    printf("コンピュータの手 %s\n",hand[computer]);

    judge=(computer-man+3)%3;
    switch (judge){
        case 0: printf("ひきわけ\n");break;
        case 1: printf("あなたの勝ち\n");break;
        case 2: printf("コンピュータの勝ち\n");break;
    }
    hist[judge]++;
    table[M][man]++;        /* 学習 */
    M=man;
    printf("--- %d勝%d敗%d分 ---\n\n",hist[1],hist[2],hist[0]);

			 }
	};
}

