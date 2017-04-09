//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr44_1.h"
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
 * ---------------------------------------
 *      ２分探索木のサーチ（再帰版）     *
 * ---------------------------------------
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
struct tnode *search(struct tnode *p,char *key)  /* 木のサーチ */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
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
    char key[12];
	stoc(Edit1->Text,key);
    root=gentree(root,key);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tnode *p;
	char key[12];
	stoc(Edit1->Text,key);
	tinit();cls();
    if ((p=search(root,key))!=NULL)
        printf("%s が見つかりました\n",p->name);
    else
        printf("見つかりません\n");
}
//---------------------------------------------------------------------------
