#pragma once
#include "clrformh.h"
int skip[256];
namespace Dr23 {

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(20, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 24);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���s";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(22, 46);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(173, 60);
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
 * ---------------------------------------------------
 *      ������̏ƍ��i�a���������|�l���������@�j     *
 * ---------------------------------------------------
 */

#include "clrform.h"


void table(char *key)      /* �X�L�b�v�E�e�[�u���̍쐬 */
{
    int k,n;

    n=strlen(key);
    for (k=0;k<=255;k++)
        skip[k]=n;
    for (k=0;k<n-1;k++)
        skip[key[k]]=n-1-k;
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);

    p=text+n-1;
    while (p<text+m){
        if (*p==key[n-1]){                   /* �E�[�̕���������r */
            if (strncmp(p-n+1,key,n)==0)     /* �L�[�S�̂��r     */
                return p-n+1;
        }
        p=p+skip[*p];                        /* �T�[�`�ʒu��i�߂� */
    }
    return NULL;
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";
	tinit();cls();
    table(key);
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
			 }
	};
}

