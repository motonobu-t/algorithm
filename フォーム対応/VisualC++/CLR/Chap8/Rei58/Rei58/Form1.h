#pragma once
#include "clrformh.h"

namespace Rei58 {

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
			this->button1->Location = System::Drawing::Point(12, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(570, 433);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 483);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * --------------------
 *       対称模様     *
 * --------------------
 */

#include "clrform.h"

#define N 9     /* データ数 */

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
    int a,b,j,k;
    double rd=3.14159/180,
           m,h,vy,vx,px,py;

    ginit(); cls();
    m=70.0; h=m*sqrt(3.0)/2;      /* 正３角形の辺の長さ、高さ */
    window(-m/2,-h/3,m/2,h*2/3);
    b=1;
    for (vy=0.0;vy<=310.0;vy=vy+h){
        a=1;
        for (vx=50.0;vx<=500.0;vx=vx+m/2){
            view(vx,vy,vx+m,vy+h);        /* ビューポートの設定 */
            for (j=0;j<3;j++){
                for (k=0;k<N;k++){
                    px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
                    py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
                    if (a*b==-1)
                        py=-py+h/3;        /* 逆像補正 */
                    if (k==0)
                        setpoint(px,py);
                    else
                        moveto(px,py);
                }
            }
            a=-a;
        }
        b=-b;
    }

			 }
	};
}

