#pragma once
#include "clrformh.h"
    struct body {
        char name[20];         /* �i�� */
        int size;           /* �d�� */
        long price;         /* ���i */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};

namespace Rei67 {

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
			this->button1->Location = System::Drawing::Point(16, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���s";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(20, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(237, 115);
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
 * -------------------------------------------------------
 *   �_�C�i�~�b�N�E�v���O���~���O�i�i�b�v�E�T�b�N���j  *
 * -------------------------------------------------------
 */

#include "clrform.h"

#define limit 8         /* �i�b�v�T�b�N�̏d�ʐ����l */
#define n 5             /* �i���̎�� */
#define min    1        /* �d���̍ŏ��l */

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++){
        value[s]=0;         /* �����l */
    }
    for (i=0;i<n;i++){                      /* �i���̔ԍ� */
        for (s=a[i].size;s<=limit;s++){     /* �i�b�v�̃T�C�Y */
            p=s-a[i].size;                  /* �󂫃T�C�Y */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s]){
                value[s]=newvalue;item[s]=i;    /* �œK���̍X�V */
            }
        }
    }
	tinit();cls();
    printf("    �i  �ځ@���i\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %5ld\n",a[item[s]].name,a[item[s]].price);
    printf("    ��  �v %5ld\n",value[limit]);

			 }
	};
}

