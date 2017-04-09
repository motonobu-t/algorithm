//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr37.h"
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
 *      �z�E�o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------------
 */

#include "turboform.h"

struct tfield {
    struct tfield *left;    /* �t�|�C���^ */
    char name[20];          /* ���O       */
    char tel[20];           /* �d�b�ԍ�   */
    struct tfield *right;   /* ���|�C���^ */
} *head;  // �֐��̊O�Ő錾
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
    p->right=head;
    p->left=head->left;
    head->left->right=p;
	head->left=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tfield *p;
	tinit();cls();
	printf("���������X�g\n");
    p=head->right;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("�t�������X�g\n");
    p=head->left;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	head=talloc();                  /* �_�~�[�E�m�[�h�̍쐬 */
	head->left=head->right=head;
}
//---------------------------------------------------------------------------
