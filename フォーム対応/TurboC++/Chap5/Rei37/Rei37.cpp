//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei37.h"
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
 *      �o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------
 */

#include "turboform.h"

struct tfield {
    struct tfield *left;    /* �t�|�C���^ */
    char name[20];          /* ���O       */
    char tel[20];           /* �d�b�ԍ�   */
    struct tfield *right;   /* ���|�C���^ */
} *head,*tail=NULL;

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
	p->left=tail;
    tail=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tfield *p;
	p=tail;                 /* �����X�g�̍쐬 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

	tinit();cls();
    printf("���������X�g\n");
    p=head;                 /* ���X�g�̏��\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("�t�������X�g\n");
    p=tail;                 /* ���X�g�̋t�\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
}
//---------------------------------------------------------------------------
