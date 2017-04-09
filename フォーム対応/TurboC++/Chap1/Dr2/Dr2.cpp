//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr2.h"
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
 * ---------------------
 *      à√çÜÇÃâì«     *
 * ---------------------
 */

#include "turboform.h"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char table[]={'Q','W','E','R','T','Y','U','I','O','P',
                  'A','S','D','F','G','H','J','K','L','Z',
                  'X','C','V','B','N','M','?'};
    char *p,*ango="KSOIDHEPZ";
    int index;
	tinit();cls();
    p=ango;
    while (*p!='\0'){
        if ('A'<=*p && *p<='Z')
            index=*p-'A';
        else
            index=26;
        putchar(table[index]);
        p++;
    }
    printf("\n");
}
//---------------------------------------------------------------------------
