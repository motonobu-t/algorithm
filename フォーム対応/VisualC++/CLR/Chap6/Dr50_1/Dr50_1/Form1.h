#pragma once
#include "Form2.h"
#include "stdlib.h"
#include <wchar.h>
#include <locale.h>
#include <vcclr.h >
struct tnode {
    struct tnode *left;  /* ���ւ̃|�C���^ */
    wchar_t node[30];      /* ���I���������蓖�Ă��s�����ߌŒ蒷�z�� */
    struct tnode *right; /* �E�ւ̃|�C���^ */
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
	private: System::Windows::Forms::Button^  button1;
	protected: 

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�m�I�f�[�^�x�[�X�̊J�n";
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
 *      ���^�����ƌ���؁i���I�\���j     *
 * ---------------------------------------
 */
struct tnode *talloc(void)            /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	struct tnode *p,*q1,*q2;
	Form2^ f=gcnew Form2();  // ���͗p�_�C�A���O�{�b�N�X
	System::Windows::Forms::DialogResult c;
	pin_ptr<const wchar_t> wc;
	setlocale(LC_ALL,"");
    root=talloc();
	f->label1->Text="�����m�[�h ? ";
	f->textBox1->Text="";
	f->ShowDialog();
	wc=PtrToStringChars(f->textBox1->Text);
	swprintf(root->node,L"%s",wc);
	root->left=root->right=NULL;
    do {
        p=root;                             /* �؂̃T�[�` */
        while (p->left!=NULL){
			c=MessageBox::Show(gcnew String(p->node),"",System::Windows::Forms::MessageBoxButtons::YesNo);
			if (c==System::Windows::Forms::DialogResult::Yes)
                p=p->left;
            else
                p=p->right;
        }
		c=MessageBox::Show(gcnew String(p->node),"",System::Windows::Forms::MessageBoxButtons::YesNo);

        if (c==System::Windows::Forms::DialogResult::No){               /* �w�K�@�\ */
            q1=talloc(); *q1=*p;        /* �m�[�h�̈ړ� */

            q2=talloc();                /* �V�����m�[�h�̍쐬 */
			f->label1->Text="���Ȃ��̍l����";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(q2->node,L"%s",wc);
            q2->left=q2->right=NULL;
                                        /* ����m�[�h�̍쐬 */
			f->label1->Text=gcnew String(q1->node)+"��"+gcnew String(q2->node)+"����ʂ��鎿���";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(p->node,L"%s",wc);
			c=MessageBox::Show("�������̍��ڂ�"+gcnew String(q1->node)+"�ŗǂ��ł���","",System::Windows::Forms::MessageBoxButtons::YesNo);
            if (c==System::Windows::Forms::DialogResult::Yes){          /* �q�̐ڑ� */

                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (c=MessageBox::Show("�����܂���","",System::Windows::Forms::MessageBoxButtons::YesNo),c==System::Windows::Forms::DialogResult::Yes);

			 }
	};
}

