#pragma once
#include "clrformh.h"
#define N 8                            /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},  /* 隣接行列 */
                 {0,0,1,1,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,1,1,0,0,1,0,0,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,1,1,0,0,0,0},
                 {0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                            /* 訪問フラグ */
namespace Dr51_2 {

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
			this->button1->Location = System::Drawing::Point(12, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 56);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(252, 93);
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
 *      非連結グラフの探索（深さ優先）     *
 * -----------------------------------------
 */
#include "clrform.h"
void visit(int i)
{
    int j;

    printf("%d ",i);
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
    }
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i,count=1;    /* 連結成分のカウント用 */
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++){
        if (v[i]!=1){
            printf("%d :",count++);
            visit(i);
            printf("\n");
        }
    }
			 }
	};
}

