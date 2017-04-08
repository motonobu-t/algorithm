// Ranking_MinusData.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *---------------------------------------
 *		順位付け(負のデータ版)
 * ゴルフのスコア様に小さい値の方から順位が高い場合
 *---------------------------------------
*/
#include "stdafx.h"
#include <stdio.h>

#define NUM 10
#define MAX 36
#define MIN -20
#define BIAS 1-(MIN)	// 最小値を配列要素の1に対応させる

int main()
{
	int a[] = { -3, 2, 3, -1, -2, -6, 2, -1, 1, 5 };
	int i, juni[MAX + BIAS + 1];

	for (i = MIN + BIAS; i <= MAX + BIAS; i++) {
		juni[i] = 0;
	}

	for (i = 0; i < NUM; i++) {
		juni[a[i] + BIAS]++;
	}

	juni[0] = 1;
	for (i = MIN + BIAS; i <= MAX + BIAS; i++) {
		juni[i] = juni[i] + juni[i - 1];
	}

	printf("  得点   順位\n");
	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + BIAS - 1]);
	}
    return 0;
}

