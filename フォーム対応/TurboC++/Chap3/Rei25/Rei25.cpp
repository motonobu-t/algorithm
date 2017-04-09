//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei25.h"
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
 * -------------------
 *      ハッシュ     *
 * -------------------
 */

#include "turboform.h"

#define TableSize 1000
#define ModSize   1000

struct tel{             /* データ・テーブル */
    char name[12];
    char telnum[12];
} dat[TableSize];

int hash(char *s)    /* ハッシュ関数 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
    char a[12],b[12];
	stoc(Edit1->Text,a);
	stoc(Edit2->Text,b);

    n=hash(a);
	strcpy(dat[n].name,a);
    strcpy(dat[n].telnum,b);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int n;
	char a[12];
	tinit();cls();
	stoc(Edit3->Text,a);

	n=hash(a);
    printf("%15s%15s\n",dat[n].name,dat[n].telnum);

}
//---------------------------------------------------------------------------
