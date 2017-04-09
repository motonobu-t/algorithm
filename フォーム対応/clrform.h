/*
 * -----------------------------------------
 *          Visual C++ 2005/2008           *
 *  CLR Windows�t�H�[���A�v���P�[�V�����p  *
 *   �e�L�X�g���O���t�B�b�N�X�E���C�u����  *
 * -----------------------------------------
 */

Graphics^ gr;    /* �O���t�B�b�N�X�I�u�W�F�N�g */

double WX1,WY1,WX2,WY2,      /* ���[���h���W */
       VX1,VY1,VX2,VY2,      /* �r���[���W   */
       FACTX,FACTY,          /* �X�P�[��     */
       ANGLE,                /* �O���t�B�b�N�p���݊p   */
       LPX,LPY;              /* �O���t�B�b�N�p���݈ʒu */

float TLPX,TLPY;             /* �e�L�X�g�`�挻�݈ʒu */
System::Drawing::Font^ myfont;  /* �e�L�X�g�p�t�H���g */

/* ------------------------ */
/* �O���t�B�b�N�X���C�u���� */
/* ------------------------ */

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
void Ginit(void)
{
    LPX=0;LPY=0;ANGLE=0;
    window(0,0,639,399);
    view(0,0,639,399);
}
void cls(void)
{
    gr->Clear(this->BackColor); /* �o�b�N�J���[�ŏ��� */
    TLPX=TLPY=0;
    ANGLE=LPX=LPY=0;
}
void line(double x1,double y1,double x2,double y2)
{
    int px1,py1,px2,py2;
    px1=(int)((x1-WX1)*FACTX);
    py1=(int)((WY2-y1)*FACTY);
    px2=(int)((x2-WX1)*FACTX);
    py2=(int)((WY2-y2)*FACTY);
    gr->DrawLine(gcnew Pen(Color::Blue),px1,py1,px2,py2); /* �ŕ`�� */
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

#define ginit() gr=pictureBox1->CreateGraphics(),Ginit();
#define setangle(a) ANGLE=(double)(a)
#define turn(a) ANGLE=fmod(ANGLE+(a),360.0)

/* ----------------------- */
/*  �e�L�X�g�o�̓��C�u���� */
/* ----------------------- */

void Tinit(void)
{
    myfont=gcnew System::Drawing::Font("�l�r �S�V�b�N",10);
    TLPX=0;
    TLPY=0;
}
void Printf(char *format,...)
{
    char buf[80];
    int n;
    va_list ap;
    va_start(ap,format);
    n=vsprintf_s(buf,format,ap);
    va_end(ap);
    if (TLPX>=80*myfont->Height/2){
        TLPX=0;
        TLPY+=myfont->Height;
    }
    if (buf[strlen(buf)-1]=='\n') {
        buf[strlen(buf)-1]='\0';
        String^ cbuf=gcnew String(buf);
        gr->DrawString(cbuf,myfont,Brushes::Black,TLPX,TLPY);
        TLPY+=myfont->Height;
        TLPX=0;
    }
    else {
        String^ cbuf=gcnew String(buf);
        gr->DrawString(cbuf,myfont,Brushes::Black,TLPX,TLPY);
        TLPX+=n*myfont->Height/2;  /* �������������̔����Ɖ��� */
    }
}
void PrintfL(void)
{
    TLPY+=myfont->Height;
    TLPX=0;
}

#define tinit() gr=pictureBox1->CreateGraphics(),Tinit();
#define printf Printf
#define putchar(x) Printf("%c",x)

#define stoi(s) System::Int32::Parse(s)
#define stod(s) System::Double::Parse(s)
void stoc(String^ s,char *p)
{
    int i;
    array<unsigned char>^ buf = System::Text::Encoding::GetEncoding(L"Shift_JIS")->GetBytes(s);
    for (i=0;i<s->Length;i++)
        p[i]=(char)buf[i];
    p[i]='\0';
}