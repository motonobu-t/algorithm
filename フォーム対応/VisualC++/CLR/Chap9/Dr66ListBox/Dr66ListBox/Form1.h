#pragma once
#define N 5

int m[N+4][N+4],                    /* 盤面 */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* 騎士の移動ｘ成分 */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* 騎士の移動ｙ成分 */


namespace Dr66ListBox {

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
			this->button1->Location = System::Drawing::Point(12, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"実行";
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
 *      騎士巡歴の問題     *
 * -------------------------
 */
String^ cbuf;		//	書式変換用			
String^ outstr;		//　１行出力用

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* 訪問順番の記録 */
        if (count==N*N){
			outstr=String::Format("解{0,3:###}",++num);    /* 解の表示 */
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
            for (k=0;k<8;k++)           /* 進む位置を選ぶ */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* １つ前に戻る */
        count--;
    }
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* 盤面 */
            else
                m[i][j]=1;      /* 壁 */

    backtrack(2,2);

			 }
	};
}

