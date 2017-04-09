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

int main(void)
{
    char dat[12];
    struct tnode *root,*p,*old;

    root=talloc();                  /* ���[�g�E�m�[�h */
    scanf("%s",root->name);
    root->left=root->right=NULL;

    while (scanf("%s",dat)!=EOF){
        p=root;                     /* �؂̃T�[�` */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* �V�����m�[�h�̐ڑ� */
        strcpy(p->name,dat);
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
    return 0;
}
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
