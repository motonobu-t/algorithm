//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei1.h"
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
 * ------------------------------
 *      ëQâªéÆÅinÇbrÇÃåvéZÅj    *
 * ------------------------------
 */

#include "turboform.h"

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
	int n,r;
	tinit();
	for (n=0;n<=5;n++) {
		for (r=0;r<=n;r++){
			printf("%dÇb%d=%ld  ",n,r,combi(n,r));
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------

