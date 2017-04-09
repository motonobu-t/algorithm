#pragma once
#include <math.h>

namespace Dr17CLR {

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

	protected: 

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 263);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
/*
 * ---------------------
 *      最小２乗法     *
 * ---------------------
 */

#include "clrglib.h"

#define N 7             /* データ数 */
#define M 5             /* 当てはめ次数 */

#define Max(a,b) (((a)>(b))?(a):(b))

double ipow(double p,int n)        /* ｐ＾ｎ　を求める関数 */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
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
        for (j=0;j<=2*M;j++)               /* s0 から s2m の計算 */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                 /* t0 から tm の計算 */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] に s[],t[] の値を入れる */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* はき出し */
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

    /* 係数の表示 */  
	Graphics^ g=this->CreateGraphics();
	System::Drawing::Font^ f=gcnew System::Drawing::Font("MS 明朝",10);
    for (k=0;k<=M;k++)                    
		g->DrawString("a"+k+"="+a[k][M+1],f,Brushes::Black,(float)0,(float)k*14);

    /* グラフの表示 */
    double px,py,xmax,ymax,xmin,ymin,sx,sy,dx,dy,step;

    ginit();
    xmax=xmin=x[0];ymax=ymin=y[0];
    for (i=1;i<N;i++){
        if (x[i]<xmin) xmin=x[i];
        if (y[i]<ymin) ymin=y[i];
        if (x[i]>xmax) xmax=x[i];
        if (y[i]>ymax) ymax=y[i];
    }
    sx=1.2*Max(fabs(xmin),fabs(xmax)); /* ｘ軸のサイズ */
    sy=1.2*Max(fabs(ymin),fabs(ymax)); /* ｙ軸のサイズ */
    dx=sx/100;dy=sy/100;               /* ＋印のサイズ */
    step=(xmax-xmin)/100;              /* プロット間隔 */

    window(-sx,-sy,sx,sy);

    line(-sx,0,sx,0);line(0,-sy,0,sy); /* 軸線 */

    for (i=0;i<N;i++){  /* ＋印のプロット */
        line(x[i]-dx,y[i],x[i]+dx,y[i]);
        line(x[i],y[i]-dy,x[i],y[i]+dy);
    }

    for (px=xmin;px<=xmax;px=px+step){ /* グラフの描画 */
        py=0;
        for (i=0;i<=M;i++)
            py=py+a[i][M+1]*ipow(px,i);
        if (px==xmin)
            setpoint(px,py);
        else
            moveto(px,py);
    }

			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

