#pragma once
#include "clrformh.h"
#define N1 4     /* 行数 */
#define N2 6     /* 列数 */
#define N3 2     /* 変数の数 */

namespace Rei16 {

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
			this->button1->Location = System::Drawing::Point(12, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(182, 49);
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
 * ---------------------------------------------------------
 *      線形計画法（Ｌｉｎｅａ　Ｐｒｏｇｒａｍｉｎｇ）     *
 * ---------------------------------------------------------
 */

#include "clrform.h"

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    double a[N1][N2]={{1.0,2.0,1.0,0.0,0.0,14.0  },
                      {1.0,1.0,0.0,1.0,0.0,8.0   },
                      {3.0,1.0,0.0,0.0,1.0,18.0  },
                      {-2.0,-3.0,0.0,0.0,0.0,0.0}};
    double min,p,d;
    int j,k,x,y,flag;

    while (1){
        min=9999;           /* 列選択 */
        for (k=0;k<N2-1;k++){
            if (a[N1-1][k]<min){
                min=a[N1-1][k];
                y=k;
            }
        }

        if (min>=0)
            break;

        min=9999;           /* 行選択 */
        for (k=0;k<N1-1;k++){
            p=a[k][N2-1]/a[k][y];
            if (a[k][y]>0 && p<min){
                min=p;
                x=k;
            }
        }
        p=a[x][y];              /* ピボット係数 */
        for (k=0;k<N2;k++)      /* ピボット行をｐで割る */
            a[x][k]=a[x][k]/p;
        for (k=0;k<N1;k++){     /* ピボット列の掃き出し */
            if (k!=x){
                d=a[k][y];
                for (j=0;j<N2;j++)
                    a[k][j]=a[k][j]-d*a[x][j];
            }
        }
    }
	tinit();cls();
    for (k=0;k<N3;k++){
        flag=-1;
        for (j=0;j<N1;j++){
            if (a[j][k]==1)
                flag=j;
        }
        if (flag!=-1)
            printf("x%d = %f\n",k,a[flag][N2-1]);
        else
            printf("x%d = %f\n",k,0);
    }
    printf("z= %f\n",a[N1-1][N2-1]);

			 }
	};
}

