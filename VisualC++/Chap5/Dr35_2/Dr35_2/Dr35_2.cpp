// Dr35_2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------
 *      ���X�g�f�[�^�̒T��     *
 * -----------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p,
                  sentinel;        /* �ԕ� */
    char key[20];

    head=&sentinel;                /* �ԕ��ւ̃|�C���^�[ */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->pointer=head;
        head=p;
    }

    rewind(stdin);                      /* �T�� */
    while (printf("\nkey name "),scanf_s("%s",key,20)!=EOF){
        strcpy_s(sentinel.name,20,key);      /* �ԕ��ɃL�[������ */
        p=head;
        while (strcmp(p->name,key)!=0)
            p=p->pointer;
        if (p!=&sentinel)
            printf("%s %s\n",p->name,p->tel);
        else
            printf("������܂���\n");
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}



