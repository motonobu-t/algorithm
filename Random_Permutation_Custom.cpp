// Random_Permutation_Custom.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *------------------------------------
 *		ランダムな順列(改良版)
 * アルゴリズムを改良した効率の良いアルゴリズムを考える
 *------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define N 20

int irnd(int);

int main()
{
	int i, j, d, a[N + 1];

	for (i = 1; i <= N; i++) {
		a[i] = i;
	}

	for (i = N; i > 1; i--) {
		j = irnd(i - 1);
		d = a[i];
		a[i] = a[j];
		a[j] = d;
	}

	for (i = 1; i <= N; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

    return 0;
}

int irnd(int n)		// １〜nの乱数
{
	return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}
