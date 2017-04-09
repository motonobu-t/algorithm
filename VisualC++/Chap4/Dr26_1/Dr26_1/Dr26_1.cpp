// Dr26_1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


/*
 * ------------------------------------
 *      フィボナッチ数（再帰版）      *
 * ------------------------------------
 */

#include <stdio.h>

long fib(long);

void main(void)
{
    long n;
    for (n=1;n<=20;n++)
        printf("%3ld: %ld\n",n,fib(n));
	getchar();
}
long fib(long n)
{
    if (n==1 || n==2)
        return 1L;
    else
        return fib(n-1)+fib(n-2);
}

