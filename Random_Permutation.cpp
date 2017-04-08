﻿// Random_Permutation.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

/*
 *------------------------------------
 *	ランダムな順列(効率の悪い方法)
 * 1〜Nの値を1回使ってできるランダムな順列を作る
 *------------------------------------
 */

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

int main()
{
	int i, j, flag, a[N + 1];
	for (i = 1; i <= N; i++) {
		do {
			a[i] = irnd(N);
			flag = 0;
			for (j = 1; j < i; j++) {
				if (a[i] == a[j]) {
					flag = 1;
					break;
				}
			}
		} while (flag == 1);
	}
	for (i = 1; i <= N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

    return 0;
}

int irnd(int n)
{
	return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}

