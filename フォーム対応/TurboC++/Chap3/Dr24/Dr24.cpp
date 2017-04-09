//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr24.h"
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
 * ----------------------------------------
 *     文字列の置き換え（リプレイス）     *
 * ----------------------------------------
 */

#include "turboform.h"
char *search(char *text,char *key)  // この関数を先に置く
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
    char *p,buf[128];

    p=search(text,key);
    while (p!=NULL){
        *p='\0';
        strcpy(buf,p+strlen(key));
        strcat(text,rep);
        strcat(text,buf);
        p=search(p+strlen(rep),key);
    }
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int k;
    static char text[][128]={"     --- サルビアの花 ---",
                             "いつもいつも思ってた",
                             "サルビアの花をあなたの部屋の中に",
                             "投げ入れたくて",
                             "そして君のベッドに",
                             "サルビアの紅い花しきつめて",
                             "僕は君を死ぬまで抱きしめていようと",
                             ""};
	tinit();cls();
    k=0;
    while (text[k][0]!='\0'){
        replace(text[k],"サルビア","か す み 草");
        replace(text[k],"紅","白");
        printf("%s\n",text[k]);
        k++;
	}
}
//---------------------------------------------------------------------------
