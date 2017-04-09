#pragma once
#include <math.h>

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
 * --------------------------------
 *      ３次元関数の陰線処理      *
 * --------------------------------
 */
#include "clrglib.h"
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
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

