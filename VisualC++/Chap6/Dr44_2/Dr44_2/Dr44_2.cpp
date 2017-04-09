// Dr44_2.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -------------------------------------
 *      �Q���T���؂̍쐬�i�ċA�Łj     *
 * -------------------------------------
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
void gentree(struct tnode **,char *);

void main(void)
{
    char dat[12];
    struct tnode *root,*p;

    root=NULL;
    while (scanf_s("%s",dat,12)!=EOF){
        gentree(&root,dat);
    }
    p=root;
    while (p!=NULL){
        printf("%s\n",p->name);
        p=p->left;
    }
	getchar();
}
void gentree(struct tnode **p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{                                       /* �Q�Ƃɂ��ďo��     */
    if ((*p)==NULL){
        (*p)=talloc();
        strcpy_s((*p)->name,12,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

