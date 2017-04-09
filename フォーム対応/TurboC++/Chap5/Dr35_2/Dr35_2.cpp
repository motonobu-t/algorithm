//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr35_2.h"
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
 *      ���X�g�f�[�^�̒T��     *
 * -----------------------------
 */

#include "turboform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} sentinel,*head=&sentinel;  // ������

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
	p->pointer=head;
	head=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tfield *p;
	char key[32];
	stoc(Edit3->Text,key);
 
	strcpy(sentinel.name,key);      /* �ԕ��ɃL�[������ */
    p=head;
    while (strcmp(p->name,key)!=0)
        p=p->pointer;
	tinit();cls();
    if (p!=&sentinel)
        printf("%s %s\n",p->name,p->tel);
    else
        printf("������܂���\n");
}
//---------------------------------------------------------------------------
