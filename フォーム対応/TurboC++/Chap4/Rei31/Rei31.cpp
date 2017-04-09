//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei31.h"
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
 * ---------------------------
 *      クイック・ソート     *
 * ---------------------------
 */

#include "turboform.h"

#define N 10
void quick(int a[],int left,int right)
{
    int s,t,i,j;

    if (left<right){
        s=a[left];              /* 左端の項を軸にする */
        i=left; j=right+1;      /* 軸より小さいグループと       */
        while (1){              /*       大きいグループに分ける */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
        a[left]=a[j]; a[j]=s;   /* 軸を正しい位置に入れる */

        quick(a,left,j-1);      /* 左部分列に対する再帰呼び出し */
        quick(a,j+1,right);     /* 右部分列に対する再帰呼び出し */
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    static int a[]={41,24,76,11,45,64,21,69,19,36};
    int k;

    quick(a,0,N-1);
	tinit();cls();
    for (k=0;k<N;k++)
        printf("%4d",a[k]);
    printf("\n");

}
//---------------------------------------------------------------------------
