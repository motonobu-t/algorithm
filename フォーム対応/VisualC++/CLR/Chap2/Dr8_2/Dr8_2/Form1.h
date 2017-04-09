#pragma once
#include "clrformh.h"

namespace Dr8_2 {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(11, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(376, 320);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(399, 378);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * -------------------------------------------
 *      正規乱数（ボックス・ミュラー法）     *
 * -------------------------------------------
 */

#include "clrform.h"
void brnd(double sig,double m,double *x,double *y)
{
    double r1,r2;
    r1=rand()/(RAND_MAX+0.1); r2=rand()/(RAND_MAX+0.1);
    *x=sig*sqrt(-2*log(r1))*cos(2*3.14159*r2)+m;
    *y=sig*sqrt(-2*log(r1))*sin(2*3.14159*r2)+m;
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i,j,hist[100];
    double x,y;

    for (i=0;i<100;i++)
        hist[i]=0;

    for (i=0;i<1000;i++){
        brnd(2.5,10.0,&x,&y);
        hist[(int)x]++;
        hist[(int)y]++;
    }
	tinit();cls();
    for (i=0;i<=20;i++){            /* ヒスト・グラムの表示 */
        printf("%3d : I ",i);
        for (j=1;j<=hist[i]/10;j++){
            printf("*");
        }
        printf("\n");
    }
			 }
	};
}

