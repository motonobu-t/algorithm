// Ranking_MinusData.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *---------------------------------------
 *		���ʕt��(���̃f�[�^��)
 * �S���t�̃X�R�A�l�ɏ������l�̕����珇�ʂ������ꍇ
 *---------------------------------------
*/
#include "stdafx.h"
#include <stdio.h>

#define NUM 10
#define MAX 36
#define MIN -20
#define BIAS 1-(MIN)	// �ŏ��l��z��v�f��1�ɑΉ�������

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

	printf("  ���_   ����\n");
	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + BIAS - 1]);
	}
    return 0;
}

