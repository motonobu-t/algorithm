/*
 * ----------------------
 *      ‰QŠª‚«–Í—l      *
 * ----------------------
 */

#include "glib.h"

void main(void)
{
    double leng=200.0,    /* •Ó‚Ì‰Šú’l */
           angle=89.0,    /* ‰ñ“]Šp */
           step=1.0;      /* •Ó‚ÌŒ¸­’l */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
