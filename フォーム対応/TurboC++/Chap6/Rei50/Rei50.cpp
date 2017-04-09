//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei50.h"
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
 *      質疑応答と決定木（配列表現）     *
 * ---------------------------------------
 */
#include <stdio.h>
#define Max 100
#define nil -1
struct tnode {
    int left;      /* 左へのポインタ */
	AnsiString node;  /* CString型で統一 */
    int right;     /* 右へのポインタ */
};
struct tnode a[Max]={{1  ,"芸能人ですか"  ,2},
					 {3  ,"歌手ですか"    ,4},
					 {nil,"吉田　茂"      ,nil},
					 {nil,"井上　陽水"    ,nil},
					 {5  ,"女優ですか"    ,6},
					 {nil,"中山　美穂"    ,nil},
                     {nil,"久米 宏"       ,nil}};
int lp=6;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	AnsiString ret;
	int p,c;
	do {
        p=0;
		while (a[p].left!=nil){          /* 木のサーチ */
			c=MessageDlg(a[p].node,mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES)
				p=a[p].left;
            else
                p=a[p].right;
		}
		c=MessageDlg("答えは"+a[p].node+"です",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);

        if (c==IDNO){               /* 学習機能 */
			a[lp+1]=a[p];                    /* ノードの移動 */
										   /* 新しいノードの作成 */
			ret=InputBox("","あなたの考えは","");
			a[lp+2].node=ret;
			a[lp+2].left=a[lp+2].right=nil;
							/* 質問ノードの作成 */
			ret=InputBox("",a[lp+1].node+"と"+a[lp+2].node+"を区別する質問は","");
			a[p].node=ret;
			c=MessageDlg("ｙｅｓの項目は"+a[lp+1].node+"で良いですか",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0);
			if (c==IDYES){          /* 子の接続 */
				a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
				a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
	} while (c=MessageDlg("続けますか",mtInformation,TMsgDlgButtons() << mbYes << mbNo,0),c==IDYES);

}
//---------------------------------------------------------------------------
