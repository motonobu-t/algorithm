//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr14_2ListBox.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
 * -------------------------
 *      階乗の多桁計算     *
 * -------------------------
 */
#include <stdio.h>
#define L 64               /* 求める桁数      */
#define L2 ((L+3)/4)       /* 配列のサイズ    */

AnsiString outstr;	//　１行出力用
char cbuf[100];		//	書式変換用

void printresult(short c[])       /* 結果の表示 */
{
    short i;
	for (i=0;i<L2;i++){
		sprintf(cbuf, "%04d",c[i]);
		outstr+=AnsiString(cbuf);
	}
	Form1->ListBox1->AddItem(outstr,NULL);
}
void lmul(short a[],short b,short c[])    /* ロング数×ショート数 */
{
    short i;long d,cy=0;
    for (i=L2-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}

void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])
{
    short i,brrw=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	short s[L2];
    short k;
	for (k=0;k<L2;k++)
        s[k]=0;

    s[L2-1]=1;
    for (k=1;k<=49;k++){
		lmul(s,k,s);
		sprintf(cbuf,"%2d!=",k);
		outstr=AnsiString(cbuf);
        printresult(s);
    }

}
//---------------------------------------------------------------------------
