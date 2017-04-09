//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr61.h"
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
 * --------------------------------
 *      ÇRéüå≥ä÷êîÇÃâAê¸èàóù      *
 * --------------------------------
 */

#include "turboform.h"

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int ymin[640],ymax[640];
    int k,px,py;
    double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

    ginit(); cls();
    for (k=0;k<640;k++){        /* ç≈ëÂÅEç≈è¨îªíËîzóÒ */
        ymin[k]=399;ymax[k]=0;
    }
    cos_x=cos(30*rd);  sin_x=sin(30*rd);
    cos_y=cos(-30*rd); sin_y=sin(-30*rd);
    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x++){
            y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
            px=(int)(x*cos_y+z*sin_y+320);              /* âÒì]ïœä∑ */
            py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
            if (py<ymin[px]){               /* ç°Ç‹Ç≈ÇÃç≈è¨ÇÊÇËè¨Ç≥Ç¢ */
                ymin[px]=py;pset(px,py);
            }
            if (py>ymax[px]){               /* ç°Ç‹Ç≈ÇÃç≈ëÂÇÊÇËëÂÇ´Ç¢ */
                ymax[px]=py;pset(px,py);
            }
        }
	}
}
//---------------------------------------------------------------------------
