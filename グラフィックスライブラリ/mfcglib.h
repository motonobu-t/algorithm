/*
 * -----------------------------------------
 *      基本グラフィックスライブラリ       *
 *     VisualC++, Visual C++ 2005/2008     *
 *       MFC MFCアプリケーション版         *
 * -----------------------------------------
 */
#include <math.h>

CDC* gpDC;             /* デバイスコンテキスト */
CPen mypen(PS_SOLID,1,RGB(0,0,255)); /* 描画ペン */

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
void view(double x1,double y1,double x2,double y2)
{
    CRgn clip;  /* クリップ領域の指定 */
    clip.CreateRectRgn((int)x1,(int)y1,(int)x2+1,(int)y2+1);
    gpDC->SelectObject(clip);
    VX1=x1; VY1=y1; VX2=x2; VY2=y2;
    FACTX=(VX2-VX1)/(WX2-WX1);
    FACTY=(VY2-VY1)/(WY2-WY1);
}
void Ginit(CDC* p)
{
    gpDC=p;
    gpDC->SetMapMode(MM_ANISOTROPIC);
    gpDC->SelectObject(&mypen);
        // 後処理も行うなら各描画処理のところで以下のようにする
        // CPen* oldp=gpDC->SelectObject(&mypen);
        // 描画処理
        // gpDC->SelectObject(oldp);
    window(0,0,639,399);
    view(0,0,639,399);
}
void cls(void)
{
    CRect r;
    gpDC->GetClipBox(&r);
    gpDC->FillSolidRect(r,gpDC->GetBkColor()); 
}
void line(double x1,double y1,double x2,double y2)
{
    int px1,py1,px2,py2;
    px1=(int)((x1-WX1)*FACTX+VX1);
    py1=(int)((WY2-y1)*FACTY+VY1);
    px2=(int)((x2-WX1)*FACTX+VX1);
    py2=(int)((WY2-y2)*FACTY+VY1);
    gpDC->MoveTo(px1,py1);
    gpDC->LineTo(px2,py2);
    LPX=x2;LPY=y2;
}
void pset(double x,double y)
{
    int px,py;
    px=(int)((x-WX1)*FACTX);
    py=(int)((WY2-y)*FACTY);
    gpDC->SetPixel(px,py,RGB(0,0,255));
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

#define ginit() Ginit(pDC)
