//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei66.h"
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
 * -----------------------------------------
 *      �����܁i�W�p�����������j�̖��     *
 * -----------------------------------------
 */

#include "turboform.h"

#define N 8
int column[N+1],    /* �������ɉ��܂��u����Ă��邩��\��*/
    rup[2*N+1],     /* �E�オ��̑Ίp����ɒu����Ă��邩��\�� */
    lup[2*N+1],     /* ���オ��̑Ίp����ɒu����Ă��邩��\�� */
    queen[N+1];     /* ���܂̈ʒu */

void backtrack(int i)
{
    int j,x,y;
    static int num=0;
    if (i>N){
        printf("�� %d \n",++num);        /* ���̕\�� */
        for (y=1;y<=N;y++){
            for (x=1;x<=N;x++)
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            printf("\n");
        }
		MessageBox(NULL,"���̈ړ�","",MB_OK);
		cls();
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* �i���C���j�����܂̈ʒu */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* �ǖʂ̕ύX */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* �ǖʂ̖߂� */
			}
        }
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
	tinit();cls();
	backtrack(1);
}
//---------------------------------------------------------------------------
