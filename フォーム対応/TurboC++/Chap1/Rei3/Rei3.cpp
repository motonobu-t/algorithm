//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei3.h"
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
 *      順位付け     *
 * -------------------
 */

#include "turboform.h"

#define Num 10
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={56,25,67,88,100,61,55,67,76,56};
    int juni[Num];
    int i,j;

    for (i=0;i<Num;i++){
        juni[i]=1;
        for (j=0;j<Num;j++){
            if (a[j]>a[i])
                juni[i]++;
        }
    }

	tinit();cls();
    printf("　得点　順位\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[i]);
    }
}
//---------------------------------------------------------------------------
