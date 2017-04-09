// Dr37.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------------------
 *      �z�E�o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    struct tfield *left;    /* �t�|�C���^ */
    char name[20];          /* ���O       */
    char tel[20];           /* �d�b�ԍ�   */
    struct tfield *right;   /* ���|�C���^ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p;

    head=talloc();                  /* �_�~�[�E�m�[�h�̍쐬 */
    head->left=head->right=head;

    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->right=head;
        p->left=head->left;
        head->left->right=p;
        head->left=p;
    }

    printf("\n���������X�g\n");
    p=head->right;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("\n�t�������X�g\n");
    p=head->left;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	getchar();
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


