// Rei29.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ------------------------------
 *      �n�m�C�̓��̍ċA��      *
 * ------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char,char);

void main(void)
{
    int n;
    printf("�~�Ղ̖��� ? ");
    scanf_s("%d",&n);

    hanoi(n,'a','b','c');
	getchar();getchar();
}
void hanoi(int n,char a,char b,char c)  /* �ċA�葱 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}


