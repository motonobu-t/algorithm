// MonteCarlo.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *-------------------------------------------
 *		モンテカルロ法によるπの計算
 *　モンテカルロ法を用いてπの値を求める
 *-------------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

double rnd(void);

int main()
{
	double x, y, pai;
	int i, in = 0;

	for (i = 0; i < NUM; i++) {
		x = rnd();
		y = rnd();
		if (x * x + y * y <= 1) {
			in++;
		}
	}
	pai = (double)4 * in / NUM;
	printf("πの値 = %f\n", pai);

    return 0;
}

double rnd(void)
{
	return (double)rand() / (RAND_MAX + 0.1);
}

