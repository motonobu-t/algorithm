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
 *       ���؋Ȑ����̂Q     *
 * --------------------------
 */

#include "turboform.h"
void ctree(int n,double x0,double y0,double leng,double angle)
                                  /* ���؋Ȑ��̍ċA�葱�� */
{
    double rd=3.14159/180;
    int k;

    if (n==0)
        return;

    setpoint(x0,y0);setangle(angle);
    for (k=1;k<=4;k++){        /* �����`��`�� */
        turn(90);
        move(leng);
    }

    ctree(n-1,x0+leng*cos((angle-45)*rd)/sqrt(2.0),  /* �E������ */
              y0+leng*sin((angle-45)*rd)/sqrt(2.0),
              leng/sqrt(2.0),angle-45);
    ctree(n-1,x0+sqrt(2.0)*leng*cos((angle+45)*rd),  /* �������� */
              y0+sqrt(2.0)*leng*sin((angle+45)*rd),
              leng/sqrt(2.0),angle+45);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int    n=9;               /* �}�̎��� */
    double x0=0.0,y0=50.0,    /* ���̈ʒu */
           leng=100.0,        /* �}�̒��� */
           angle=90.0;        /* �}�̌��� */

    ginit(); cls();
    window(-640,-400,640,400);

	ctree(n,x0,y0,leng,angle);    /* �ċA�Ăяo�� */
}
//---------------------------------------------------------------------------
