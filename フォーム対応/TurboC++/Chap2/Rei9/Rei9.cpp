//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei9.h"
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
 * ----------------------------
 *     ��`���ɂ���ϕ�     *
 * ----------------------------
 */


#include "turboform.h"
#define f(x) (sqrt(4-(x)*(x)))   /* ��ϕ��֐� */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int k;
	double a,b,n,h,x,s,sum;
	a=stod(Edit1->Text);
	b=stod(Edit2->Text);
	n=50;             /* ���`���Ԃ̕����� */
	h=(b-a)/n;        /* ��ԕ� */
	x=a; s=0;
	for (k=1;k<=n-1;k++){
		x=x+h;
		s=s+f(x);
	}
	sum=h*((f(a)+f(b))/2+s);
	tinit();
	printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
	printf("   /%f\n",a);
}
//---------------------------------------------------------------------------
