//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr11.h"
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
 * -----------------------
 *      �j���[�g���@     *
 * -----------------------
 */

#include "turboform.h"

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)
#define EPS  1e-8               /* �ł��؂�덷 */
#define LIMIT 50                /* �ł��؂�� */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x=-2.0,dx;
    int k;
	tinit();cls();
    for (k=1;k<=LIMIT;k++) {
        dx=x;
        x=x-f(x)/g(x);
        if (fabs(x-dx)<fabs(dx)*EPS) {
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("�������Ȃ�\n");
}
//---------------------------------------------------------------------------
