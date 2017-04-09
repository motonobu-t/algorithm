//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei37.h"
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
 * -----------------------------------
 *      双方向リストデータの作成     *
 * -----------------------------------
 */

#include "turboform.h"

struct tfield {
    struct tfield *left;    /* 逆ポインタ */
    char name[20];          /* 名前       */
    char tel[20];           /* 電話番号   */
    struct tfield *right;   /* 順ポインタ */
} *head,*tail=NULL;

struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	struct tfield *p;
	p=talloc();
	stoc(Edit1->Text,p->name);
	stoc(Edit2->Text,p->tel);
	p->left=tail;
    tail=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tfield *p;
	p=tail;                 /* 順リストの作成 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

	tinit();cls();
    printf("順方向リスト\n");
    p=head;                 /* リストの順表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("逆方向リスト\n");
    p=tail;                 /* リストの逆表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
}
//---------------------------------------------------------------------------
