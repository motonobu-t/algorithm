// Ranking_Custom.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *------------------------------------
 *		順位付け(改良版)
 *------------------------------------
*/
#include "stdafx.h"
#include <stdio.h>

#define NUM 10
#define MAX 100
#define MIN 0

int main()
{
	int a[] = { 56, 25, 67, 88, 100, 61, 55, 67, 76, 56 };
	int i, juni[MAX + 2];
	
	// 初期化
	for (i = MIN; i <= MAX; i++) {
		juni[i] = 0;
	}

	for (i = 0; i < NUM; i++) {
		juni[a[i]]++;		// 各得点に対応する添字の配列に+1する
	}

	juni[MAX + 1] = 1;
	for (i = MAX; i >= MIN; i--) {
		juni[i] = juni[i] + juni[i + 1];
	}

	printf("  得点  順位\n");
	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + 1]);
	}
    return 0;
}

