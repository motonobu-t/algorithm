/*
 * -------------------
 *      ‡•‚Q•ªŠ„     *
 * -------------------
 */

#include "glib.h"

void main(void)
{
    int k;
    double leng=400.0,            /* ‘ÎŠpü‚Ì‰Šú’l */
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 /* ‘ÎŠpü‚ğˆø‚­ */
        x=leng*cos(54.7*rd);        /* ‚˜•ûŒü‚Ì’·‚³ */
        y=leng*sin(54.7*rd);        /* ‚™•ûŒü‚Ì’·‚³ */
        turn(180-35.3); move(y);    /* ’·•ûŒ`‚ğ•`‚­ */
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}
