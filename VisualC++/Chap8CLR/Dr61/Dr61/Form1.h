#pragma once
#include <math.h>

namespace Dr61 {

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
 * --------------------------------
 *      �R�����֐��̉A������      *
 * --------------------------------
 */
#include "clrglib.h"
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		int ymin[640],ymax[640];
		int k,px,py;
		double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

		ginit(); cls();
		for (k=0;k<640;k++){        /* �ő�E�ŏ�����z�� */
			ymin[k]=399;ymax[k]=0;
		}
		cos_x=cos(30*rd);  sin_x=sin(30*rd);
		cos_y=cos(-30*rd); sin_y=sin(-30*rd);
		for (z=200.0;z>=-200.0;z=z-10.0){
			for (x=-200.0;x<=200.0;x++){
				y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
				px=(int)(x*cos_y+z*sin_y+320);              /* ��]�ϊ� */
				py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
				if (py<ymin[px]){               /* ���܂ł̍ŏ���菬���� */
					ymin[px]=py;pset(px,py);
				}
				if (py>ymax[px]){               /* ���܂ł̍ő���傫�� */
					ymax[px]=py;pset(px,py);
				}
			}
		}

			 }
	};
}

