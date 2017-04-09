//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr7_2.h"
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
 * ---------------------------------------
 *        エラトステネスのふるい         *
 * ---------------------------------------
 */

#include "turboform.h"

#define NUM 1000
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int prime[NUM+1];
    int i,j,Limit;

    for (i=2;i<=NUM;i++)
        prime[i]=1;

    Limit=(int)sqrt((double)NUM);
    for (i=2;i<=Limit;i++){
        if (prime[i]==1){
            for (j=2*i;j<=NUM;j++){
                if (j%i==0)
                    prime[j]=0;
            }
        }
    }

	tinit();cls();
    printf("\n求められた素数\n");
	for (i=2;i<=NUM;i++){
		if (prime[i]==1)
            printf("%5d",i);
	}
    printf("\n");
}
//---------------------------------------------------------------------------
