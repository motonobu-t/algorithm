#pragma once
#include "Form2.h"
#include <wchar.h>
#include <locale.h>
#include <vcclr.h >

#define Max 100
#define nil -1
struct tnode {
    int left;      /* ���ւ̃|�C���^ */
    wchar_t node[30];  /* �\���̃����o��String^�͎g���Ȃ� */
    int right;     /* �E�ւ̃|�C���^ */
};
struct tnode a[Max]={{1  ,L"�|�\�l�ł���"  ,2},
                     {3  ,L"�̎�ł���"    ,4},
                     {nil,L"�g�c�@��"      ,nil},
                     {nil,L"���@�z��"    ,nil},
                     {5  ,L"���D�ł���"    ,6},
                     {nil,L"���R�@����"    ,nil},
                     {nil,L"�v�� �G"       ,nil}};
int lp=6;

namespace Rei50 {

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
			this->button1->Location = System::Drawing::Point(22, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�m�I�f�[�^�ׁ[�X�̊J�n";
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
 *      ���^�����ƌ���؁i�z��\���j     *
 * ---------------------------------------
 */

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Form2^ f=gcnew Form2();  // ���͗p�_�C�A���O�{�b�N�X
	int p;
	System::Windows::Forms::DialogResult c;
	pin_ptr<const wchar_t> wc;
	setlocale(LC_ALL,"");
	do {
        p=0;
        while (a[p].left!=nil){          /* �؂̃T�[�` */
			c=MessageBox::Show(gcnew String(a[p].node),"",System::Windows::Forms::MessageBoxButtons::YesNo);
			if (c==System::Windows::Forms::DialogResult::Yes)
                p=a[p].left;
            else
                p=a[p].right;
        }
		c=MessageBox::Show(gcnew String(a[p].node),"",System::Windows::Forms::MessageBoxButtons::YesNo);

        if (c==System::Windows::Forms::DialogResult::No){               /* �w�K�@�\ */
            a[lp+1]=a[p];                    /* �m�[�h�̈ړ� */
                                           /* �V�����m�[�h�̍쐬 */
			f->label1->Text="���Ȃ��̍l����";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(a[lp+2].node,L"%s",wc);
            a[lp+2].left=a[lp+2].right=nil;
                                            /* ����m�[�h�̍쐬 */
			f->label1->Text=gcnew String(a[lp+1].node)+"��"+gcnew String(a[lp+2].node)+"����ʂ��鎿���";
			f->textBox1->Text="";
			f->ShowDialog();
			wc=PtrToStringChars(f->textBox1->Text);
			swprintf(a[p].node,L"%s",wc);
			c=MessageBox::Show("�������̍��ڂ�"+gcnew String(a[lp+1].node)+"�ŗǂ��ł���","",System::Windows::Forms::MessageBoxButtons::YesNo);
            if (c==System::Windows::Forms::DialogResult::Yes){          /* �q�̐ڑ� */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
	} while (c=MessageBox::Show("�����܂���","",System::Windows::Forms::MessageBoxButtons::YesNo),c==System::Windows::Forms::DialogResult::Yes);

			 }
	};
}

