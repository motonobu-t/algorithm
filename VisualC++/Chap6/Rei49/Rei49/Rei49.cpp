// Rei49.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * -----------------
 *      ���̖�     *
 * -----------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char ope;               /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void prefix(struct tnode *);
void infix(struct tnode *);
void postfix(struct tnode *);

void main(void)
{
    struct tnode *root;
	char expression[]="ab*cd+e/-";
    root=NULL;
    root=gentree(root,expression);

    printf("\nprefix  = ");prefix(root);        /* ���̖؂̑��� */
    printf("\ninfix   = ");infix(root);
    printf("\npostfix = ");postfix(root);
	printf("\n");
	getchar();
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* ������̏I�[���m�[�h�ɂ��� */
    w[n-1]='\0';           /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void prefix(struct tnode *p)     /* �ړ��` */
{
    if (p!=NULL){
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}
void infix(struct tnode *p)      /* �}���` */
{
    if (p!=NULL){
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}
void postfix(struct tnode *p)    /* �ڔ��` */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}
struct tnode *talloc(void)       /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

