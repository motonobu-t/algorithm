// Euclidean_Algorithm_1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *---------------------------------------------
 *		ユークリッドの互除法　その１
 *　２つの整数 m, nの最大公約数をユークリッド
 *　をユークリッド(Euclid)の互除法を用いて求める
 *---------------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a, b, m, n;
	printf("二つの整数を入力してください ");
	scanf("%d %d", &a, &b);

	m = a;
	n = b;
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	printf("最大公約数 = %d\n", m);
    return 0;
}

