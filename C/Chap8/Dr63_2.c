/*
 * -----------------
 *      �b�Ȑ�     *
 * -----------------
 */

#include "glib.h"

void ccurve(int);

void main(void)
{
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    ccurve(n);
}
void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}
