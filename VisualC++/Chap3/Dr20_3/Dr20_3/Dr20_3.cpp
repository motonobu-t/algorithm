// Dr20_3.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------
 *      ��{�}���@     *
 * ---------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100   /* �f�[�^�� */

void main(void)
{
    int a[N+1],i,j,t;

    for(i=1;i<=N;i++)        /* �m�̗��� */
        a[i]=rand();

    a[0]=-9999;              /* �ԕ� */
    for (i=2;i<=N;i++){
        t=a[i];
        for (j=i-1;a[j]>t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }

    for (i=1;i<=N;i++)
        printf("%8d",a[i]);
	getchar();
}

