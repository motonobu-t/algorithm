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
 *      式の木     *
 * -----------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char ope;               /* 項目 */
    struct tnode *right;    /* 右部分木へのポインタ */
};

struct tnode *talloc(void)       /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* 式の木の作成 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* 文字列の終端をノードにする */
    w[n-1]='\0';           /* 終端を除く */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void prefix(struct tnode *p)     /* 接頭形 */
{
    if (p!=NULL){
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}
void infix(struct tnode *p)      /* 挿入形 */
{
    if (p!=NULL){
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}
void postfix(struct tnode *p)    /* 接尾形 */
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
    printf("prefix  = ");prefix(root);        /* 式の木の走査 */
	printf("\n");  // 改行を単独処理に
	printf("infix   = ");infix(root);
	printf("\n");
	printf("postfix = ");postfix(root);
    printf("\n");
}
//---------------------------------------------------------------------------
