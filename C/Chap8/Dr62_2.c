/*
 * ------------------------------
 *       �N���X�E�X�e�b�`       *
 * ------------------------------
 */

#include "glib.h"

void stech(int,double);

void main(void)
{
    int    k,
           n=4;         /* �X�e�b�`�̎��� */
    double leng=2.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(200,150); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(90);
    }
}
void stech(int n,double leng)       /* �X�e�b�`�̍ċA�葱�� */
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng);
    }
}
