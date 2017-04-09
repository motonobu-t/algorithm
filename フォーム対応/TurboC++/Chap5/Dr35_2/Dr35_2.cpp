//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr35_2.h"
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
 * -----------------------------
 *      リストデータの探索     *
 * -----------------------------
 */

#include "turboform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} sentinel,*head=&sentinel;  // 初期化

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
	p->pointer=head;
	head=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	struct tfield *p;
	char key[32];
	stoc(Edit3->Text,key);
 
	strcpy(sentinel.name,key);      /* 番兵にキーを入れる */
    p=head;
    while (strcmp(p->name,key)!=0)
        p=p->pointer;
	tinit();cls();
    if (p!=&sentinel)
        printf("%s %s\n",p->name,p->tel);
    else
        printf("見つかりません\n");
}
//---------------------------------------------------------------------------
