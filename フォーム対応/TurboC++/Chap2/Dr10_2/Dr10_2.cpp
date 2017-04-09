//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr10_2.h"
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
 *      �e�C���[�W�J�i�������i���j�j     *
 * ---------------------------------------
 */

#include "turboform.h"

double mycos(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d;
    int k;

    x=fmod(x,2*3.14159265358979);      /* ���̒l���O�`�Q�΂Ɏ��߂� */
    for (k=1;k<=200;k=k+2) {
        d=s;
        e=-e*x*x/(k*(k+1));
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d))     /* �ł��؂�덷 */
            return s;
    }
    return 9999.0;                     /* �������Ȃ��Ƃ� */
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x,rd=3.14159/180;
	tinit();cls();
    printf("    x      mycos(x)        cos(x)\n");
    for (x=0;x<=180;x=x+10)
        printf("%5.1f%14.6f%14.6f\n",x,mycos(x*rd),cos(x*rd));

}
//---------------------------------------------------------------------------
