//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei65.h"
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

int man,computer,M=0,judge;
int table[3][3]={{0,0,0},    /* �헪�e�[�u�� */
                 {0,0,0},
                 {0,0,0}},
    hist[3]={0,0,0};    /* ���s�̓x�� */
char *hand[3]={"�O�[","�`���L","�p�["};
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tinit();cls();
	if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
        computer=2;
    else if (table[M][1]>table[M][2])
        computer=0;
    else
        computer=1;

	man=stoi(Edit1->Text);
    printf("�R���s���[�^�̎� %s\n",hand[computer]);

    judge=(computer-man+3)%3;
    switch (judge){
        case 0: printf("�Ђ��킯\n");break;
        case 1: printf("���Ȃ��̏���\n");break;
        case 2: printf("�R���s���[�^�̏���\n");break;
    }
    hist[judge]++;
    table[M][man]++;        /* �w�K */
    M=man;
    printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);

}
//---------------------------------------------------------------------------
