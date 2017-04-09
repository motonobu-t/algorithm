//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei36.h"
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
 *      リストデータの削除     *
 * -----------------------------
 */

#include "turboform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head=NULL;
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
	struct tfield *p,*old;
	char key[20];
	stoc(Edit3->Text,key);

	p=old=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            if (p==head)
                head=p->pointer;
            else
                old->pointer=p->pointer;
            return;
        }
        old=p;
        p=p->pointer;
    }
	tinit();cls();
    printf("キーデータが見つかりません\n");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	struct tfield *p;
	tinit();cls();
	p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
//---------------------------------------------------------------------------
