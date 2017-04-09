#pragma once
#include "clrformh.h"
#define N 7             /* �f�[�^�� */
#define M 5             /* ���Ă͂ߎ��� */

#define Max(a,b) (((a)>(b))?(a):(b))

namespace Dr17 {

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
			this->button1->Location = System::Drawing::Point(4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"�`��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(1, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(717, 379);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(713, 413);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * ---------------------
 *      �ŏ��Q��@     *
 * ---------------------
 */

#include "clrform.h"

double ipow(double p,int n)        /* ���O���@�����߂�֐� */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
    double x[]={-3,-2,-1, 0,1,2,3},
           y[]={ 5,-2,-3,-1,1,4,5},
           a[M+1][M+2],s[2*M+1],t[M+1];
    int i,j,k;
    double p,d;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)               /* s0 ���� s2m �̌v�Z */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                 /* t0 ���� tm �̌v�Z */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] �� s[],t[] �̒l������ */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* �͂��o�� */
        p=a[k][k];
        for (j=k;j<=M+1;j++)
            a[k][j]=a[k][j]/p;
        for (i=0;i<=M;i++){
            if (i!=k){
                d=a[i][k];
                for (j=k;j<=M+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    /* �W���̕\�� */ 
	tinit();cls();
    for (k=0;k<=M;k++)                    
        printf("a%d=%f\n",k,a[k][M+1]);

    /* �O���t�̕\�� */
    double px,py,xmax,ymax,xmin,ymin,sx,sy,dx,dy,step;

    ginit();
    xmax=xmin=x[0];ymax=ymin=y[0];
    for (i=1;i<N;i++){
        if (x[i]<xmin) xmin=x[i];
        if (y[i]<ymin) ymin=y[i];
        if (x[i]>xmax) xmax=x[i];
        if (y[i]>ymax) ymax=y[i];
    }
    sx=1.2*Max(fabs(xmin),fabs(xmax)); /* �����̃T�C�Y */
    sy=1.2*Max(fabs(ymin),fabs(ymax)); /* �����̃T�C�Y */
    dx=sx/100;dy=sy/100;               /* �{��̃T�C�Y */
    step=(xmax-xmin)/100;              /* �v���b�g�Ԋu */

    window(-sx,-sy,sx,sy);

    line(-sx,0,sx,0);line(0,-sy,0,sy); /* ���� */

    for (i=0;i<N;i++){  /* �{��̃v���b�g */
        line(x[i]-dx,y[i],x[i]+dx,y[i]);
        line(x[i],y[i]-dy,x[i],y[i]+dy);
    }

    for (px=xmin;px<=xmax;px=px+step){ /* �O���t�̕`�� */
        py=0;
        for (i=0;i<=M;i++)
            py=py+a[i][M+1]*ipow(px,i);
        if (px==xmin)
            setpoint(px,py);
        else
            moveto(px,py);
    }
			 }
	};
}

