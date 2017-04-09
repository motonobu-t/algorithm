// Rei6.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ---------------------------------
 *      ユークリッドの互除法       *
 * ---------------------------------
 */

#include <stdio.h>

void main(void)
{
    int a,b,m,n;

    printf("二つの整数を入力してください ");
    scanf_s("%d %d",&a,&b);

    m=a; n=b;
    while (m!=n){
        if (m>n)
            m=m-n;
        else
            n=n-m;
    }
    printf("最大公約数=%d\n",m);
	getchar();getchar();
}

