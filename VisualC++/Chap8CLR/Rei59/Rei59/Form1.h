#pragma once
#include <math.h>

struct {
	int f;
	double x,y,z;
} a[]
	    ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
	      1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
	      -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
	      -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
	      -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
	       1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
	      -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
		   1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
	      -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
	       1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0  };

namespace Rei59 {

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
 * ----------------------
 *       �������e       *
 * ----------------------
 */
#include "clrglib.h"
void rotate(double ax,double ay,double az,double x,double y,double z,
       double *px,double *py)      /* �R������]�ϊ� */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);        /* ������� */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                         /* ������� */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);     /* ������� */
    *py=x2*sin(az)+y2*cos(az);
}

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	    int k;
	    double ax=20*3.14159/180,
	           ay=-45*3.14159/180,
	           az=0*3.14159/180,
	           px,py;

		ginit(); cls();
		window(-160,-100,160,100);

		for (k=0;a[k].f!=-999;k++){
			rotate(ax,ay,az,a[k].x,a[k].y,a[k].z,&px,&py);
			if (a[k].f==-1)          /* �n�_�Ȃ� */
				setpoint(px,py);
			else
				moveto(px,py);
		}

			 }
	};
}

