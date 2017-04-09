/*
 * --------------------------
 *       ÷–Ø‹Èü‚»‚Ì‚Q     *
 * --------------------------
 */

#include "glib.h"

void ctree(int,double,double,double,double);

void main(void)
{
    int    n=9;               /* }‚ÌŸ” */
    double x0=0.0,y0=50.0,    /* ª‚ÌˆÊ’u */
           leng=100.0,        /* }‚Ì’·‚³ */
           angle=90.0;        /* }‚ÌŒü‚« */

    ginit(); cls();
    window(-640,-400,640,400);

    ctree(n,x0,y0,leng,angle);    /* Ä‹AŒÄ‚Ño‚µ */
}
void ctree(int n,double x0,double y0,double leng,double angle)
                                  /* ÷–Ø‹Èü‚ÌÄ‹Aè‘±‚« */
{
    double rd=3.14159/180;
    int k;

    if (n==0)
        return;

    setpoint(x0,y0);setangle(angle);
    for (k=1;k<=4;k++){        /* ³•ûŒ`‚ğ•`‚­ */
        turn(90);
        move(leng);
    }

    ctree(n-1,x0+leng*cos((angle-45)*rd)/sqrt(2.0),  /* ‰E•”•ª–Ø */
              y0+leng*sin((angle-45)*rd)/sqrt(2.0),
              leng/sqrt(2.0),angle-45);
    ctree(n-1,x0+sqrt(2.0)*leng*cos((angle+45)*rd),  /* ¶•”•ª–Ø */
              y0+sqrt(2.0)*leng*sin((angle+45)*rd),
              leng/sqrt(2.0),angle+45);
}
