// Dr48_1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------------
 *      �q�[�v�E�\�[�g     *
 * -------------------------
 */

#include <stdio.h>

void swap(int *,int *);
void shiftdown(int,int,int *);

void main(void)
{
    int heap[100];
    int i,n,m;

    n=1;                        /* �f�[�^��؂Ɋ��蓖�Ă� */
    while (scanf_s("%d",&heap[n])!=EOF)
        n++;
    m=n-1;                        /* ���̕ۑ� */
    for (i=m/2;i>=1;i--)        /* �����q�[�v�̍쐬 */
        shiftdown(i,m,heap);
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* �؂̏I�[��؂藣�� */
        shiftdown(1,m,heap);
    }
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
	printf("\n");
	getchar();
}
void shiftdown(int p,int n,int heap[])   /* �����ړ� */
{
    int s;
    s=2*p;
    while (s<=n){
        if( s<n && heap[s+1]<heap[s])    /* ���ƉE�̎q�̏������� */
            s++;
        if (heap[p]<=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
    }
}
void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

