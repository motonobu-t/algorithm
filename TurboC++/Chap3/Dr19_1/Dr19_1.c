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
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* �m�̗��� */
        a[i]=rand();

    gap=N/2;                /* �M���b�v�̏����l */
    while (gap>0){
        for (k=0;k<gap;k++){    /* �M���v�Ƃт̕�������̃\�[�g */
            for (i=k+gap;i<N;i=i+gap){
                for (j=i-gap;j>=k;j=j-gap){
                    if (a[j]>a[j+gap]){
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             /* �M���b�v�𔼕��ɂ��� */
    }

    for (i=0;i<N;i++)
        printf("%8d",a[i]);
	printf("\n");
	getchar();
}

