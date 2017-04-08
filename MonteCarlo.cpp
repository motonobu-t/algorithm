// MonteCarlo.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *-------------------------------------------
 *		�����e�J�����@�ɂ��΂̌v�Z
 *�@�����e�J�����@��p���ă΂̒l�����߂�
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
	printf("�΂̒l = %f\n", pai);

    return 0;
}

double rnd(void)
{
	return (double)rand() / (RAND_MAX + 0.1);
}

