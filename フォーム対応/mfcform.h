/*
 * ----------------------------------------------
 *    �@ VisualC++, Visual C++ 2005/2008        *
 *   MFC MFC�A�v���P�[�V������FormView�N���X�p  *
 *    �e�L�X�g���O���t�B�b�N�X�E���C�u����      *       
 * ----------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

CDC* gpDC;           /* �f�o�C�X�R���e�L�X�g   */
CPen mypen(PS_SOLID,1,RGB(0,0,255)); /* �`��y�� */
double WX1,WY1,WX2,WY2,      /* ���[���h���W */
       VX1,VY1,VX2,VY2,      /* �r���[���W   */
       FACTX,FACTY,          /* �X�P�[��     */
       ANGLE,                /* ���݊p       */
       LPX,LPY;              /* ���݈ʒu     */

int TLPX,TLPY;      /* �e�L�X�g�`�挻�݈ʒu   */
CFont myfont,*oldf; /* �t�H���g               */
LOGFONT lf;         /* �t�H���g�����\����     */
CRect clientR;	    /* �s�N�`���[�{�b�N�X�̈� */

/* ------------------------- */
/*  �O���t�B�b�N�X���C�u���� */
/* ------------------------- */

void window(double x1,double y1,double x2,double y2)
{
    WX1=x1; WY1=y1; WX2=x2; WY2=y2;
    FACTX=(VX2-VX1)/(WX2-WX1);
    FACTY=(VY2-VY1)/(WY2-WY1);
}
void view(double x1,double y1,double x2,double y2)
{
    CRgn clip;  /* �N���b�v�̈�̎w�� */
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
        // �㏈�����s���Ȃ�e�`�揈���̂Ƃ���ňȉ��̂悤�ɂ���
        // CPen* oldp=gpDC->SelectObject(&mypen);
        // �`�揈��
        // gpDC->SelectObject(oldp);
    window(0,0,clientR.right-clientR.left,clientR.bottom-clientR.top);
    view(0,0,clientR.right-clientR.left,clientR.bottom-clientR.top);
    CRgn clip;  /* �N���b�v�̈�̎w�� */
    clip.CreateRectRgn(clientR.left+1,clientR.top+1,clientR.right-1,clientR.bottom-1);
    gpDC->SelectObject(clip);
}
void cls(void)
{
    gpDC->FillSolidRect(clientR,GetSysColor(COLOR_BTNFACE)); 
        //GetSysColor(COLOR_BTNFACE)�͂RD�R���g���[���̕\�ʐF
        //gpDC->GetBkColor()�͔� 

    TLPX=1;TLPY=0;
    ANGLE=LPX=LPY=0;
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
    double x,y,rd=3.14159/180;
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

#define ginit()  pict.GetClientRect(clientR),Ginit(pict.GetDC())    /* FormView�p */

//�s�N�`���[�R���g���[���Ƀ����o�ϐ������蓖�ĂȂ��Ȃ��̂P�s���ȉ��ɕς���
//CStatic *pict;
//#define ginit() pict=(CStatic *)GetDlgItem(IDC_PICT),pict->GetClientRect(clientR),Ginit(pict->GetDC())

/* ----------------------- */
/*  �e�L�X�g�o�̓��C�u���� */
/* ----------------------- */

void Tinit(CDC* p)
{
    gpDC=p;
    CString family("�l�r �S�V�b�N");  /* �t�H���g�̎w�� */
    myfont.CreateFont(14,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,
        SHIFTJIS_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,FIXED_PITCH|FF_MODERN,family);
    oldf=gpDC->SelectObject(&myfont);
    myfont.GetLogFont(&lf);

    //myfont�𐶐�������̂R�����ȉ��ő�p����΁Atfin()�����͕s�v
    //oldf=(CFont*)gpDC->SelectStockObject(SYSTEM_FIXED_FONT);
    //oldf->GetLogFont(&lf);
    //

    CRgn clip;    /* �N���b�v�̈�̎w�� */
    clip.CreateRectRgn(clientR.left+1,clientR.top+1,clientR.right-1,clientR.bottom-1);
    gpDC->SelectObject(clip);

    TLPX=1;TLPY=0;  // TLPX=0���ƍ��[��������
}
void tfin(void)
{
    gpDC->SelectObject(oldf);
    myfont.DeleteObject();
}
void Printf(char *format,...)
{
    char buf[80];
    int n;
    va_list ap;
    va_start(ap,format);
    n=vsprintf_s(buf,format,ap); /* vsprintf�̈�����CString��v�����邽�� */
    va_end(ap);
    if (TLPX>=80*lf.lfHeight/2){  /* 80�����𒴂����� */
        TLPX=1;
        TLPY+=lf.lfHeight;
    }
    if (buf[strlen(buf)-1]=='\n') {  /* ���s�R�[�h������ꍇ */
        buf[strlen(buf)-1]='\0';
        CString cbuf(buf);
        gpDC->TextOut(TLPX,TLPY,cbuf);
        TLPY+=lf.lfHeight;
        TLPX=1;
    }
    else {
        CString cbuf(buf);
        gpDC->TextOut(TLPX,TLPY,cbuf);
        TLPX+=n*lf.lfHeight/2;  /* �������������̔����Ɖ��� */
    } 
}
void PrintL(void)
{
    TLPY+=lf.lfHeight;
    TLPX=1;
}

#define tinit() pict.GetClientRect(clientR),Tinit(pict.GetDC())

//�s�N�`���[�R���g���[���Ƀ����o�ϐ������蓖�ĂȂ��Ȃ��̂P�s���ȉ��ɕς���
//#define tinit() pict=(CStatic *)GetDlgItem(IDC_PICT),pict->GetClientRect(clientR),Tinit(pict->GetDC())


#define printf Printf
#define putchar(x) Printf("%c",x)

void stoc(CString s,char *p) /* CString->char�z�� */
{
    int i;
    for (i=0;i<s.GetLength();i++)
        p[i]=(char)s.GetAt(i);  /* wchar_t->char�ϊ� */
    p[i]='\0';
}
int stoi(CString s)  /* CString->int�l */
{
    char buf[80];
    char *tailptr;
    stoc(s,buf);
    return (int)strtol(buf,&tailptr,10);
}
double stod(CString s)  /* CString->double�l */
{
    char buf[80];
    char *tailptr;
    stoc(s,buf);
    return strtod(buf,&tailptr);
}
