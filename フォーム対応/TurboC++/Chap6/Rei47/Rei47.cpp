//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei47.h"
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
 * -----------------------
 *      ヒープの作成     *
 * -----------------------
 */

#include "turboform.h"
int heap[100],n=1;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int s,p,w;
	heap[n]=stoi(Edit1->Text);
    s=n;
    p=s/2;          /* 親の位置 */
    while (s>=2 && heap[p]>heap[s]){    /* 上方移動 */
        w=heap[p];heap[p]=heap[s];heap[s]=w;
        s=p;p=s/2;
    }
    n++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int i;
	tinit();cls();
	for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
}
//---------------------------------------------------------------------------
