//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei42.h"
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
 * -------------------------------
 *      �Q���T���؂̔z��\��     *
 * -------------------------------
 */

#include "turboform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    struct tnode a[MaxSize]={{  1,"Machilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[12];
    int p;

	stoc(Edit1->Text,key);
	tinit();cls();
    p=0;
    while (p!=nil){
        if (strcmp(key,a[p].name)==0){
            printf("������܂���\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* �������؂ֈړ� */
        else
            p=a[p].right;                   /* �E�����؂ֈړ� */
    }

}
//---------------------------------------------------------------------------
