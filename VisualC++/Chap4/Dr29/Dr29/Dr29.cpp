// Dr29.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ------------------------------------------
 *      �n�m�C�̓��i�������P���炷�j      *
 * ------------------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char);
#define Total 'a'+'b'+'c'

void main(void)
{
    int n;
    printf("�~�Ղ̖��� ? ");
    scanf_s("%d",&n);

    hanoi(n,'a','b');
	getchar();getchar();
}
void hanoi(int n,char a,char b)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}


