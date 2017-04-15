// Rei37.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------------
 *      �o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------
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
    struct tfield *head,*tail,*p;

    tail=NULL;              /* �t���X�g�̍쐬 */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->left=tail;
        tail=p;
    }

    p=tail;                 /* �����X�g�̍쐬 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

    printf("\n���������X�g\n");
    p=head;                 /* ���X�g�̏��\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("\n�t�������X�g\n");
    p=tail;                 /* ���X�g�̋t�\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	getchar();
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

