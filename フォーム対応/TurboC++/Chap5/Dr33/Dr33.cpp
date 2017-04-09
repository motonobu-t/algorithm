//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr33.h"
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
 * -----------------------------
 *      �L���[�i�҂��s��j     *
 * -----------------------------
 */

#include "turboform.h"

#define MaxSize 100     /* �L���[�E�T�C�Y */
int queue[MaxSize];     /* �L���[ */
int head=0,             /* �擪�f�[�^�ւ̃|�C���^ */
    tail=0;             /* �I�[�f�[�^�ւ̃|�C���^ */
int queuein(int n)     /* �L���[�Ƀf�[�^������葱�� */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* �L���[����t�̂Ƃ� */
}
int queueout(int *n)    /* �L���[����f�[�^�����o���葱�� */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* �L���[����̂Ƃ� */
}
void disp(void)        /* �҂��s��̓��e��\������葱�� */
{
    int i;

    i=head;
    while (i!=tail){
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n;
	n=stoi(Edit1->Text);
	tinit();cls();
	if (queuein(n)==-1)
         printf("�҂��s�񂪈�t�ł�\n");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	tinit();cls();
	if (queueout(&n)==-1)
        printf("�҂��s��͋�ł�\n");
    else
        printf("queue data --> %d\n",n);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	tinit();cls();
	disp();
}
//---------------------------------------------------------------------------
