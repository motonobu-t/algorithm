#pragma once
#include <math.h>

namespace Rei58 {

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * --------------------
 *       �Ώ̖͗l     *
 * --------------------
 */
#include "clrglib.h"
#define N 9     /* �f�[�^�� */
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
	           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
	    int a,b,j,k;
	    double rd=3.14159/180,
	           m,h,vy,vx,px,py;

		ginit(); cls();
		m=70.0; h=m*sqrt(3.0)/2;      /* ���R�p�`�̕ӂ̒����A���� */
		window(-m/2,-h/3,m/2,h*2/3);
		b=1;
		for (vy=0.0;vy<=310.0;vy=vy+h){
			a=1;
			for (vx=50.0;vx<=500.0;vx=vx+m/2){
				view(vx,vy,vx+m,vy+h);        /* �r���[�|�[�g�̐ݒ� */
				for (j=0;j<3;j++){
					for (k=0;k<N;k++){
						px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
						py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
						if (a*b==-1)
							py=-py+h/3;        /* �t���␳ */
						if (k==0)
							setpoint(px,py);
						else
							moveto(px,py);
					}
				}
				a=-a;
			}
			b=-b;
		}

			 }
};
}

