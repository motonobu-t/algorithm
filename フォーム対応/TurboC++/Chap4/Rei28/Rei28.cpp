//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei28.h"
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
 * -------------------------------------
 *      ���񐶐��i���������łȂ��j     *
 * -------------------------------------
 */

#include "turboform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]��p[j]�̌��� */
            perm(i+1);                    /* �ċA�Ăяo�� */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* ���ɖ߂� */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* ����̕\�� */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i;

    for (i=1;i<=N;i++)        /* �����ݒ� */
        p[i]=i;
	tinit();cls();  // �ċA�Ăяo���̑O���tinit()��tfin()������
    perm(1);

}
//---------------------------------------------------------------------------
