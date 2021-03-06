//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr63_1.h"
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
 * --------------------------
 *       樹木曲線その２     *
 * --------------------------
 */

#include "turboglib.h"

void ctree(int n,double x0,double y0,double leng,double angle)
                                  /* 樹木曲線の再帰手続き */
{
    double rd=3.14159/180;
    int k;

    if (n==0)
        return;

    setpoint(x0,y0);setangle(angle);
    for (k=1;k<=4;k++){        /* 正方形を描く */
        turn(90);
        move(leng);
    }

    ctree(n-1,x0+leng*cos((angle-45)*rd)/sqrt(2.0),  /* 右部分木 */
              y0+leng*sin((angle-45)*rd)/sqrt(2.0),
              leng/sqrt(2.0),angle-45);
    ctree(n-1,x0+sqrt(2.0)*leng*cos((angle+45)*rd),  /* 左部分木 */
              y0+sqrt(2.0)*leng*sin((angle+45)*rd),
              leng/sqrt(2.0),angle+45);
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int    n=9;               /* 枝の次数 */
    double x0=0.0,y0=50.0,    /* 根の位置 */
           leng=100.0,        /* 枝の長さ */
           angle=90.0;        /* 枝の向き */

    ginit(); cls();
    window(-640,-400,640,400);

    ctree(n,x0,y0,leng,angle);    /* 再帰呼び出し */
}
//---------------------------------------------------------------------------
