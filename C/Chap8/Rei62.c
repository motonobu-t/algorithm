/*
 * -----------------------
 *       �R�b�z�Ȑ�      *
 * -----------------------
 */

#include "glib.h"

void koch(int,double);

void main(void)
{
    int    n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);
}
void koch(int n,double leng)        /* �R�b�z�Ȑ��̍ċA�葱�� */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}
