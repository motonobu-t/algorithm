/*
 * --------------------------------
 *     ��l�����i���`�����@�j     *
 * --------------------------------
 */

#include <stdio.h>

unsigned rndnum=13;        /* �����̏����l */

unsigned irnd(void);

void main(void)
{
    int j;
    for (j=0;j<100;j++){
        printf("%8d",irnd());
    }
    printf("\n");
}
unsigned irnd(void)        /* 0�`32767�̐������� */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}