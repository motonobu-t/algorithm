//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei32.h"
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
 * -------------------
 *      スタック     *
 * -------------------
 */

#include "turboform.h"

#define MaxSize 100     /* スタック・サイズ */
int stack[MaxSize];     /* スタック */
int sp=0;               /* スタック・ポインタ */
int push(int n)        /* スタックにデータを積む手続き */
{
    if (sp<MaxSize){
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* スタックが一杯のとき */
}
int pop(int *n)        /* スタックからデータを取り出す手続き */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* スタックが空のとき */
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	n=stoi(Edit1->Text);
	tinit();cls();
	if (push(n)==-1){
       printf("スタックが一杯です\n");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	tinit();cls();
	if (pop(&n)==-1)
        printf("スタックは空です\n");
    else
        printf("stack data --> %d\n",n);
}
//---------------------------------------------------------------------------
