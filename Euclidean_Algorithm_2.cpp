// Euclidean_Algorithm_2.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *------------------------------------------
 *		ユークリッドの互除法
 *　mとnの差が大きいときは減算(m - n)の代わりに剰余(m % n)を
 * 用いた方が効率が良い。この方法でmとnの最大公約数を求める。
 *------------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a, b, m, n, k;

	printf("二つの整数を入力してください");
	scanf("%d %d", &a, &b);

	m = a;
	n = b;
	do {
		k = m % n;
		m = n;
		n = k;
	} while (k != 0);

	printf("最大公約数 = %d\n", m);

    return 0;
}

