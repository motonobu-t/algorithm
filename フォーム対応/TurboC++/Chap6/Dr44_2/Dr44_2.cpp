//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr44_2.h"
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
 * -------------------------------------
 *      �Q���T���؂̍쐬�i�ċA�Łj     *
 * -------------------------------------
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
void gentree(struct tnode **p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{                                       /* �Q�Ƃɂ��ďo��     */
    if ((*p)==NULL){
        (*p)=talloc();
        strcpy((*p)->name,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char dat[12];
	stoc(Edit1->Text,dat);
	gentree(&root,dat);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tnode *p;
	p=root;
	tinit();cls();
    while (p!=NULL){
        printf("%s\n",p->name);
        p=p->left;
    }
}
//---------------------------------------------------------------------------
