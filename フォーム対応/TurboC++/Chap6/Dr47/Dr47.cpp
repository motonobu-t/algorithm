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
 *      �q�[�v�̍쐬�i�����ړ��j     *
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
    m=n-1;                     /* �f�[�^�� */
    for (i=m/2;i>=1;i--){
        p=i;                 /* �e�̈ʒu */
        s=2*p;               /* ���̎q�̈ʒu */
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̎q�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }

	tinit();cls();
	for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
	printf("\n");
}
//---------------------------------------------------------------------------
