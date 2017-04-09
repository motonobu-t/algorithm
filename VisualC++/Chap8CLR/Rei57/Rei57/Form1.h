#pragma once
#include <math.h>

namespace Rei57 {

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
 *      対称移動     *
 * -------------------
 */

#include "clrglib.h"
void mirror(int flag,double m,double *dat)    /* 対称移動 */
{
    int i;
    for (i=1;i<=2*dat[0];i=i+2){    /* dat[0]はデータ数 */
        if (flag==1)                /* ｙ軸中心 */
            dat[i]=2*m-dat[i];
        if (flag==0)                /* ｘ軸中心 */
            dat[i+1]=2*m-dat[i+1];
    }
}
void draw(double *dat)              /* 図形の描画 */
{
    int i;
    setpoint(dat[1],dat[2]);        /* 始点 */
    for (i=3;i<=2*dat[0];i=i+2)     /* dat[0]はデータ数 */
        moveto(dat[i],dat[i+1]);
}

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	    double a[]={11,0,80,5,75,17,80,20,60,15,55,0,55,
					 0,20,10,40,20,40,10,20,0,20};
		ginit(); cls(); window(-160,-100,160,100);

		draw(a);
		mirror(1,0.0,a);draw(a);
		mirror(0,0.0,a);draw(a);
		mirror(1,0.0,a);draw(a);

			 }
	};
}

