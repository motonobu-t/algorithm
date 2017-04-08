﻿// Uniform_Random_Number.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *-------------------------------
 *	一様乱数(線形合同法)
 *　線形合同法を用いて、一様乱数を発生する
 *-------------------------------
 */
#include "stdafx.h"
#include <stdio.h>

unsigned rndnum = 13;	// 乱数の初期値
unsigned irnd(void);

int main()
{
	int j;

	for (j = 0; j < 100; j++) {
		printf("%8d", irnd());
	}
	printf("\n");
    return 0;
}

unsigned irnd(void)		// 0〜32767の整数乱数
{
	rndnum = (rndnum * 109 + 1021) % 32768;
	return rndnum;
}