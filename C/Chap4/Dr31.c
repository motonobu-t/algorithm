/*
 * ---------------------------
 *      �N�C�b�N�E�\�[�g     *
 * ---------------------------
 */

#include <stdio.h>

void quick(int *,int,int);

#define N 10

void main(void)
{
    static int a[]={41,24,76,11,45,64,21,69,19,36};
    int k;

    quick(a,0,N-1);

    for (k=0;k<N;k++)
        printf("%4d",a[k]);
    printf("\n");
}
void quick(int a[],int left,int right)
{
    int s,t,i,j;
    if (left<right){
        s=a[(left+right)/2];    /* �����̒l�����ɂ��� */
        i=left-1; j=right+1;    /* ����菬�����O���[�v��       */
        while (1){              /*       �傫���O���[�v�ɕ����� */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }

        quick(a,left,i-1);        /* ��������ɑ΂���ċA�Ăяo�� */
        quick(a,j+1,right);       /* �E������ɑ΂���ċA�Ăяo�� */
    }
}
