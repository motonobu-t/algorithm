// Euclidean_Algorithm_1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//
/*
 *---------------------------------------------
 *		���[�N���b�h�̌ݏ��@�@���̂P
 *�@�Q�̐��� m, n�̍ő���񐔂����[�N���b�h
 *�@�����[�N���b�h(Euclid)�̌ݏ��@��p���ċ��߂�
 *---------------------------------------------
 */
#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a, b, m, n;
	printf("��̐�������͂��Ă������� ");
	scanf("%d %d", &a, &b);

	m = a;
	n = b;
	while (m != n) {
		if (m > n) {
			m = m - n;
		}
		else {
			n = n - m;
		}
	}
	printf("�ő���� = %d\n", m);
    return 0;
}

