// Dr34_2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------------------------
 *      ���X�g�f�[�^�̍쐬�i�_�~�[�E�m�[�h�j     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <malloc.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();      /* �_�~�[�E�m�[�h�̍쐬 */
    old=head;
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;

    p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	getchar();
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


