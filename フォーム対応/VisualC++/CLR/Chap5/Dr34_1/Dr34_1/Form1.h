#pragma once
#include "clrformh.h"
struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head,*old;
int flag=0;

namespace Dr34_1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
			this->label1->Location = System::Drawing::Point(2, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"���O";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(2, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"�d�b";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(39, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 19);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(39, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(75, 19);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(129, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 18);
			this->button1->TabIndex = 4;
			this->button1->Text = L"�o�^";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(129, 43);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 18);
			this->button2->TabIndex = 5;
			this->button2->Text = L"�I��";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(10, 91);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(222, 83);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(9, 67);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(223, 18);
			this->button3->TabIndex = 7;
			this->button3->Text = L"�\���i�I���{�^���������Ă��牟���Ă��������j";
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
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
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
 * ---------------------------------------
 *      ���X�g�f�[�^�̍쐬�i���͏��j     *
 * ---------------------------------------
 */

#include "clrform.h"
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tfield *p;
	if (flag==0){
		head=talloc();
		stoc(textBox1->Text,head->name);
		stoc(textBox2->Text,head->tel);
		old=head;
		flag=1;
	}
	else {
		p=talloc();
		stoc(textBox1->Text,p->name);
		stoc(textBox2->Text,p->tel);
        old->pointer=p;
        old=p;
    }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
    old->pointer=NULL;

			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tfield *p;
	tinit();cls();
	p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
			 }
};
}

