/*
 * -----------------------------------------
 *      基本グラフィックスライブラリ       *
 *         Visual C++ 2005/2008            *
 *  CLR Windowsフォームアプリケーション版  *
 * -----------------------------------------
 */

Graphics^ gr;    /* グラフィックスオブジェクト */

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
    gr->ResetTransform();
    gr->TranslateTransform((float)(x1),(float)(y1));
    gr->SetClip(Rectangle(0,0,(int)(x2-x1),(int)(y2-y1)));

    VX1=x1; VY1=y1; VX2=x2; VY2=y2;
    FACTX=(VX2-VX1)/(WX2-WX1);
    FACTY=(VY2-VY1)/(WY2-WY1);
}

void ginit(void)
{
    gr=this->CreateGraphics();
    LPX=0;LPY=0;ANGLE=0;
    window(0,0,639,399);
    view(0,0,639,399);
}
void cls(void)
{
    gr->Clear(this->BackColor); /* バックカラーで消去 */
}
void line(double x1,double y1,double x2,double y2)
{
    int px1,py1,px2,py2;
    px1=(int)((x1-WX1)*FACTX);
    py1=(int)((WY2-y1)*FACTY);
    px2=(int)((x2-WX1)*FACTX);
    py2=(int)((WY2-y2)*FACTY);
    gr->DrawLine(gcnew Pen(Color::Blue),px1,py1,px2,py2); /* 青で描画 */
    LPX=x2;LPY=y2;
}
void pset(double x,double y)
{
    int px,py;
    px=(int)((x-WX1)*FACTX);
    py=(int)((WY2-y)*FACTY);
    gr->FillRectangle(gcnew SolidBrush(Color::Blue),px,py,1,1);
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
