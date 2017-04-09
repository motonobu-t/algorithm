#pragma once
#include <math.h>

namespace Rei60 {

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
 * -------------------------------------
 *      ��]�̃��f���i���C���O���X�j   *
 * -------------------------------------
 */
#include "clrglib.h"
void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* �R������]�ϊ� */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ������� */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ������� */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ������� */
    *py=x2*sin(az)+y2*cos(az);
}

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	    int n,k;
	    double x,z,px,py,ax,ay,az,rd=3.14159/180;
	    double y[]={180,140,100,60,20,10,4,0,-999},   /* ���� */
	           r[]={100,55,10,10,10,50,80,80,-999};   /* ���a */
		ax=35*rd;   /* �������̉�]�p */
		ay=0;       /* �������̉�]�p */
		az=20*rd;   /* �������̉�]�p */

		ginit(); cls();
		window(-320,-100,320,300);

		for (k=0;(int)y[k]!=-999;k++){    /* �������̉�]�O�� */
			for (n=0;n<=360;n=n+10){
				x=r[k]*cos(n*rd);
				z=r[k]*sin(n*rd);
				rotate(ax,ay,az,x,y[k],z,&px,&py);
				if (n==0)
					setpoint(px,py);
				else
					moveto(px,py);
			}
		}
		for (n=0;n<=360;n=n+60){        /* �Ő� */
			for (k=0;(int)y[k]!=-999;k++){
				x=r[k]*cos(n*rd);
				z=r[k]*sin(n*rd);
				rotate(ax,ay,az,x,y[k],z,&px,&py);
				if (k==0)
					setpoint(px,py);
				else
					moveto(px,py);
			}
		}

			 }
};
}

