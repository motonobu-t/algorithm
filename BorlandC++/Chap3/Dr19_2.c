/*
 * ----------------------------------------
 *      �V�F���E�\�[�g�i���Ǒ}���@ �j     *
 * ----------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* �f�[�^�� */

void main(void)
{
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        /* �m�̗��� */
        a[i]=rand();
                            /* �m��菬�����͈͂ōő�̂����������߂� */
    for (gap=1;gap<N/3;gap=3*gap+1)
        ;

    while (gap>0){
        for (i=gap;i<N;i++){
            for (j=i-gap;j>=0;j=j-gap){
                if (a[j]>a[j+gap]){
                    t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                }
                else
                    break;
            }
        }
        gap=gap/3;             /* �M���b�v���P�^�R�ɂ��� */
    }

    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
}
