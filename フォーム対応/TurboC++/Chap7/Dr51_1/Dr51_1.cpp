//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr51_1.h"
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
 *      �O���t�̒T���i�[���D��j     *
 * -----------------------------------
 */
#include "turboform.h"

#define N 8                             /* �_�̐� */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* �אڍs�� */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* �K��t���O */

void visit(int i)
{
    int j;

    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0){
            printf("%d->%d ",i,j);
            visit(j);
        }
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,k;
	tinit();cls();
    for (k=1;k<=N;k++){
        for (i=1;i<=N;i++)
            v[i]=0;
        visit(k);
        printf("\n");
    }
}
//---------------------------------------------------------------------------
