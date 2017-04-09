//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei24.h"
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
 * -----------------------------------------
 *      文字列の置き換え（リプレイス）     *
 * -----------------------------------------
 */

#include "turboform.h"
char *search(char *text,char *key) //この関数を先に置く
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
void replace(char *text,char *key,char *rep)
{
    char *p;
    int i;
    p=search(text,key);
    while (p!=NULL){
        for (i=0;i<(int)strlen(rep);i++)      /* 置き換え */
            p[i]=rep[i];
        p=search(p+strlen(key),key);
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    static char text[]="This is a pen. That is a pencil.";
	tinit();cls();
    replace(text,"pen","cap");      /* 同じ長さであること */
    printf("%s\n",text);

}
//---------------------------------------------------------------------------
