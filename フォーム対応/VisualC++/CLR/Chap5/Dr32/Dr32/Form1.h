#pragma once
#include "clrformh.h"
int pie[20][3];        /* 20:円盤の最大枚数, 3:棒の数 */
int sp[3],N;           /* スタック・ポインタ */
namespace Dr32 {

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(112, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"円盤の枚数";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(33, 19);
			this->textBox1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(9, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(265, 200);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * ---------------------------------------------
 *      ハノイの塔（シミュレ－ション付き）     *
 * ---------------------------------------------
 */

#include "clrform.h"
void hanoi(int n,int a,int b,int c)  /* 再帰手続 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void move(int n,int s,int d)        /* 円盤の移動シミュレーション */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ｓ－＞ｄへ円盤の移動 */
    sp[d]++;                        /* スタック・ポインタの更新 */
    sp[s]--;
	printf("\n");
    printf("%d 番の円盤を %c-->%c に移す\n\n",n,'a'+s,'a'+d);
    for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
	printf("\n");
    printf("       a       b       c\n");
	MessageBox::Show("次へ");
	cls();
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i;
	N=stoi(textBox1->Text);
    for (i=0;i<N;i++)               /* 棒ａに円盤を積む */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* スタック・ポインタの初期設定 */
	tinit();cls();
    hanoi(N,0,1,2);
			 }
	};
}

