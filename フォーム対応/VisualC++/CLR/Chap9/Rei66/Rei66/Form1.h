#pragma once
#include "clrformh.h"
#define N 8
int column[N+1],    /* 同じ欄に王妃が置かれているかを表す*/
    rup[2*N+1],     /* 右上がりの対角線上に置かれているかを表す */
    lup[2*N+1],     /* 左上がりの対角線上に置かれているかを表す */
    queen[N+1];     /* 王妃の位置 */
namespace Rei66 {

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
			this->button1->Location = System::Drawing::Point(11, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(15, 49);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(225, 146);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * -----------------------------------------
 *      八王妃（８Ｑｕｅｅｎｓ）の問題     *
 * -----------------------------------------
 */

#include "clrform.h"
void backtrack(int i)
{
    int j,x,y;
    static int num=0;
    if (i>N){
        printf("解 %d \n",++num);        /* 解の表示 */
        for (y=1;y<=N;y++){
            for (x=1;x<=N;x++)
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            printf("\n");
        }
		MessageBox::Show("次の移動");  // 次の移動まで待つ
		cls();
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* （ｉ，ｊ）が王妃の位置 */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* 局面の変更 */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* 局面の戻し */
            }
        }
    }
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
	tinit();cls();
    backtrack(1);

			 }
	};
}

