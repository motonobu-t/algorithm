// Rei47.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------
 *      �q�[�v�̍쐬     *
 * -----------------------
 */

#include <stdio.h>

void main(void)
{
    int heap[100];
    int n,i,s,p,w;

    n=1;
    while (scanf_s("%d",&heap[n])!=EOF){      /* �q�[�v�̍Ō�̗v�f�ɓ���� */
        s=n;
        p=s/2;          /* �e�̈ʒu */
        while (s>=2 && heap[p]>heap[s]){    /* ����ړ� */
            w=heap[p];heap[p]=heap[s];heap[s]=w;
            s=p;p=s/2;
        }
        n++;
     }
     for (i=1;i<n;i++)
        printf("%d ",heap[i]);
	 printf("\n");
	 getchar();
}

