// Dr26_5.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ------------------------------------------
 *      ���[�N���b�h�̌ݏ��@�i�ċA�Łj      *
 * ------------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

void main(void)
{
    int a,b;

    printf("�Q�̐�������͂��Ă�������");
    scanf_s("%d %d",&a,&b);

    printf("�ő����=%d\n",gcd(a,b));
	getchar();getchar();
}
int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}


