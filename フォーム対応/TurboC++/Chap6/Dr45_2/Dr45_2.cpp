//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr45_2.h"
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
 *      �Q���T���؂̃g���o�[�T���i��ċA�Łj     *
 * -----------------------------------------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
} *root=NULL;
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void treewalk(struct tnode *p)   /* �؂̃g���o�[�T���i��ċA�Łj */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)){
        while (q!=NULL){         /* �s���邾�����ɐi�� */
            w[sp++]=q;           /* �e�̈ʒu���X�^�b�N�ɐς� */
            q=q->left;
        }
        sp--;                    /* �P�O�̐e�ɖ߂� */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* �E�֐i�� */
    }
}
struct tnode *gentree(struct tnode *p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(p->name,w)<0)
        p->right=gentree(p->right,w);
    else
        p->left=gentree(p->left,w);
    return p;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char dat[12];
	stoc(Edit1->Text,dat);
    root=gentree(root,dat);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	tinit();cls();
	treewalk(root);
}
//---------------------------------------------------------------------------
