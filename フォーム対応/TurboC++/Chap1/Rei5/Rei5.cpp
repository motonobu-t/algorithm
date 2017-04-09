//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei5.h"
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
 *     ƒ‚ƒ“ƒeƒJƒ‹ƒ–@‚É‚æ‚éƒÎ‚ÌŒvZ   *
 * ------------------------------------
 */

#include "turboform.h"

#define NUM 1000
double rnd(void)        /* ‚O`‚P‚Ì—” */
{
	return (double)rand()/(RAND_MAX+0.1);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x,y,pai;
    int i,in=0;

    for (i=1;i<=NUM;i++){
        x=rnd();
        y=rnd();
        if (x*x+y*y<=1)
            in++;
    }
    pai=(double)4*in/NUM;

	tinit();cls();
    printf("ƒÎ‚Ì’l=%f\n",pai);

}
//---------------------------------------------------------------------------
