//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei14_2.h"
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
 * -------------------------
 *      �K��̑����v�Z     *
 * -------------------------
 */

#include "turboform.h"

#define L 64               /* ���߂錅��      */
#define L2 ((L+3)/4)       /* �z��̃T�C�Y    */
void lmul(short a[],short b,short c[])    /* �����O���~�V���[�g�� */
{
    short i;long d,cy=0;
    for (i=L2-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}

void printresult(short c[])       /* ���ʂ̕\�� */
{
    short i;
    for (i=0;i<L2;i++)
        printf("%04d",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])
{
    short i,brrw=0;
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    short s[L2];
    short k;

    for (k=0;k<L2;k++)
        s[k]=0;

    s[L2-1]=1;
	tinit();cls();
    for (k=1;k<=49;k++){
        lmul(s,k,s);
        printf("%2d!=",k);
        printresult(s);
    }

}
//---------------------------------------------------------------------------
