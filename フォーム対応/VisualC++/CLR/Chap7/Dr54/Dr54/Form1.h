#pragma once
#include "clrformh.h"
#define Node 4        /* 節点の数 */
#define Root 6        /* 辺の数 */
#define Start 1       /* 開始点 */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,0},
                       {0,0,0,1,1},
                       {0,0,0,0,1},
                       {0,1,1,0,0}};
int success,
    v[Root+1],      /* 経路を入れるスタック */
    n;              /* 通過した道の数 */
namespace Dr54 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
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
			this->button1->Location = System::Drawing::Point(17, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(62, 19);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(21, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(227, 50);
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
 * -----------------------------------------------
 *      Ｅｕｌｅｒの一筆書き（有向グラフ版）     *
 * -----------------------------------------------
 */

#include "clrform.h"
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){     /* 辺の数だけ通過し元に戻ったら */
        printf("解 %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--;     /* 通つた道を切り離す */
                n--;
                visit(j);
                a[i][j]++;     /* 道を復旧する */
                n++;
            }
    }
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	tinit();cls(); 
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("解なし\n");

			 }
	};
}

