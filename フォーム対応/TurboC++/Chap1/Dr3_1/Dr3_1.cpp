//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr3_1.h"
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
 * ----------------------------
 *      順位付け（改良版）    *
 * ----------------------------
 */

#include "turboform.h"

#define Num 10
#define Max 100
#define Min 0
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={56,25,67,88,100,61,55,67,76,56};
    int i,juni[Max+2];
    for (i=Min;i<=Max;i++)
        juni[i]=0;

    for (i=0;i<Num;i++)
        juni[a[i]]++;

    juni[Max+1]=1;
    for (i=Max;i>=Min;i--)
        juni[i]=juni[i]+juni[i+1];

	tinit();cls();
    printf("　得点　順位\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[a[i]+1]);
    }
}
//---------------------------------------------------------------------------
