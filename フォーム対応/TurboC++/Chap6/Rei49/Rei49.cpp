//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei49.h"
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
 * -----------------
 *      ���̖�     *
 * -----------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char ope;               /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void)       /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* ������̏I�[���m�[�h�ɂ��� */
    w[n-1]='\0';           /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void prefix(struct tnode *p)     /* �ړ��` */
{
    if (p!=NULL){
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}
void infix(struct tnode *p)      /* �}���` */
{
    if (p!=NULL){
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}
void postfix(struct tnode *p)    /* �ڔ��` */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct tnode *root;
    char expression[]="ab*cd+e/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    printf("prefix  = ");prefix(root);        /* ���̖؂̑��� */
	printf("\n");  // ���s��P�Ə�����
	printf("infix   = ");infix(root);
	printf("\n");
	printf("postfix = ");postfix(root);
    printf("\n");
}
//---------------------------------------------------------------------------
