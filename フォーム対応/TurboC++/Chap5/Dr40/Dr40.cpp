//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr40.h"
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
 *      ���ȍĕҐ��T���i�P�O�Ɉڂ��j     *
 * -----------------------------------------
 */

#include "turboform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head=NULL;
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
	p=talloc();               /* �_�~�[�E�m�[�h */
    p->pointer=head;
    head=p;
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	struct tfield *p,*old1,*old2,*q;
	char key[32];
	stoc(Edit3->Text,key);

	p=head->pointer;
    old1=old2=head;
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            printf("%15s%15s\n",p->name,p->tel);
            if (p!=head->pointer){       /* �擪�łȂ��Ƃ��� */
                q=old1->pointer;         /* �P�O�ƌ���     */
                old1->pointer=p;
                old2->pointer=p->pointer;
                p->pointer=q;
            }
            break;
        }
        old1=old2;
        old2=p;
		p=p->pointer;
    }
}
//---------------------------------------------------------------------------
