//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei1_2Lable.h"
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
 * --------------------------------
 *      �o�����������̎O�p�`      *
 * --------------------------------
 */

char cbuf[100];    //�����ϊ��p
AnsiString outstr; //�P�s�o�͗p

#include <stdio.h>
#define N 12
long combi(int n,int r)
{
    int i;
    long p=1;

    for (i=1;i<=r;i++)
        p=p*(n-i+1)/i;
    return p;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n,r,t;
    outstr="";
	for (n=0;n<=N;n++){
		for (t=0;t<(N-n)*3;t++)        /* �� */
			outstr+=" ";
		for (r=0;r<=n;r++){
			sprintf(cbuf,"%3ld   " ,combi(n,r));
			outstr+=AnsiString(cbuf);
		}
		outstr+="\n";
    }
	Label1->Caption=outstr;
}
//---------------------------------------------------------------------------
