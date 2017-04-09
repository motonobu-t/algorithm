//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr9.h"
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
 * -----------------------------
 *      ƒVƒ“ƒvƒ\ƒ“‚Ì’èÏ•ª     *
 * -----------------------------
 */

#include "turboform.h"

#define f(x) (sqrt(4-(x)*(x)))   /* ”íÏ•ªŠÖ” */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int k;
    double a,b,n,h,fo,fe,sum;

	a=stod(Edit1->Text);
	b=stod(Edit2->Text);

    n=50;              /* ‚`‚‚ŠÔ‚Ì•ªŠ„” */
    h=(b-a)/(2*n);     /* ‹æŠÔ• */
    fo=0; fe=0;
    for (k=1;k<=2*n-3;k=k+2){
        fo=fo+f(a+h*k);         /* Šï”€‚Ì˜a */
        fe=fe+f(a+h*(k+1));     /* ‹ô”€‚Ì˜a */
    }
    sum=(f(a)+f(b)+4*(fo+f(b-h))+2*fe)*h/3;

	tinit();cls();
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);

}
//---------------------------------------------------------------------------
