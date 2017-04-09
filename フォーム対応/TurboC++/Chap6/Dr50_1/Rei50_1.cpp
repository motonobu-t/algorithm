//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei50_1.h"
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
 *      質疑応答と決定木（動的表現）     *
 * ---------------------------------------
 */
struct tnode {
	struct tnode *left;  /* 左へのポインタ */
	wchar_t node[30];      /* 動的メモリ割り当てを行うため固定長配列 */
	struct tnode *right; /* 右へのポインタ */
};
struct tnode *root;

struct tnode *talloc(void)            /* 記憶領域の取得 */
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tnode *p,*q1,*q2;
    int c;
	AnsiString ret;

    root=talloc();
	ret=InputBox("","初期ノード？","");
	ret.WideChar(root->node,30 );
	root->left=root->right=NULL;
    do {
        p=root;                             /* 木のサーチ */
        while (p->left!=NULL){
			c=MessageDlg(AnsiString(p->node),mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=MessageDlg("答えは"+AnsiString(p->node)+"です",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

		if (c==IDNO){                         /* 学習機能 */
			q1=talloc(); *q1=*p;        /* ノードの移動 */

            q2=talloc();                /* 新しいノードの作成 */
			ret=InputBox("","あなたの考えは","");
			ret.WideChar(q2->node,30);
            q2->left=q2->right=NULL;
                                        /* 質問ノードの作成 */
			ret=InputBox("",AnsiString(q1->node)+"と"+AnsiString(q2->node)+"を区別する質問は","");
			ret.WideChar(p->node,30);
			c=MessageDlg("ｙｅｓの項目は"+AnsiString(q1->node)+"で良いですか",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

            if (c==IDYES){      /* 子の接続 */
				p->left=q1; p->right=q2;
            }
            else {
				p->left=q2; p->right=q1;
            }
        }
	} while (c=MessageDlg("続けますか",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0),c==IDYES);

}
//---------------------------------------------------------------------------
