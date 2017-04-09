// Dr4.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ------------------------------------
 *      ランダムな順列（改良版）      *
 * ------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

void main(void)
{
    int i,j,d,a[N+1];

    for (i=1;i<=N;i++)
        a[i]=i;

    for (i=N;i>1;i--){
        j=irnd(i-1);
        d=a[i];a[i]=a[j];a[j]=d;
    }

    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
	printf("\n");
	getchar();
}
int irnd(int n)        /* １〜ｎの乱数 */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}

