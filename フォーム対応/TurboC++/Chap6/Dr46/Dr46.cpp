//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr46.h"
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
 *      レベルごとの２分探索木のトラバーサル     *
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
void treewalk(struct tnode *p)  /* レベルごとの木のトラバーサル */
{
    struct connect {            /* 接続関係を示す構造体 */
        struct tnode *node;     /* 子ノード */
        char *parent;           /* 親の名前 */
        char direct;            /* 親の左の子か右の子かを示す */
    } q[128],w[128];
    int i,child,n,level;

    child=1; level=0;           /* 初期値 */
    q[0].node=p; q[0].parent="root"; q[0].direct=' ';
    do {
        n=0;
        printf("level %d :\n",level);
        for (i=0;i<child;i++){
            printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
            /* １つ下のレベルの子へのポインタをスタックに積む */
            if (q[i].node->left!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='l';
                w[n].node=q[i].node->left;
                n++;
            }
            if (q[i].node->right!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='r';
                w[n].node=q[i].node->right;
                n++;
            }
        }
        child=n;            /* １つ下のレベルの子の数 */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
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
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	tinit();cls();
	treewalk(root);
}
//---------------------------------------------------------------------------
