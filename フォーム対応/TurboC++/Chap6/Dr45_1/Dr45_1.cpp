//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr45_1.h"
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
//---------------------------------------------------------------------------
/*
 * -----------------------------------
 *      ２分探索木のトラバーサル     *
 * -----------------------------------
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
void treewalk(struct tnode *p)  /* 木のトラバーサル */
{
	if (p!=NULL){
		treewalk(p->right);
		printf("%s\n",p->name);
		treewalk(p->left);
	}
}
struct tnode *gentree(struct tnode *p,char *w)  /* 木の作成の再帰手続き */
{
	if (p==NULL){
		p=talloc();
		strcpy(p->name,w);
		p->left=p->right=NULL;
	}
	else if(strcmp(w,p->name)<0)
		p->left=gentree(p->left,w);
	else
        p->right=gentree(p->right,w);
	return p;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char dat[12];
	stoc(Edit1->Text,dat);
	root=gentree(root,dat);
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	tinit();cls();
	treewalk(root);
}
//---------------------------------------------------------------------------
