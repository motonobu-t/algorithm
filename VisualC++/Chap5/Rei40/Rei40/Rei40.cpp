// Rei40.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------------------------
 *      ���ȍĕҐ��T���i�擪�Ɉڂ��j     *
 * ---------------------------------------
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
    char key[20];
    struct tfield *head,*p,*old;

    head=NULL;                  /* ���X�g�̍쐬 */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->pointer=head;
        head=p;
    }
                                                        /* �T�� */
    while (printf("\nKey Name ? "),scanf_s("%s",key,20)!=EOF){
        p=old=head;
        while (p!=NULL){
            if (strcmp(key,p->name)==0){
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head){
                    old->pointer=p->pointer;    /* �擪�Ɉڂ� */
                    p->pointer=head;
                    head=p;
                }
                break;
            }
            old=p;
            p=p->pointer;
        }
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


