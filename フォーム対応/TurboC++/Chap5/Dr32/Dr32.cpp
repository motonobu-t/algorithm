//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr32.h"
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
 * ---------------------------------------------
 *      �n�m�C�̓��i�V�~�����|�V�����t���j     *
 * ---------------------------------------------
 */

#include "turboform.h"
int pie[20][3];        /* 20:�~�Ղ̍ő喇��, 3:�_�̐� */
int sp[3],N;           /* �X�^�b�N�E�|�C���^ */

void move(int n,int s,int d)        /* �~�Ղ̈ړ��V�~�����[�V���� */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ���|�����։~�Ղ̈ړ� */
    sp[d]++;                        /* �X�^�b�N�E�|�C���^�̍X�V */
    sp[s]--;

	printf("\n"); 
	printf("%d �Ԃ̉~�Ղ� %c-->%c �Ɉڂ�\n",n,'a'+s,'a'+d);
	printf("\n");   
	for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
	printf("\n");
	printf("       a       b       c\n");
	MessageBox(NULL,"���̈ړ�","",MB_OK); // ���̕\���܂ő҂�
	cls();
}
void hanoi(int n,int a,int b,int c)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i;
	N=stoi(Edit1->Text);

    for (i=0;i<N;i++)               /* �_���ɉ~�Ղ�ς� */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* �X�^�b�N�E�|�C���^�̏����ݒ� */
	tinit();cls();
	hanoi(N,0,1,2);
}
//---------------------------------------------------------------------------
