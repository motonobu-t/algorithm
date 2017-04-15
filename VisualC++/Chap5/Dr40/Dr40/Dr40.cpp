// Dr40.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------------------------------
 *      ���ȍĕҐ��T���i�P�O�Ɉڂ��j     *
 * -----------------------------------------
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
    struct tfield *head,*p,*old1,*old2,*q;

    head=NULL;                /* ���X�g�̍쐬 */
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->pointer=head;
        head=p;
    }
    p=talloc();               /* �_�~�[�E�m�[�h */
    p->pointer=head;
    head=p;
                                                       /* �T�� */
    while (printf("\nKey Name ? "),scanf_s("%s",key,20)!=EOF){
        p=head->pointer;
        old1=old2=head;
        while (p!=NULL){
            if (strcmp(key,p->name)==0){
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head->pointer){       /* �擪�łȂ��Ƃ��� */
                    q=old1->pointer;         /* �P�O�ƌ���     */
                    old1->pointer=p;
                    old2->pointer=p->pointer;
                    p->pointer=q;
                }
                break;
            }
            old1=old2;
            old2=p;
            p=p->pointer;
        }
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

