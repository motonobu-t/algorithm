// Rei6.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------------------
 *      ���[�N���b�h�̌ݏ��@       *
 * ---------------------------------
 */

#include <stdio.h>

void main(void)
{
    int a,b,m,n;

    printf("��̐�������͂��Ă������� ");
    scanf_s("%d %d",&a,&b);

    m=a; n=b;
    while (m!=n){
        if (m>n)
            m=m-n;
        else
            n=n-m;
    }
    printf("�ő����=%d\n",m);
	getchar();getchar();
}

