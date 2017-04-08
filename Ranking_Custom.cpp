// Ranking_Custom.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *------------------------------------
 *		���ʕt��(���ǔ�)
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
	
	// ������
	for (i = MIN; i <= MAX; i++) {
		juni[i] = 0;
	}

	for (i = 0; i < NUM; i++) {
		juni[a[i]]++;		// �e���_�ɑΉ�����Y���̔z���+1����
	}

	juni[MAX + 1] = 1;
	for (i = MAX; i >= MIN; i--) {
		juni[i] = juni[i] + juni[i + 1];
	}

	printf("  ���_  ����\n");
	for (i = 0; i < NUM; i++) {
		printf("%6d%6d\n", a[i], juni[a[i] + 1]);
	}
    return 0;
}

