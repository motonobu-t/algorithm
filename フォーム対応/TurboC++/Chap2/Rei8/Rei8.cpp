//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei8.h"
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
 *     ��l�����i���`�����@�j     *
 * --------------------------------
 */

#include "turboform.h"

unsigned rndnum=13;        /* �����̏����l */
unsigned irnd(void)        /* 0�`32767�̐������� */
{
	rndnum=(rndnum*109+1021) % 32768;
	return rndnum;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int j;
	tinit();cls();
	for (j=0;j<100;j++){
		printf("%8d",irnd());
	}

}
//---------------------------------------------------------------------------
