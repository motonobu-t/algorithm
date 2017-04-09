/*
 * -----------------------------------------
 *      基本グラフィックスライブラリ       *
 *     VisualC++, Visual C++ 2005/2008     *
 *       MFC MFCアプリケーション版         *
 *                                         *
 *   MFCのSetWindowExt,SetWindowOrgを      *
 *   利用したwindowが整数仕様のもの        *
 * -----------------------------------------
 */
#include <math.h>

CDC* gpDC;             /* デバイスコンテキスト */
CPen mypen(PS_SOLID,1,RGB(0,0,255)); /* 描画ペン */
double ANGLE,          /* 現在角   */
       LPX,LPY;        /* 現在位置 */

void window(double x1,double y1,double x2,double y2)
{
    /* 整数指定なのでwindow(-1,-1,1,1)のような小さな範囲を指定すると正常に動作しない */
    gpDC->SetWindowExt((int)(x2-x1),-(int)(y2-y1)); 
    gpDC->SetWindowOrg((int)x1,(int)y1);
}
void view(double x1,double y1,double x2,double y2)
{
    gpDC->SetViewportExt((int)(x2-x1),(int)(y2-y1));
    gpDC->SetViewportOrg((int)(x1),(int)(y2));
    CRgn clip;  /* クリップ領域の指定 */
    clip.CreateRectRgn((int)x1,(int)y1,(int)x2+1,(int)y2+1);
    gpDC->SelectObject(clip);
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
    gpDC->MoveTo((int)x1,(int)y1);
    gpDC->LineTo((int)x2,(int)y2);
    LPX=x2;LPY=y2;
}
void pset(double x,double y)
{
    gpDC->SetPixel((int)x,(int)y,RGB(0,0,255));
}
void move(double l)
{
    double x,y,rd=3.14159/180;
    x=l*cos(rd*ANGLE);y=l*sin(rd*ANGLE);
    gpDC->LineTo((int)(LPX+x),(int)(LPY+y));
    LPX=LPX+x;LPY=LPY+y;
}
void moveto(double x,double y)
{
    gpDC->LineTo((int)x,(int)y);
    LPX=x;LPY=y;
} 
void setpoint(double x,double y)
{
    gpDC->MoveTo((int)x,(int)y);
    LPX=x;LPY=y;
} 

#define setangle(a) ANGLE=(double)(a)
#define turn(a) ANGLE=fmod(ANGLE+(a),360.0)

#define ginit() Ginit(pDC)
