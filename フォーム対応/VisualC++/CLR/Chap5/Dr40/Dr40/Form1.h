#pragma once
#include "clrformh.h"
struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head=NULL;

namespace Dr40 {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"名前";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"電話";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 12);
			this->label3->TabIndex = 2;
			this->label3->Text = L"キー";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(53, 10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 19);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(53, 36);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(90, 19);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(53, 66);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(90, 19);
			this->textBox3->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(149, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 21);
			this->button1->TabIndex = 6;
			this->button1->Text = L"登録（再登録不可）";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(149, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 19);
			this->button2->TabIndex = 7;
			this->button2->Text = L"登録の終了";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(8, 100);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(247, 22);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(149, 67);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 18);
			this->button3->TabIndex = 9;
			this->button3->Text = L"探索";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * -----------------------------------------
 *      自己再編成探索（１つ前に移す）     *
 * -----------------------------------------
 */

#include "clrform.h"
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tfield *p;
	p=talloc();
	stoc(textBox1->Text,p->name);
	stoc(textBox2->Text,p->tel);
    p->pointer=head;
    head=p;

			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tfield *p;
	p=talloc();               /* ダミー・ノード */
    p->pointer=head;
    head=p;

			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
    char key[20];
    struct tfield *p,*old1,*old2,*q;
	stoc(textBox3->Text,key);
	p=head->pointer;
    old1=old2=head;
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            printf("%15s%15s\n",p->name,p->tel);
            if (p!=head->pointer){       /* 先頭でないときに */
                q=old1->pointer;         /* １つ前と交換     */
                old1->pointer=p;
                old2->pointer=p->pointer;
                p->pointer=q;
            }
            break;
        }
        old1=old2;
        old2=p;
        p=p->pointer;
    }
			 }
};
}

