#pragma once
#include "Form2.h"
#include <wchar.h>
#include <locale.h>
#include <vcclr.h >

#define Max 100
#define nil -1
struct tnode {
    int left;      /* 左へのポインタ */
    wchar_t node[30];  /* 構造体メンバにString^は使えない */
    int right;     /* 右へのポインタ */
};
struct tnode a[Max]={{1  ,L"芸能人ですか"  ,2},
                     {3  ,L"歌手ですか"    ,4},
                     {nil,L"吉田　茂"      ,nil},
                     {nil,L"井上　陽水"    ,nil},
                     {5  ,L"女優ですか"    ,6},
                     {nil,L"中山　美穂"    ,nil},
                     {nil,L"久米 宏"       ,nil}};
int lp=6;

namespace Rei50 {

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"知的データべースの開始";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * ---------------------------------------
 *      質疑応答と決定木（配列表現）     *
 * ---------------------------------------
 */

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Form2^ f=gcnew Form2();  // 入力用ダイアログボックス
	int p;
	System::Windows::Forms::DialogResult c;
	pin_ptr<const wchar_t> wc;
	setlocale(LC_ALL,"");
	do {
        p=0;
        while (a[p].left!=nil){          /* 木のサーチ */
			c=MessageBox::Show(gcnew String(a[p].node),"",System::Windows::Forms::MessageBoxButtons::YesNo);
			if (c==System::Windows::Forms::DialogResult::Yes)
                p=a[p].left;
            else
                p=a[p].right;
        }
		c=MessageBox::Show(gcnew String(a[p].node),"",System::Windows::Forms::MessageBoxButtons::YesNo);

        if (c==System::Windows::Forms::DialogResult::No){               /* 学習機能 */
            a[lp+1]=a[p];                    /* ノードの移動 */
                                           /* 新しいノードの作成 */
			f->label1->Text="あなたの考えは";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(a[lp+2].node,L"%s",wc);
            a[lp+2].left=a[lp+2].right=nil;
                                            /* 質問ノードの作成 */
			f->label1->Text=gcnew String(a[lp+1].node)+"と"+gcnew String(a[lp+2].node)+"を区別する質問は";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(a[p].node,L"%s",wc);
			c=MessageBox::Show("ｙｅｓの項目は"+gcnew String(a[lp+1].node)+"で良いですか","",System::Windows::Forms::MessageBoxButtons::YesNo);
            if (c==System::Windows::Forms::DialogResult::Yes){          /* 子の接続 */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
	} while (c=MessageBox::Show("続けますか","",System::Windows::Forms::MessageBoxButtons::YesNo),c==System::Windows::Forms::DialogResult::Yes);

			 }
	};
}

