// dr8_1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ----------------------
 *     ��l���̌���@   *
 * ----------------------
 */

#include <stdio.h>

#define N 1000             /* �����̔����� */
#define M 10               /* ���������͈̔� */
#define F (N/M)            /* ���Ғl */
#define SCALE (40.0/F)     /* �q�X�g�O�����̍����i�����X�P�[���j */

unsigned rndnum=13;        /* �����̏����l */

unsigned irnd(void);
double rnd(void);

void main(void)
{
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1�`M�̗������P���� */
        hist[rank]++;
    }

    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* �q�X�g�O�����̕\�� */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /* ��2�̌v�Z */
    }
    printf("��2=%f\n",e);
	getchar();
}
unsigned irnd(void)        /* 0�`32767�̐������� */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0�`1�����̎������� */
{
    return irnd()/32767.1;
}