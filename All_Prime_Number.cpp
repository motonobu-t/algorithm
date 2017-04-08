// All_Prime_Number.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *----------------------------------------
 *		2〜Nの中から素数を拾い出す
 *	2〜Nまでの整数の中からすべての素数を求める
 *----------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>
#include <math.h>

#define NUM 1000

int main()
{
	int prime[NUM / 2 + 1];
	int i, n, m = 0, Limit;

	for (n = 2; n <= NUM; n++) {
		Limit = (int)sqrt((double)n);
		for (i = Limit; i > 1; i--) {
			if (n % i == 0) {
				break;
			}
		}
		if (i == 1) {
			prime[m++] = n;
		}
	}
	printf("\n求められた素数\n");
	for (i = 0; i < m; i++) {
		printf("%5d", prime[i]);
	}
	printf("\n");

    return 0;
}

