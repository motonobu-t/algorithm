//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei41.h"
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
 *      リストを用いたハッシュ（先頭に追加）     *
 * -----------------------------------------------
 */

#include "turboform.h"

#define TableSize 1000
#define ModSize   1000

struct tfield{
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];               /* ポインタ・テーブル */
int hash(char *s)    /* ハッシュ関数 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	struct tfield *p;
	p=talloc();
	stoc(Edit1->Text,p->name);
	stoc(Edit2->Text,p->tel);
	n=hash(p->name);         /* ハッシング */
    p->pointer=dat[n];       /* 先頭に追加 */
    dat[n]=p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int n;
	char key[32];
	struct tfield *p;
	stoc(Edit3->Text,key);
	n=hash(key);
    p=dat[n];
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0)
            printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
//---------------------------------------------------------------------------
