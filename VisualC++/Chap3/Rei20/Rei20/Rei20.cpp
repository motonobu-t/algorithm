// Rei20.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------
 *      �����T���@     *
 * ---------------------
 */

#include <stdio.h>
#include <string.h>

#define N 10       /* �f�[�^���@*/

void main(void)
{
    struct girl {
        char name[20];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i;

    printf("��������data ? ");scanf_s("%s",key,20);

    i=0;
    while (i<N && strcmp(key,a[i].name)!=0)
        i++;

    if (i<N)
        printf("%s %d\n",a[i].name,a[i].age);
    else
        printf("������܂���ł���\n");
	getchar();getchar();
}


