//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr65.h"
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
 *      �헪��������񂯂�     *
 * -------------------------------
 */

#include "turboform.h"

int man,computer,C=0,M=0,judge;
int table[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},    /* �헪�e�[�u�� */
                    {{0,0,0},{0,0,0},{0,0,0}},
                    {{0,0,0},{0,0,0},{0,0,0}}},
    hist[3]={0,0,0};                       /* ���s�̓x�� */
char *hand[3]={"�O�[","�`���L","�p�["};

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tinit();cls();
	if (table[C][M][0]>table[C][M][1] && table[C][M][0]>table[C][M][2])
        computer=0;
    else if (table[C][M][1]>table[C][M][2])
        computer=1;
    else
        computer=2;
	man=stoi(Edit1->Text);

    printf("�R���s���[�^�̎� %s\n",hand[computer]);
    judge=(computer-man+3)%3;         /* ���� */
    switch (judge){
        case 0: printf("�Ђ��킯\n");
                table[C][M][(computer+2)%3]++;break;
        case 1: printf("���Ȃ��̏���\n");
                table[C][M][computer]--;break;
        case 2: printf("�R���s���[�^�̏���\n");
                table[C][M][computer]++;break;
    }
    M=man;               /* �P�O�̏�Ԃ�ۑ� */
    C=computer;

    hist[judge]++;
    printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);

}
//---------------------------------------------------------------------------
