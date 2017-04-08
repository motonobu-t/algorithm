// Prime_number_determination.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
/*
 *--------------------------------------------------
 *		素数の判定
 *  nが素数か否か判定
 *--------------------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>
#include <math.h>

int main()
{
	int i, n, Limit;

	while (printf("data? "), scanf("%d", &n) != EOF) {
		if (n >= 2) {
			Limit = (int)sqrt((double)n);
			for (i = Limit; i > 1; i--) {
				if (n % i == 0) {
					break;
				}
			}
			if (i == 1) {
				printf("素数\n");
			}
			else {
				printf("素数でない\n");
			}
		}
	}
    return 0;
}

