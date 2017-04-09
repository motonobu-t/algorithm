// Dr49.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


/*
 * ---------------------------------
 *      ���̖؂�p�������̌v�Z     *
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    int ope;                /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void postfix(struct tnode *);

void main(void)
{
    struct tnode *root;
	char expression[]="53*64+2/-";
    root=NULL;
    root=gentree(root,expression);

    postfix(root);         /* ���̌v�Z */
    printf("value=%d\n",root->ope);
	getchar();
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* ������̏I�[���m�[�h�ɂ��� */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* �萔�̂Ƃ��͐��l�ɕϊ� */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    /* ���̖؂̌v�Z */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}


