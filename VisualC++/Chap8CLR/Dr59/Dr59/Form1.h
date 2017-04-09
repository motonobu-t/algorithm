#pragma once
#include <math.h>
struct {
	int f;
	double x,y,z;
} a[]
	      ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
	        1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
	        -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
	        -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
	        -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
	        1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
	        -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
	        1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
	        -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
	        1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0 };

namespace Dr59 {

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

	protected: 

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * -------------------
 *      透視変換     *
 * -------------------
 */
#include "clrglib.h"
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		double ay=-35*3.14159/180,    /* ｙ軸回りの回転角 */
	           vp=-300.0,             /* 投影中心 */
	           l=-25.0,               /* ｘ方向の移動量 */
	           m=-70.0,               /* ｙ方向の移動量 */
	           n=0.0,                 /* ｚ方向の移動量*/
	           h,px,py;
		int k;

		ginit(); cls();
		window(-320,-200,320,200);
		for (k=0;a[k].f!=-999;k++){
                                              /* 透視変換 */
			h=-a[k].x*sin(ay)/vp+a[k].z*cos(ay)/vp+n/vp+1;
			px=(a[k].x*cos(ay)+a[k].z*sin(ay)+l)/h;
			py=(a[k].y+m)/h;

			if (a[k].f==-1)
				setpoint(px,py);
			else
				moveto(px,py);
		}

			 }
	};
}

