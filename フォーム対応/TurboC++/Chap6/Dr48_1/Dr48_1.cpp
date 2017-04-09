//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr48_1.h"
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
 *      ヒープ・ソート     *
 * -------------------------
 */

#include "turboform.h"
int heap[100],n=1;

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
void shiftdown(int p,int n,int heap[])   /* 下方移動 */
{
    int s;
    s=2*p;
    while (s<=n){
        if( s<n && heap[s+1]<heap[s])    /* 左と右の子の小さい方 */
            s++;
        if (heap[p]<=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* 親と子の位置の更新 */
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	heap[n]=stoi(Edit1->Text);
    n++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int i,m;
    m=n-1;                        /* ｎの保存 */
    for (i=m/2;i>=1;i--)        /* 初期ヒープの作成 */
        shiftdown(i,m,heap);
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* 木の終端を切り離す */
        shiftdown(1,m,heap);
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	n=1;	// 最初からやり直す
}
//---------------------------------------------------------------------------
