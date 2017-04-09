//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr43.h"
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
 * ---------------------------
 *      �ŏ��m�[�h�̒T��     *
 * ---------------------------
 */

#include "turboform.h"
struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
} *root;
int flag=0;  // �{�^���̍ŏ��̃N���b�N�𔻒�
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tnode *p,*old;
	char dat[12];

	if (flag==0){
		root=talloc();                  /* ���[�g�E�m�[�h */
		stoc(Edit1->Text,root->name);
	    root->left=root->right=NULL;
		flag=1;
	}
	else {
		stoc(Edit1->Text,dat);
        p=root;                     /* �؂̃T�[�` */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* �V�����m�[�h�̐ڑ� */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
	tinit();cls();
	p=root;                    /* �ŏ��m�[�h�̒T�� */
    while (p->left!=NULL)
        p=p->left;
    printf("�ŏ��m�[�h�� %s\n",p->name);

    p=root;                    /* �ő�m�[�h�̒T�� */
    while (p->right!=NULL)
        p=p->right;
	printf("�ő�m�[�h�� %s\n",p->name);
}
//---------------------------------------------------------------------------
