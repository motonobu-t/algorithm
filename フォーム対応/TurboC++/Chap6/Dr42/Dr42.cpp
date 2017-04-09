//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr42.h"
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
 * -----------------------------------
 *      �Q���T���؂ւ̃f�[�^�ǉ�     *
 * -----------------------------------
 */

#include "turboform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};

int sp=8;               /* �m�[�h�̊i�[���݈ʒu */
struct tnode a[MaxSize]={{  1,"Machilda",  2},
                         {  3,"Candy",  4},
                         {  5,"Rolla"   ,nil},
                         {nil,"Ann"  ,nil},
                         {  6,"Emy"     ,  7},
                         {nil,"Nancy",nil},
                         {nil,"Eluza"   ,nil},
                         {nil,"Lisa" ,nil}};

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char key[12];
    int p,old,i;

	stoc(Edit1->Text,key);
    p=0;                                /* �؂̃T�[�` */
    while (p!=nil){
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* �V�����m�[�h�̐ڑ� */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;

	tinit();cls();
    for (i=0;i<sp;i++)                  /* �m�[�h�E�e�[�u���̕\�� */
        printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);

}
//---------------------------------------------------------------------------
