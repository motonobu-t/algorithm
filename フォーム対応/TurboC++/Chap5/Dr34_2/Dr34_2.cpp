//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr34_2.h"
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
 * -----------------------------------------------
 *      ���X�g�f�[�^�̍쐬�i�_�~�[�E�m�[�h�j     *
 * -----------------------------------------------
 */

#include "turboform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head,*old;    // �֐��̊O�Ő錾
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tfield *p;
	p=talloc();
	stoc(Edit1->Text,p->name);
	stoc(Edit2->Text,p->tel);
	old->pointer=p;
    old=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    old->pointer=NULL;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	struct tfield *p;
	tinit();cls();
	p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	head=talloc();      /* �_�~�[�E�m�[�h�̍쐬 */
	old=head;
}
//---------------------------------------------------------------------------
