/*
 * ------------------------------------------
 *      基本グラフィックスライブラリ        *
 *  TurboC++ VCLフォームアプリケーション版  *
 * ------------------------------------------
 */

#include <math.h>

TCanvas* gCanvas;            /* グラフィックオブジェクト */

double WX1,WY1,WX2,WY2,      /* ワールド座標 */
       VX1,VY1,VX2,VY2,      /* ビュー座標   */
       FACTX,FACTY,          /* スケール     */
       ANGLE,                /* 現在角       */
       LPX,LPY;              /* 現在位置     */

void window(double x1,double y1,double x2,double y2)
{
    WX1=x1; WY1=y1; WX2=x2; WY2=y2;
    FACTX=(VX2-VX1)/(WX2-WX1);
    FACTY=(VY2-VY1)/(WY2-WY1);
}
void view(int x1,int y1,int x2,int y2)
{
    VX1=(double)x1; VY1=(double)y1; VX2=(double)x2; VY2=(double)y2;
    FACTX=(VX2-VX1)/(WX2-WX1);
    FACTY=(VY2-VY1)/(WY2-WY1);
}
void Ginit(TCanvas* canvas)
{
    gCanvas=canvas;
    gCanvas->Pen->Color=clBlue; // 青のペン
    LPX=0;LPY=0;ANGLE=0;
    window(0,0,639,399);
    view(0,0,639,399);
}
void Cls(int x,int y)
{
    gCanvas->Brush->Style=bsSolid;
    gCanvas->FillRect(Rect(0,0,x,y));
}
void line(double x1,double y1,double x2,double y2)
{
    int px1,py1,px2,py2;
    px1=(int)((x1-WX1)*FACTX+VX1);
    py1=(int)((WY2-y1)*FACTY+VY1);
    px2=(int)((x2-WX1)*FACTX+VX1);
    py2=(int)((WY2-y2)*FACTY+VY1);
    gCanvas->MoveTo(px1,py1);
    gCanvas->LineTo(px2,py2);
    LPX=x2;LPY=y2;
}
void pset(double x,double y)
{
    int px,py;
    line(x,y,x+1,y);
    LPX=x;LPY=y;
}
void move(double l)
{
    double x,y,rd=3.1415927/180;
    x=l*cos(rd*ANGLE);y=l*sin(rd*ANGLE);
    line(LPX,LPY,LPX+x,LPY+y);
}
void moveto(double x,double y)
{
    line(LPX,LPY,x,y);
}
void setpoint(double x,double y)
{
    LPX=x;LPY=y;
}

#define setangle(a) ANGLE=(double)(a)
#define turn(a) ANGLE=fmod(ANGLE+(a),360.0)

#define ginit() Ginit(Canvas)
#define cls() Cls(ClientWidth,ClientHeight)
