/*
 * -----------------------------------------
 *      ��{�O���t�B�b�N�X���C�u����       *
 *     VisualC++, Visual C++ 2005/2008     *
 *       MFC MFC�A�v���P�[�V������         *
 *                                         *
 *   MFC��SetWindowExt,SetWindowOrg��      *
 *   ���p����window�������d�l�̂���        *
 * -----------------------------------------
 */
#include <math.h>

CDC* gpDC;             /* �f�o�C�X�R���e�L�X�g */
CPen mypen(PS_SOLID,1,RGB(0,0,255)); /* �`��y�� */
double ANGLE,          /* ���݊p   */
       LPX,LPY;        /* ���݈ʒu */

void window(double x1,double y1,double x2,double y2)
{
    /* �����w��Ȃ̂�window(-1,-1,1,1)�̂悤�ȏ����Ȕ͈͂��w�肷��Ɛ���ɓ��삵�Ȃ� */
    gpDC->SetWindowExt((int)(x2-x1),-(int)(y2-y1)); 
    gpDC->SetWindowOrg((int)x1,(int)y1);
}
void view(double x1,double y1,double x2,double y2)
{
    gpDC->SetViewportExt((int)(x2-x1),(int)(y2-y1));
    gpDC->SetViewportOrg((int)(x1),(int)(y2));
    CRgn clip;  /* �N���b�v�̈�̎w�� */
    clip.CreateRectRgn((int)x1,(int)y1,(int)x2+1,(int)y2+1);
    gpDC->SelectObject(clip);
}
void Ginit(CDC* p)
{
    gpDC=p;
    gpDC->SetMapMode(MM_ANISOTROPIC);
    gpDC->SelectObject(&mypen);
        // �㏈�����s���Ȃ�e�`�揈���̂Ƃ���ňȉ��̂悤�ɂ���
        // CPen* oldp=gpDC->SelectObject(&mypen);
        // �`�揈��
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
