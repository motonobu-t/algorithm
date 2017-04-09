//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei23.h"
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
 * -------------------------------------
 *      文字列の照合（単純な方法）     *
 * -------------------------------------
 */

#include "turboform.h"

char *search(char *text,char *key)
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";
	tinit();cls();
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }

}
//---------------------------------------------------------------------------
