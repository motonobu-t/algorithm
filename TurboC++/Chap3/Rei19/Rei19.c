/*
 * ---------------------
 *      ��{�}���@     *
 * ---------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100     /* �f�[�^�� */

void main(void)
{
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* �m�̗��� */
        a[i]=rand();

    for (i=1;i<N;i++){
        for (j=i-1;j>=0;j--){
            if (a[j]>a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
            else
                break;
        }
    }

    for (i=0;i<N;i++)
        printf("%8d",a[i]);
	printf("\n");
	getchar();
}

