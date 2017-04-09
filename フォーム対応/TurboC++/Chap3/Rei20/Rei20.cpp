//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei20.h"
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
 *      逐次探索法     *
 * ---------------------
 */

#include "turboform.h"

#define N 10       /* データ数　*/
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct girl {
        char name[20];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
	char key[20];
    int i;

	stoc(Edit1->Text,key);

    i=0;
    while (i<N && strcmp(key,a[i].name)!=0)
        i++;

	tinit();cls();
    if (i<N)
        printf("%s %d\n",a[i].name,a[i].age);
    else
        printf("見つかりませんでした\n");

}
//---------------------------------------------------------------------------
