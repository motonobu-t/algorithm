//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr47.h"
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
 * -----------------------------------
 *      ヒープの作成（下方移動）     *
 * -----------------------------------
 */

#include "turboform.h"

int heap[100],n=1;

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	heap[n]=stoi(Edit1->Text);
    n++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int i,p,s,m;
    m=n-1;                     /* データ数 */
    for (i=m/2;i>=1;i--){
        p=i;                 /* 親の位置 */
        s=2*p;               /* 左の子の位置 */
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* 左と右の子の小さい方 */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* 親と子の位置の更新 */
        }
    }

	tinit();cls();
	for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
	printf("\n");
}
//---------------------------------------------------------------------------
