//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr28_1.h"
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
 * -------------------------------
 *      ���񐶐��i���������j     *
 * -------------------------------
 */

#include "turboform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,k,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[j];                  /* p[i]�`p[j]�̉E���[�e�C�g */
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);               /* �ċA�Ăяo�� */

            for (k=i;k<j;k++)        /* �z��̕��т��ċA�Ăяo���O�ɖ߂� */
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N;j++)           /* ����̕\�� */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i;

    for (i=1;i<=N;i++)        /* �����ݒ� */
        p[i]=i;
	tinit();cls();
    perm(1);

}
//---------------------------------------------------------------------------
