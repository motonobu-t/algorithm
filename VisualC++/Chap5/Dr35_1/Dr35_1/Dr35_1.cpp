// Dr35_1.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------------------
 *      ���X�g�f�[�^�ւ̒ǉ�     *
 * -------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head;

struct tfield *talloc(void);
void genlist(void);
void displist(void);
void link(char *);

void main(void)
{
    char key[32];

    genlist();
    displist();

    while (printf("Key Name "),scanf_s("%s",key,32)!=EOF){
        link(key);
    }

    displist();
	getchar();
}
void link(char *key)         /* ���X�g�ւ̒ǉ� */
{
    struct tfield *p,*n;

    n=talloc();
    printf("�ǉ��f�[�^ ");
    scanf_s("%s %s",n->name,20,n->tel,20);

    p=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            n->pointer=p->pointer;
            p->pointer=n;
            return;
        }
        p=p->pointer;
    }
    printf("%s ��������Ȃ��̂Ő擪�ɒǉ����܂�\n",key);
    n->pointer=head;
    head=n;
}
void genlist(void)           /* ���X�g�̍쐬 */
{
    struct tfield *p;

    head=NULL;
    while (p=talloc(),scanf_s("%s %s",p->name,20,p->tel,20)!=EOF){
        p->pointer=head;
        head=p;
    }
}
void displist(void)           /* ���X�g�̕\�� */
{
    struct tfield *p;
    p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}


