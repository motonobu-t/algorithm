// Rei32.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------
 *      �X�^�b�N     *
 * -------------------
 */

#include <stdio.h>

#define MaxSize 100     /* �X�^�b�N�E�T�C�Y */
int stack[MaxSize];     /* �X�^�b�N */
int sp=0;               /* �X�^�b�N�E�|�C���^ */
int push(int);
int pop(int*);

void main(void)
{
    int c,n;

    while (printf("]"),(c=getchar())!=EOF){
        rewind(stdin);
        if (c=='i' || c=='I'){
            printf("data--> ");
            scanf_s("%d",&n);rewind(stdin);
            if (push(n)==-1){
                printf("�X�^�b�N����t�ł�\n");
            }
        }
        if (c=='o' || c=='O'){
            if (pop(&n)==-1)
                printf("�X�^�b�N�͋�ł�\n");
            else
                printf("stack data --> %d\n",n);
        }
    }
}
int push(int n)        /* �X�^�b�N�Ƀf�[�^��ςގ葱�� */
{
    if (sp<MaxSize){
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����t�̂Ƃ� */
}
int pop(int *n)        /* �X�^�b�N����f�[�^�����o���葱�� */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����̂Ƃ� */
}


