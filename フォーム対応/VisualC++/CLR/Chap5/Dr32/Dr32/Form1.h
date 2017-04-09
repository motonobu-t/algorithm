#pragma once
#include "clrformh.h"
int pie[20][3];        /* 20:�~�Ղ̍ő喇��, 3:�_�̐� */
int sp[3],N;           /* �X�^�b�N�E�|�C���^ */
namespace Dr32 {

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(112, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(59, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���s";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 12);
			this->label1->TabIndex = 1;
			this->label1->Text = L"�~�Ղ̖���";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(33, 19);
			this->textBox1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(9, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(265, 200);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
/*
 * ---------------------------------------------
 *      �n�m�C�̓��i�V�~�����|�V�����t���j     *
 * ---------------------------------------------
 */

#include "clrform.h"
void hanoi(int n,int a,int b,int c)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void move(int n,int s,int d)        /* �~�Ղ̈ړ��V�~�����[�V���� */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ���|�����։~�Ղ̈ړ� */
    sp[d]++;                        /* �X�^�b�N�E�|�C���^�̍X�V */
    sp[s]--;
	printf("\n");
    printf("%d �Ԃ̉~�Ղ� %c-->%c �Ɉڂ�\n\n",n,'a'+s,'a'+d);
    for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
	printf("\n");
    printf("       a       b       c\n");
	MessageBox::Show("����");
	cls();
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    int i;
	N=stoi(textBox1->Text);
    for (i=0;i<N;i++)               /* �_���ɉ~�Ղ�ς� */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* �X�^�b�N�E�|�C���^�̏����ݒ� */
	tinit();cls();
    hanoi(N,0,1,2);
			 }
	};
}

