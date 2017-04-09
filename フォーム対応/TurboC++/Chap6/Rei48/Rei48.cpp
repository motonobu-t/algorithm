//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei48.h"
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
 *      �q�[�v�E�\�[�g     *
 * -------------------------
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
    int s,p;
	heap[n]=stoi(Edit1->Text);
    s=n;p=s/2;
    while (s>=2 && heap[p]>heap[s]){
        swap(&heap[p],&heap[s]);
        s=p;p=s/2;
    }
    n++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int i,s,p,m;
    m=n-1;                /* ���̕ۑ� */
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* �؂̏I�[��؂藣�� */

        p=1; s=2*p;
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	n=1;  // �ŏ������蒼��
}
//---------------------------------------------------------------------------
