// Ranking.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *-------------------------------------
 *		���ʕt��
 * ���_�̏��ʂ����߂�
 *-------------------------------------
*/

#include "stdafx.h"
#include <stdio.h>

#define NUM 10

int main()
{
	int a[] = { 56, 25, 67, 88, 100, 61, 55, 67, 76, 56 };
	int juni[NUM];
	int i, j;

	for (i = 0; i < NUM; i++) {
		juni[i] = 1;
		for (j = 0; j < NUM; j++) {
			if (a[j] > a[i])
				juni[i]++;
		}
	}

	printf("   ���_�@ ����\n");
	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], juni[i]);
	}
    return 0;
}

