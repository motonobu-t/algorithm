/*
 * ----------------------
 *      �Q�����͗l      *
 * ----------------------
 */

#include "glib.h"

void main(void)
{
    double leng=200.0,    /* �ӂ̏����l */
           angle=89.0,    /* ��]�p */
           step=1.0;      /* �ӂ̌����l */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
