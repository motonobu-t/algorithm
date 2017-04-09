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
 *      式の木を用いた式の計算     *
 * ---------------------------------
 */

#include "turboform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    int ope;                /* 項目 */
    struct tnode *right;    /* 右部分木へのポインタ */
};
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* 式の木の作成 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* 文字列の終端をノードにする */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* 定数のときは数値に変換 */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* 終端を除く */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    /* 式の木の計算 */
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
    postfix(root);         /* 式の計算 */
    printf("value=%d\n",root->ope);
}
//---------------------------------------------------------------------------
