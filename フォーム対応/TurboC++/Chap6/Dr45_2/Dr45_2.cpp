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
 *      ２分探索木のトラバーサル（非再帰版）     *
 * -----------------------------------------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
} *root=NULL;
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void treewalk(struct tnode *p)   /* 木のトラバーサル（非再帰版） */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)){
        while (q!=NULL){         /* 行けるだけ左に進む */
            w[sp++]=q;           /* 親の位置をスタックに積む */
            q=q->left;
        }
        sp--;                    /* １つ前の親に戻る */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* 右へ進む */
    }
}
struct tnode *gentree(struct tnode *p,char *w)  /* 木の作成の再帰手続き */
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
