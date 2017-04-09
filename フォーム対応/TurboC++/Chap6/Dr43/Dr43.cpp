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
 *      最小ノードの探索     *
 * ---------------------------
 */

#include "turboform.h"
struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
} *root;
int flag=0;  // ボタンの最初のクリックを判定
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tnode *p,*old;
	char dat[12];

	if (flag==0){
		root=talloc();                  /* ルート・ノード */
		stoc(Edit1->Text,root->name);
	    root->left=root->right=NULL;
		flag=1;
	}
	else {
		stoc(Edit1->Text,dat);
        p=root;                     /* 木のサーチ */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* 新しいノードの接続 */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
	tinit();cls();
	p=root;                    /* 最小ノードの探索 */
    while (p->left!=NULL)
        p=p->left;
    printf("最小ノード＝ %s\n",p->name);

    p=root;                    /* 最大ノードの探索 */
    while (p->right!=NULL)
        p=p->right;
	printf("最大ノード＝ %s\n",p->name);
}
//---------------------------------------------------------------------------
