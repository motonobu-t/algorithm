//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr7_1.h"
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
 *       ÇQÅ`ÇmÇÃíÜÇ©ÇÁëfêîÇèEÇ¢èoÇ∑      *
 * -----------------------------------------
 */

#include "turboform.h"

#define NUM 1000
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int prime[NUM/2+1];
    int i,n,m=0,Limit;

    for (n=2;n<=NUM;n++){
        Limit=(int)sqrt((double)n);
        for (i=Limit;i>1;i--){
            if (n%i == 0)
                break;
        }
        if (i==1)
            prime[m++]=n;
    }

	tinit();cls();
    printf("\nãÅÇﬂÇÁÇÍÇΩëfêî\n");
	for (i=0;i<m;i++)
        printf("%5d",prime[i]);

}
//---------------------------------------------------------------------------
