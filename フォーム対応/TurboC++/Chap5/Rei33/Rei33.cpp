//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei33.h"
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
 * -----------------------------
 *      キュー（待ち行列）     *
 * -----------------------------
 */

#include "turboform.h"

#define MaxSize 100     /* キュー・サイズ */
int queue[MaxSize];     /* キュー */
int head=0,             /* 先頭データへのポインタ */
    tail=0;             /* 終端データへのポインタ */
int queuein(int n)       /* キューにデータを入れる手続き */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* キューが一杯のとき */
}
int queueout(int *n)     /* キューからデータを取り出す手続き */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* キューが空のとき */
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	n=stoi(Edit1->Text);
	tinit();cls();
	if (queuein(n)==-1){
        printf("待ち行列が一杯です\n");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	tinit();cls();
    if (queueout(&n)==-1)
        printf("待ち行列は空です\n");
    else
        printf("queue data --> %d\n",n);
}
//---------------------------------------------------------------------------
