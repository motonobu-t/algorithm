#pragma once
#include <math.h>

namespace Dr57 {

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
 * ------------------------
 *     ２次元回転変換     *
 * ------------------------
 */
#include "clrglib.h"

void multi(double factx,double facty,double *x,double *y)
{
	*x=factx*(*x);
	*y=facty*(*y);
}

void rotate(double deg,double *x,double *y)	/* 回転変換 */
{
	double dx,dy,rd=3.14159/180;
	dx=(*x)*cos(deg*rd)-(*y)*sin(deg*rd);
	dy=(*x)*sin(deg*rd)+(*y)*cos(deg*rd);
	*x=dx; *y=dy;
}
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		double x[]={0,100,100,  0,0},
			   y[]={0,  0,200,200,0};
		int j,k,n=5;

		ginit(); cls(); window(-320,-200,320,200);

		for (j=0;j<12;j++){
			for (k=0;k<n;k++){
				multi(.8,.8,&x[k],&y[k]);
				rotate(30,&x[k],&y[k]);
				if (k==0)
					setpoint(x[k],y[k]);
				else
					moveto(x[k],y[k]);

			}
		}

			 }
};
}

