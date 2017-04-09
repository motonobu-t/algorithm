//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei32.h"
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
 * -------------------
 *      �X�^�b�N     *
 * -------------------
 */

#include "turboform.h"

#define MaxSize 100     /* �X�^�b�N�E�T�C�Y */
int stack[MaxSize];     /* �X�^�b�N */
int sp=0;               /* �X�^�b�N�E�|�C���^ */
int push(int n)        /* �X�^�b�N�Ƀf�[�^��ςގ葱�� */
{
    if (sp<MaxSize){
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����t�̂Ƃ� */
}
int pop(int *n)        /* �X�^�b�N����f�[�^�����o���葱�� */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����̂Ƃ� */
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	n=stoi(Edit1->Text);
	tinit();cls();
	if (push(n)==-1){
       printf("�X�^�b�N����t�ł�\n");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	tinit();cls();
	if (pop(&n)==-1)
        printf("�X�^�b�N�͋�ł�\n");
    else
        printf("stack data --> %d\n",n);
}
//---------------------------------------------------------------------------
