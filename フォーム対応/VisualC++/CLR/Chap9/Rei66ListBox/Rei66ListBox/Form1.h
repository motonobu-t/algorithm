#pragma once
#define N 8
int column[N+1],    /* �������ɉ��܂��u����Ă��邩��\��*/
    rup[2*N+1],     /* �E�オ��̑Ίp����ɒu����Ă��邩��\�� */
    lup[2*N+1],     /* ���オ��̑Ίp����ɒu����Ă��邩��\�� */
    queen[N+1];     /* ���܂̈ʒu */


namespace Rei66ListBox {

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
			this->button1->Location = System::Drawing::Point(9, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"���s";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(10, 41);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(137, 292);
			this->listBox1->TabIndex = 1;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 347);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * -----------------------------------------
 *      �����܁i�W�p�����������j�̖��     *
 * -----------------------------------------
 */


String^ cbuf;		//	�����ϊ��p			
String^ outstr;		//�@�P�s�o�͗p
void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N){
		outstr=String::Format("��{0,3:###}",++num);        /* ���̕\�� */
		listBox1->Items->Add(outstr);  
		for (y=1;y<=N;y++){
			outstr="";
			for (x=1;x<=N;x++){
				if (queen[y]==x){
					outstr+=" Q";
				}
				else{
					outstr+=" .";
				}
			}
			listBox1->Items->Add(outstr);  
		}
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* �i���C���j�����܂̈ʒu */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* �ǖʂ̕ύX */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* �ǖʂ̖߂� */
            }
        }
    }
}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
    backtrack(1);

			 }
	};
}

