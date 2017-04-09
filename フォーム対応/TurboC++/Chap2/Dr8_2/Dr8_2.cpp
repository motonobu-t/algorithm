//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr8_2.h"
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
 * -------------------------------------------
 *      ���K�����i�{�b�N�X�E�~�����[�@�j     *
 * -------------------------------------------
 */

#include "turboform.h"

void brnd(double sig,double m,double *x,double *y)
{
    double r1,r2;
    r1=rand()/(RAND_MAX+0.1); r2=rand()/(RAND_MAX+0.1);
    *x=sig*sqrt(-2*log(r1))*cos(2*3.14159*r2)+m;
    *y=sig*sqrt(-2*log(r1))*sin(2*3.14159*r2)+m;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j,hist[100];
    double x,y;

    for (i=0;i<100;i++)
        hist[i]=0;

    for (i=0;i<1000;i++){
        brnd(2.5,10.0,&x,&y);
        hist[(int)x]++;
        hist[(int)y]++;
    }

	tinit();cls();
    for (i=0;i<=20;i++){            /* �q�X�g�E�O�����̕\�� */
        printf("%3d : I ",i);
        for (j=1;j<=hist[i]/10;j++){
            printf("*");
        }
        printf("\n");
    }

}
//---------------------------------------------------------------------------
