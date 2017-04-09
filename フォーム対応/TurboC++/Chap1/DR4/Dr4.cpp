//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr4.h"
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
 * ------------------------------------
 *      ƒ‰ƒ“ƒ_ƒ€‚È‡—ñi‰ü—Ç”Åj      *
 * ------------------------------------
 */

#include "turboform.h"

#define N 20
int irnd(int n)        /* ‚P`‚‚Ì—” */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j,d,a[N+1];

	for (i=1;i<=N;i++)
        a[i]=i;

    for (i=N;i>1;i--){
        j=irnd(i-1);
        d=a[i];a[i]=a[j];a[j]=d;
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
}
//---------------------------------------------------------------------------
