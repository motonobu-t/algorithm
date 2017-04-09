#pragma once
#define N 5

int m[N+4][N+4],                    /* �Ֆ� */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* �R�m�̈ړ������� */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* �R�m�̈ړ������� */


namespace Dr66ListBox {

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
	private: System::Windows::Forms::ListBox^  listBox1;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���s";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(14, 45);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(157, 196);
			this->listBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 263);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * -------------------------
 *      �R�m�����̖��     *
 * -------------------------
 */
String^ cbuf;		//	�����ϊ��p			
String^ outstr;		//�@�P�s�o�͗p

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* �K�⏇�Ԃ̋L�^ */
        if (count==N*N){
			outstr=String::Format("��{0,3:###}",++num);    /* ���̕\�� */
			listBox1->Items->Add(outstr);
            for (i=2;i<=N+1;i++){
				outstr="";
				for (j=2;j<=N+1;j++){
					cbuf=String::Format("{0,4:####}",m[i][j]);
					outstr+=cbuf;
				}
				listBox1->Items->Add(outstr);
            }
        }
        else
            for (k=0;k<8;k++)           /* �i�ވʒu��I�� */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* �P�O�ɖ߂� */
        count--;
    }
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* �Ֆ� */
            else
                m[i][j]=1;      /* �� */

    backtrack(2,2);

			 }
	};
}

