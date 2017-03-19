// 1-1-2_Horner.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
*----------------------------------------
*		Hornerの方法
* 多項式の値をHornaerの方法を用いて計算する
*----------------------------------------
*/
#include "stdafx.h"
#include <stdio.h>

double fn(double, double *, int);

int main()
{
	double a[] = { 1, 2, 3, 4, 5 };	/* 係数 */
	double x;

	for (x = 1; x <= 5; x++) {
		printf("fn(%f) = %f\n", x, fn(x, a, 4));
	}
    return 0;
}

double fn(double x, double a[], int n)
{
	double p;
	int i;

	p = a[n];
	for (i = n - 1; i >= 0; i--) {
		p = p * x + a[i];
	}
	return p;
}

