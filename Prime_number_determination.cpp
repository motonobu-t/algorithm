// Prime_number_determination.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *--------------------------------------------------
 *		�f���̔���
 *  n���f�����ۂ�����
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
				printf("�f��\n");
			}
			else {
				printf("�f���łȂ�\n");
			}
		}
	}
    return 0;
}

