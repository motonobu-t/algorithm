// Factoring.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *--------------------------------------
 *	�f��������
 *--------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a, n;

	while (printf("Number ? "), scanf("%d", &n) != EOF) {
		a = 2;
		while (n >= a * a) {
			if (n % a == 0) {
				printf("%d*", a);
				n = n / a;
			}
			else {
				a++;
			}
		}
		printf("%d\n", n);
	}
    return 0;
}

