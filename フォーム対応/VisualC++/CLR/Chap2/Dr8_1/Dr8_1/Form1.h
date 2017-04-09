#pragma once
#include "clrformh.h"
#define N 1000             /* 乱数の発生回数 */
#define M 10               /* 整数乱数の範囲 */
#define F (N/M)            /* 期待値 */
#define SCALE (40.0/F)     /* ヒストグラムの高さ（自動スケール） */

unsigned rndnum=13;        /* 乱数の初期値 */

namespace Dr8_1 {

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
			this->button1->Location = System::Drawing::Point(6, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 22);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(7, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(455, 223);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 338);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * ----------------------
 *     一様性の検定　   *
 * ----------------------
 */

#include "clrform.h"


unsigned irnd(void)        /* 0～32767の整数乱数 */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0～1未満の実数乱数 */
{
    return irnd()/32767.1;
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i,j,rank,hist[M+1];
    double ee=0.0;	// eは引数にあるのでeeとした

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1～Mの乱数を１つ発生 */
        hist[rank]++;
    }
	tinit();cls();
    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* ヒストグラムの表示 */
            printf("*");
        printf("\n");

        ee=ee+(double)(hist[i]-F)*(hist[i]-F)/F;        /* χ2の計算 */
    }
    printf("χ2=%f\n",ee);
			 }
	};
}

