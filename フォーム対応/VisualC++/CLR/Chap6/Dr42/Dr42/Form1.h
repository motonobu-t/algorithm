#pragma once
#include "clrformh.h"
#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};

int sp=8;               /* �m�[�h�̊i�[���݈ʒu */
struct tnode a[MaxSize]={{  1,"Machilda",  2},
                         {  3,"Candy",  4},
                         {  5,"Rolla"   ,nil},
                         {nil,"Ann"  ,nil},
                         {  6,"Emy"     ,  7},
                         {nil,"Nancy",nil},
                         {nil,"Eluza"   ,nil},
                         {nil,"Lisa" ,nil}};
namespace Dr42 {

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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 19);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(110, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�ǉ��E�\��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(14, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(183, 204);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * -----------------------------------
 *      �Q���T���؂ւ̃f�[�^�ǉ�     *
 * -----------------------------------
 */

#include "clrform.h"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    char key[12];
    int p,old,i;

    stoc(textBox1->Text,key);
    p=0;                                /* �؂̃T�[�` */
    while (p!=nil){
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* �V�����m�[�h�̐ڑ� */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;
	tinit();cls();
    for (i=0;i<sp;i++)                  /* �m�[�h�E�e�[�u���̕\�� */
        printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);
			 }
	};
}

