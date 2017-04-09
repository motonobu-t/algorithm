// Dr43.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------------
 *      �ŏ��m�[�h�̒T��     *
 * ---------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void);

void main(void)
{
    char dat[12];
    struct tnode *root,*p,*old;

    root=talloc();                  /* ���[�g�E�m�[�h */
    scanf_s("%s",root->name,12);
    root->left=root->right=NULL;

    while (scanf_s("%s",dat,12)!=EOF){
        p=root;                     /* �؂̃T�[�` */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* �V�����m�[�h�̐ڑ� */
        strcpy_s(p->name,12,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
    p=root;                    /* �ŏ��m�[�h�̒T�� */
    while (p->left!=NULL)
        p=p->left;
    printf("�ŏ��m�[�h�� %s\n",p->name);

    p=root;                    /* �ő�m�[�h�̒T�� */
    while (p->right!=NULL)
        p=p->right;
    printf("�ő�m�[�h�� %s\n",p->name);
	getchar();
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}


