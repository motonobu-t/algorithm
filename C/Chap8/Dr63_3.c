/*
 * ---------------------------
 *      �h���S���E�J�[�u     *
 * ---------------------------
 */

#include "glib.h"

void dragon(int,double);

void main(void)
{
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    dragon(n,90);
}
void dragon(int n,double a)
{
    if (n==0){
        move(5);
    }
    else {
        dragon(n-1,90);
        turn(a);
        dragon(n-1,-90);
    }
}
