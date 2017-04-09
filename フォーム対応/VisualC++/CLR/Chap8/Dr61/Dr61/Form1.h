#pragma once
#include "clrformh.h"

namespace Dr61 {

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
			this->button1->Location = System::Drawing::Point(10, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"描画";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(15, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(585, 414);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(621, 470);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * --------------------------------
 *      ３次元関数の陰線処理      *
 * --------------------------------
 */

#include "clrform.h"

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int ymin[640],ymax[640];
    int k,px,py;
    double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

    ginit(); cls();
    for (k=0;k<640;k++){        /* 最大・最小判定配列 */
        ymin[k]=399;ymax[k]=0;
    }
    cos_x=cos(30*rd);  sin_x=sin(30*rd);
    cos_y=cos(-30*rd); sin_y=sin(-30*rd);
    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x++){
            y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
            px=(int)(x*cos_y+z*sin_y+320);              /* 回転変換 */
            py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
            if (py<ymin[px]){               /* 今までの最小より小さい */
                ymin[px]=py;pset(px,py);
            }
            if (py>ymax[px]){               /* 今までの最大より大きい */
                ymax[px]=py;pset(px,py);
            }
        }
    }

			 }
	};
}

