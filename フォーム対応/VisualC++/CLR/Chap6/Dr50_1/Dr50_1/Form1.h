#pragma once
#include "Form2.h"
#include "stdlib.h"
#include <wchar.h>
#include <locale.h>
#include <vcclr.h >
struct tnode {
    struct tnode *left;  /* 左へのポインタ */
    wchar_t node[30];      /* 動的メモリ割り当てを行うため固定長配列 */
    struct tnode *right; /* 右へのポインタ */
};
struct tnode *root;


namespace Dr50_1 {

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
			this->button1->Location = System::Drawing::Point(22, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"知的データベースの開始";
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
 *      質疑応答と決定木（動的表現）     *
 * ---------------------------------------
 */
struct tnode *talloc(void)            /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tnode *p,*q1,*q2;
	Form2^ f=gcnew Form2();  // 入力用ダイアログボックス
	System::Windows::Forms::DialogResult c;
	pin_ptr<const wchar_t> wc;
	setlocale(LC_ALL,"");
    root=talloc();
	f->label1->Text="初期ノード ? ";
	f->textBox1->Text="";
	f->ShowDialog();
	wc=PtrToStringChars(f->textBox1->Text);
	swprintf(root->node,L"%s",wc);
	root->left=root->right=NULL;
    do {
        p=root;                             /* 木のサーチ */
        while (p->left!=NULL){
			c=MessageBox::Show(gcnew String(p->node),"",System::Windows::Forms::MessageBoxButtons::YesNo);
			if (c==System::Windows::Forms::DialogResult::Yes)
                p=p->left;
            else
                p=p->right;
        }
		c=MessageBox::Show(gcnew String(p->node),"",System::Windows::Forms::MessageBoxButtons::YesNo);

        if (c==System::Windows::Forms::DialogResult::No){               /* 学習機能 */
            q1=talloc(); *q1=*p;        /* ノードの移動 */

            q2=talloc();                /* 新しいノードの作成 */
			f->label1->Text="あなたの考えは";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(q2->node,L"%s",wc);
            q2->left=q2->right=NULL;
                                        /* 質問ノードの作成 */
			f->label1->Text=gcnew String(q1->node)+"と"+gcnew String(q2->node)+"を区別する質問は";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(p->node,L"%s",wc);
			c=MessageBox::Show("ｙｅｓの項目は"+gcnew String(q1->node)+"で良いですか","",System::Windows::Forms::MessageBoxButtons::YesNo);
            if (c==System::Windows::Forms::DialogResult::Yes){          /* 子の接続 */

                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (c=MessageBox::Show("続けますか","",System::Windows::Forms::MessageBoxButtons::YesNo),c==System::Windows::Forms::DialogResult::Yes);

			 }
	};
}

