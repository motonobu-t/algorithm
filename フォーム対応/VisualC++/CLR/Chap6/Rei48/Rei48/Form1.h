#pragma once
#include "clrformh.h"
int heap[100],n=1;

namespace Rei48 {

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
	private: System::Windows::Forms::Button^  button2;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(43, 19);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(73, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(54, 19);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�ǉ�";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(144, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(52, 19);
			this->button2->TabIndex = 2;
			this->button2->Text = L"�\�[�g";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(15, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(189, 21);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
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
 * -------------------------
 *      �q�[�v�E�\�[�g     *
 * -------------------------
 */

#include "clrform.h"
void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int s,p;
	heap[n]=stoi(textBox1->Text);
    s=n;p=s/2;
    while (s>=2 && heap[p]>heap[s]){
        swap(&heap[p],&heap[s]);
        s=p;p=s/2;
    }
    n++;

			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
    int i,s,p,m;
    m=n-1;                /* ���̕ۑ� */
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* �؂̏I�[��؂藣�� */

        p=1; s=2*p;
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	n=1;	//�@�ŏ������蒼��
			 }
};
}

