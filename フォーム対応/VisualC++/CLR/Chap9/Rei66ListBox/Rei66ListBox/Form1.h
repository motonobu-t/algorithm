#pragma once
#define N 8
int column[N+1],    /* 同じ欄に王妃が置かれているかを表す*/
    rup[2*N+1],     /* 右上がりの対角線上に置かれているかを表す */
    lup[2*N+1],     /* 左上がりの対角線上に置かれているかを表す */
    queen[N+1];     /* 王妃の位置 */


namespace Rei66ListBox {

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
	private: System::Windows::Forms::ListBox^  listBox1;

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
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
 *      八王妃（８Ｑｕｅｅｎｓ）の問題     *
 * -----------------------------------------
 */


String^ cbuf;		//	書式変換用			
String^ outstr;		//　１行出力用
void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N){
		outstr=String::Format("解{0,3:###}",++num);        /* 解の表示 */
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
                queen[i]=j;                /* （ｉ，ｊ）が王妃の位置 */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* 局面の変更 */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* 局面の戻し */
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

