#pragma once
#include "clrformh.h"
#define N 3     /* 元の数 */

namespace Dr15_1 {

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
			this->button1->Location = System::Drawing::Point(13, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 52);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(159, 61);
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
 * ---------------------------------------------
 *      連立方程式の解法（ピボット選択法）     *
 * ---------------------------------------------
 */

#include "clrform.h"

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d,max,dumy;
    int i,j,k,s;
	tinit();cls();
    for (k=0;k<N;k++){
        max=0;s=k;
        for(j=k;j<N;j++){
            if (fabs(a[j][k])>max){
                max=fabs(a[j][k]);s=j;
            }
        }
        if (max==0){
            printf("解けない");
            exit(1);
        }
        for (j=0;j<=N;j++){
            dumy=a[k][j];
            a[k][j]=a[s][j];
            a[s][j]=dumy;
        }

        p=a[k][k];              /* ピボット係数 */
        for (j=k;j<N+1;j++)        /* ピボット行をｐで割る */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){      /* ピボット列の掃き出し */
            if (i!=k){
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);

			 }
	};
}

