//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr23.h"
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
 * ---------------------------------------------------
 *      文字列の照合（Ｂｏｙｅｒ－Ｍｏｏｒｅ法）     *
 * ---------------------------------------------------
 */

#include "turboform.h"

int skip[256];
void table(char *key)      /* スキップ・テーブルの作成 */
{
    int k,n;

    n=strlen(key);
    for (k=0;k<=255;k++)
        skip[k]=n;
    for (k=0;k<n-1;k++)
        skip[key[k]]=n-1-k;
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);

    p=text+n-1;
    while (p<text+m){
        if (*p==key[n-1]){                   /* 右端の文字だけ比較 */
            if (strncmp(p-n+1,key,n)==0)     /* キー全体を比較     */
                return p-n+1;
        }
        p=p+skip[*p];                        /* サーチ位置を進める */
    }
    return NULL;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";
	tinit();cls();
    table(key);
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
	}
}
//---------------------------------------------------------------------------
