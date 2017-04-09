#pragma once
#include "clrformh.h"
#define MaxSize 100     /* キュー・サイズ */
int queue[MaxSize];     /* キュー */
int head=0,             /* 先頭データへのポインタ */
    tail=0;             /* 終端データへのポインタ */

namespace Dr33 {

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(7, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(38, 19);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 19);
			this->button1->TabIndex = 1;
			this->button1->Text = L"queuein";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 9);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(63, 19);
			this->button2->TabIndex = 2;
			this->button2->Text = L"queueout";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(195, 8);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 19);
			this->button3->TabIndex = 3;
			this->button3->Text = L"disp";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(9, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(248, 91);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * -----------------------------
 *      キュー（待ち行列）     *
 * -----------------------------
 */

#include "clrform.h"
int queuein(int n)     /* キューにデータを入れる手続き */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* キューが一杯のとき */
}
int queueout(int *n)    /* キューからデータを取り出す手続き */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* キューが空のとき */
}
void disp(void)        /* 待ち行列の内容を表示する手続き */
{
    int i;

    i=head;
    while (i!=tail){
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 int n;
			 n=stoi(textBox1->Text);
			 tinit();cls();
             if (queuein(n)==-1)
                 printf("待ち行列が一杯です\n");

			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			int n;
			tinit();cls();
			if (queueout(&n)==-1)
                 printf("待ち行列は空です\n");
            else
                 printf("queue data --> %d\n",n);
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			tinit();cls();
			disp();
			 }
};
}

