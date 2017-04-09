//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr49.h"
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
 * ---------------------------------
 *      ���̖؂�p�������̌v�Z     *
 * ---------------------------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    int ope;                /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* ������̏I�[���m�[�h�ɂ��� */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* �萔�̂Ƃ��͐��l�ɕϊ� */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    /* ���̖؂̌v�Z */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct tnode *root;
    char expression[]="53*64+2/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    postfix(root);         /* ���̌v�Z */
    printf("value=%d\n",root->ope);
}
//---------------------------------------------------------------------------
