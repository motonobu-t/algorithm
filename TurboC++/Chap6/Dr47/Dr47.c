/*
 * -----------------------------------
 *      �q�[�v�̍쐬�i�����ړ��j     *
 * -----------------------------------
 */

#include <stdio.h>

void swap(int *,int *);

void main(void)
{
    int heap[100];
	int i,n,p,s,m;

    n=1;                     /* �f�[�^��؂Ɋ��蓖�Ă� */
    while (scanf("%d",&heap[n])!=EOF)
        n++;
	m=n-1;                     /* �f�[�^�� */
	for (i=m/2;i>=1;i--){
        p=i;                 /* �e�̈ʒu */
        s=2*p;               /* ���̎q�̈ʒu */
		while (s<=m){
			if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̎q�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }
    for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
	printf("\n");
	getchar();
}
void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

